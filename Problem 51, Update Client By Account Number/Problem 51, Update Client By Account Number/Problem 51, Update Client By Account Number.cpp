#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient {
    string AccountNumer;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelet = false;
};

vector <string> SplitString(string Line, string Delim)
{
    vector <string> vClientsData;
    short pos;
    string sWord;

    while ((pos = Line.find(Delim)) != string::npos)
    {
        sWord = Line.substr(0, pos);

        if (sWord != "")
            vClientsData.push_back(sWord);

        Line.erase(0, pos + Delim.length());
    }
    if (Line != "")
        vClientsData.push_back(Line);

    return vClientsData;
}

sClient ConvertRecodToClient(string Line, string Separator = "#||#")
{
    sClient Client;
    vector <string> vClientsData = SplitString(Line, Separator);
    Client.AccountNumer = vClientsData[0];
    Client.PinCode = vClientsData[1];
    Client.Name = vClientsData[2];
    Client.Phone = vClientsData[3];
    Client.AccountBalance = stod(vClientsData[4]);
    return Client;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    sClient Client;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    string Line = "";
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            Client = ConvertRecodToClient(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

string ReadAcountNumber()
{
    cout << "Please enter account number : ";
    string AccNum;
    cin >> AccNum;
    return AccNum;
}

bool FindClientByAccountNumber(sClient& Client, vector <sClient>& vClients, string AccountNumber, short &vClientNum)
{
    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].AccountNumer == AccountNumber)
        {
            vClientNum = i;
            Client = vClients[i];
            return true;
        }
    }
    return false;
}

void UpdateClient(sClient &Client)
{   
    cout << "\nenter pin code : ";
    getline(cin >> ws, Client.PinCode);

    cout << "enter name : ";
    getline(cin, Client.Name);

    cout << "enter Phone : ";
    getline(cin, Client.Phone);

    cout << "enter Account Balance : ";
    string AccBal;
    getline(cin, AccBal);
    Client.AccountBalance = stod(AccBal);
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details";
    cout << "\nAccount Numer   : " << Client.AccountNumer;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << to_string(Client.AccountBalance);
}

string ConvertRecordToLine(sClient Client, string Separator = "#||#")
{
    string Line = Client.AccountNumer + Separator;
    Line += Client.PinCode + Separator;
    Line += Client.Name + Separator;
    Line += Client.Phone + Separator;
    Line += to_string(Client.AccountBalance);
    return Line;
}

void SaveClientsDataToFile(vector <sClient>& vClients)
{
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out);
    string Line;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (!C.MarkForDelet)
            {
                Line = ConvertRecordToLine(C);
                MyFile << Line << endl;
            }
        }
    }
}

void UpdateClientByAccountNumber(vector <sClient> &vClients, string AccountNumber)
{
    sClient Client;
    char Anser = 'n';
    short vClientNum = 0;
    if (FindClientByAccountNumber(Client, vClients, AccountNumber, vClientNum))
    {
        PrintClientCard(Client);
        cout << "\n\n\nAre you want to update the client details (y/n) : ";
        cin >> Anser;        
        if (tolower(Anser) == 'y')
        {
            UpdateClient(vClients[vClientNum]);
            SaveClientsDataToFile(vClients);
            cout << "\nClient Updated Successfully.\n";
        }        
    }
    else    
        cout << "\nCleint with Account Number (" << AccountNumber << ") Not Found!\n";
    
}

int main()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    string AccountNumber = ReadAcountNumber();

    UpdateClientByAccountNumber(vClients, AccountNumber);

    system("pause>0");
}