#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelet = false;
};

vector <string> SplitStrig(string Line, string Delim)
{
    vector <string> vData;
    string sWord;
    short pos;

    while ((pos = Line.find(Delim)) != string::npos)
    {
        sWord = Line.substr(0, pos);

        if (sWord != "")        
            vData.push_back(sWord);
        
        Line.erase(0, pos + Delim.length());
    }
    if(Line != "")
        vData.push_back(Line);

    return vData;
}

sClient ConvertLineToRecord(string Line, string Separator = "#||#")
{
    sClient Client;
    vector <string> vStr = SplitStrig(Line, Separator);

    Client.AccountNumber = vStr[0];
    Client.PinCode = vStr[1];
    Client.Name = vStr[2];
    Client.Phone = vStr[3];
    Client.AccountBalance = stod(vStr[4]);
    return Client;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    string Line;
    sClient Client;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
    }
    return vClients;
}

bool FindClientByAccountNumer(vector <sClient>& vClients, string AccountNumber, sClient &Client)
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

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client delails:\n";
    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << to_string(Client.AccountBalance);
}

void MarkClientForDeletByAccountNumber(vector <sClient>& vClients, string AccountNumber)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelet = true;
            return;
        }
    }
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

void SaveClientDataToFile(vector <sClient>& vClients)
{
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out);
    for (sClient &C : vClients)
    {
        if (!C.MarkForDelet)
            MyFile << ConvertRecordToLine(C) << endl;
    }
    MyFile.close();
}

void DeletClientsByAccountNumber(vector <sClient> &vClients, string AccountNumber)
{
    sClient Client;
    char Answr = 'n';
    if (FindClientByAccountNumer(vClients, AccountNumber, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nare you sure you want to delet this cient (y/n) : ";
        cin >> Answr;
        if (Answr == 'y' || Answr == 'Y')
        {
            MarkClientForDeletByAccountNumber(vClients, AccountNumber);
            SaveClientDataToFile(vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\n\nClient Delet Successfully.\n";
        }
    }
}

string ReadAccountNumber()
{
    string accNum;
    cout << "Please enter the account number : ";
    cin >> accNum;
    return accNum;
}

int main()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    string AccountNumber = ReadAccountNumber();

    DeletClientsByAccountNumber(vClients, AccountNumber);

    system("pause>0");
}