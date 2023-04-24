#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector <string> SplitString(string Text, string Delim)
{
    vector <string> vStr;
    short pos;
    string sWord;
    while ((pos = Text.find(Delim)) != string::npos) 
    {
        sWord = Text.substr(0, pos);
        if (sWord != "")
            vStr.push_back(sWord);

        Text.erase(0, pos + Delim.length());
    }

    if (Text != "")
        vStr.push_back(Text);
    return vStr;
}

sClient ConvertLineToRecord(string clientData, string Separator = "#||#")
{
    vector <string> vStr = SplitString(clientData, Separator);
    sClient Client;
    
    Client.AccountNumber = vStr[0];
    Client.PinCode = vStr[1];
    Client.Name = vStr[2];
    Client.Phone = vStr[3];
    Client.AccountBalance = stod(vStr[4]);

    return Client;
}

vector <sClient> LoadDataRecordFromFile(string FileName)
{
    fstream MyFile;
    vector <sClient> Clients;
    MyFile.open(FileName, ios::in);
    string Line;
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))        
            Clients.push_back(ConvertLineToRecord(Line));

        MyFile.close();
    }
    return Clients;
}

bool FindClientByAccountNumber(string AccountNumber, sClient &Client, vector <sClient> & vClients)
{    
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

string ReadAccountNumber()
{
    cout << "Please enter the account number : ";
    string AccNum = "";
    cin >> AccNum;
    return AccNum;
}

void PrintClientCard(sClient Client)
{
    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;
}

bool DeletClient()
{
    char DeletClient;
    cout << "\n\nAre you sure you want to delet this client (y/n): ";
    cin >> DeletClient;

    return toupper(DeletClient) == 'Y';
}

string ConvertRecordToLine(sClient Client, string Separator = "#||#")
{
    string Line = Client.AccountNumber + Separator;
    Line += Client.PinCode + Separator;
    Line += Client.Name + Separator;
    Line += Client.Phone + Separator;
    Line += to_string(Client.AccountBalance);
    return Line;
}

void SaveRecordToFile(sClient Client)
{
    string Line = ConvertRecordToLine(Client);
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out | ios::app);
    MyFile << Line << endl;
    MyFile.close();
}

void DeletClientByAccountNumber(vector <sClient> &vClients)
{
    string AccountNumber = ReadAccountNumber();
    sClient Client;
    

    if (FindClientByAccountNumber(AccountNumber, Client, vClients))
    {
        PrintClientCard(Client);

        if (DeletClient())
        {
            fstream MyFile;
            MyFile.open(ClientsFileName, ios::out);
            MyFile.close();

            for (int i = 0; i < vClients.size(); i++)
            {
                if (AccountNumber != vClients[i].AccountNumber)
                    SaveRecordToFile(vClients[i]);
            }
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else
        cout << "\nAccount number (" << AccountNumber << ") is Not faound\n";
}

int main()
{
    vector <sClient> vClients = LoadDataRecordFromFile(ClientsFileName);

    DeletClientByAccountNumber(vClients);

    system("pause>0");
}