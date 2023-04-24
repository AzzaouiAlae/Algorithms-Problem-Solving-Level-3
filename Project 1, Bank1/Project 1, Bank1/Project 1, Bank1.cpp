#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalcance;
    bool MarkForDelet = false;
};

void ResetScreen()
{
    system("cls");
}

enum enMainMenueClients{ClientsList = 1, NewClient = 2, DeletClient = 3, UpdateClient = 4, FindClient = 5, Exit};
 
vector <string> SplitString(string Line, string Separator)
{
    vector <string> vClientData;
    short pos;
    string sWord;
    while ((pos = Line.find(Separator)) != string::npos)
    {
        sWord = Line.substr(0, pos);
        if (sWord != "")
            vClientData.push_back(sWord);

        Line = Line.erase(0, pos + Separator.length());
    }
    if(Line != "")
        vClientData.push_back(Line);
    return vClientData;
}

sClient ConvertLineToRecord(string Line, string Separator = "#||#")
{
    vector <string> vClientData = SplitString(Line, Separator);
    sClient Client;
    if (vClientData.size() >= 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalcance = stod(vClientData[4]);        
    }
    return Client;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    sClient Client;
    fstream MyFile;
    string Line = "";
    MyFile.open(FileName, ios::in);    
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void ShowClientsList(vector <sClient> &vClients)
{
    ResetScreen();
    cout << "=============================================================================================================\n";
    cout << "\t\t\t\t\tClients List Screen\n";
    cout << "=============================================================================================================\n";
    cout << left << "| " << setw(15) << "Account Number ";
    cout << left << "| " << setw(15) << "Pin Code ";
    cout << left << "| " << setw(35) << "Name ";
    cout << left << "| " << setw(15) << "Phone ";
    cout << left << "| " << setw(15) << "Account Balcance \n";
    cout << "=============================================================================================================\n";

    for (int i = 0; i < vClients.size(); i++)
    {
        cout << left << "| " << setw(15) << vClients[i].AccountNumber;
        cout << left << "| " << setw(15) << vClients[i].PinCode;
        cout << left << "| " << setw(35) << vClients[i].Name;
        cout << left << "| " << setw(15) << vClients[i].Phone;
        cout << left << "| " << setw(15) << vClients[i].AccountBalcance << "\n";
    }   
    cout << "\n\n\nPresse a Key to return to main menu...";
    system("pause>0");
}

void MenueScreen()
{
    ResetScreen();
    cout << "=================================\n";
    cout << "      Main Menue Screen\n";
    cout << "=================================\n";
    cout << "\t [1] Show Clients Liste.\n";
    cout << "\t [2] Add New Client.\n";
    cout << "\t [3] Delet Client.\n";
    cout << "\t [4] Update Client.\n";
    cout << "\t [5] Find Client.\n";
    cout << "\t [6] Exit.\n";
    cout << "=================================\n";
    cout << "Choose Number from 1 to 6 : ";
}

enMainMenueClients ReadClientChoose()
{
    short shoose;
    cin >> shoose;
    return enMainMenueClients(shoose);
}

string ConvertRecordToLine(sClient Client, string Separator = "#||#")
{
    string Line = Client.AccountNumber + Separator;
    Line += Client.PinCode + Separator;
    Line += Client.Name + Separator;
    Line += Client.Phone + Separator;
    Line += to_string(Client.AccountBalcance);

    return Line;
}

void SaveClientsDataToFile(vector <sClient>& vClients)
{    
    string Line;
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out);
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
        MyFile.close();
    }   
}

void SaveNewClientDataToFile(sClient Client)
{
    string Line;
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        if (!Client.MarkForDelet)
        {
            Line = ConvertRecordToLine(Client);
            MyFile << Line << endl;
        }
        MyFile.close();
    }
}

sClient AddNewClient()
{
    sClient Client;

    cout << "Enter Account Number  : ";
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter Pin Code        : ";
    getline(cin, Client.PinCode);

    cout << "Enter Name            : ";
    getline(cin, Client.Name);

    cout << "Enter Phone           : ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance : ";
    cin >> Client.AccountBalcance;

    return Client;
}

void AddNewClients(vector <sClient> &vClients)
{    
    char Answer = 'y';

    while (Answer == 'y' || Answer == 'Y')
    {
        ResetScreen();
        sClient Client;
        cout << "=================================\n";
        cout << "    Add New Client Screen\n";
        cout << "=================================\n";
        Client = AddNewClient();
        vClients.push_back(Client);
        SaveNewClientDataToFile(Client);
        cout << "are you want to add more clients (y/n) : ";
        cin >> Answer;
    }    

    cout << "\n\n\nPresse a Key to return to main menu...";
    system("pause>0");
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are client details : ";
    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPin Code         : " << Client.PinCode;
    cout << "\nName             : " << Client.Name;
    cout << "\nPhone            : " << Client.Phone;
    cout << "\nAccount Balcance : " << Client.AccountBalcance;
}

bool FindClientsByAccountNumber(vector <sClient>& vClients, string AccNum, short & NumberAccInVec)
{
    for (short i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].AccountNumber == AccNum)
        {
            NumberAccInVec = i;
            return true;
        }
    }
    return false;
}

void DeletClientsByAccountNumber(vector <sClient> & vClients)
{
    char Answer = 'y';
    string AccNum;
    short NumberAccInVec; // number Account in vector

    while (Answer == 'y' || Answer == 'Y')
    {
        ResetScreen();
        sClient Client;
        cout << "=================================\n";
        cout << "      Delet Client Screen\n";
        cout << "=================================\n";
        cout << "Please enter the account number : ";
        cin >> AccNum;
        if (FindClientsByAccountNumber(vClients, AccNum, NumberAccInVec))
        {
            PrintClientCard(vClients[NumberAccInVec]);
            cout << "\n\nAre you sure you want to delet this Client (y/n) : ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                vClients[NumberAccInVec].MarkForDelet = true;
                SaveClientsDataToFile(vClients);
                vClients = LoadClientsDataFromFile(ClientsFileName);
            }
        }
        else
        {
            cout << "Account Number (" << AccNum << ") not found!\n";
        }
        cout << "Are you want to delet more clients (y/n) : ";
        cin >> Answer;
    }

    cout << "\n\n\nPresse a Key to return to main menu...";
    system("pause>0");
}

void ReadUpdateClient(sClient &vClients)
{
    cout << "Enter Pin Code : ";
    getline(cin >> ws, vClients.PinCode);

    cout << "Enter Name : ";
    getline(cin, vClients.Name);

    cout << "Enter Phone : ";
    getline(cin, vClients.Phone);

    cout << "Enter Phone : ";
    cin >> vClients.AccountBalcance;
}

void UpdateClientsByAccountNumber(vector <sClient>& vClients)
{
    char Answer = 'y';
    string AccNum;
    short NumberAccInVec; // number Account in vector

    while (Answer == 'y' || Answer == 'Y')
    {
        ResetScreen();
        sClient Client;
        cout << "=================================\n";
        cout << "       Update Client Screen\n";
        cout << "=================================\n";
        cout << "Please enter the account number : ";
        cin >> AccNum;
        if (FindClientsByAccountNumber(vClients, AccNum, NumberAccInVec))
        {
            PrintClientCard(vClients[NumberAccInVec]);
            cout << "\n\nAre you sure you want to update this Client (y/n) : ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {                
                ReadUpdateClient(vClients[NumberAccInVec]);
                SaveClientsDataToFile(vClients);
                vClients = LoadClientsDataFromFile(ClientsFileName);
            }
        }
        else
        {
            cout << "Account Number (" << AccNum << ") not found!\n";
        }
        cout << "\n\nAre you want to Update more clients (y/n) : ";
        cin >> Answer;
    }

    cout << "\n\n\nPresse a Key to return to main menu...";
    system("pause>0");
}

void FindAndPrintClients(vector <sClient>& vClients)
{
    char Answer = 'y';
    string AccNum;
    short NumberAccInVec; // number Account in vector

    while (Answer == 'y' || Answer == 'Y')
    {
        ResetScreen();
        sClient Client;
        cout << "=================================\n";
        cout << "       Find Clients Screen\n";
        cout << "=================================\n";
        cout << "Please enter the account number : ";
        cin >> AccNum;
        if (FindClientsByAccountNumber(vClients, AccNum, NumberAccInVec))
        {
            PrintClientCard(vClients[NumberAccInVec]);
        }
        else
        {
            cout << "Account Number (" << AccNum << ") not found!\n";
        }
        cout << "\n\nAre you want to Find more clients (y/n) : ";
        cin >> Answer;
    }

    cout << "\n\n\nPresse a Key to return to main menu...";
    system("pause>0");
}

void StartBankApp()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    enMainMenueClients Answer;
    while (true)
    {
        MenueScreen();
        Answer = ReadClientChoose();
        switch (Answer)
        {
        case  ClientsList: ShowClientsList(vClients); break;
        case  NewClient: AddNewClients(vClients); break;
        case  DeletClient: DeletClientsByAccountNumber(vClients); break;
        case  UpdateClient: UpdateClientsByAccountNumber(vClients); break;
        case  FindClient: FindAndPrintClients(vClients); break;
        case  Exit: return;
        default: break;
        }
    }
}

int main()
{
    StartBankApp();
    
}