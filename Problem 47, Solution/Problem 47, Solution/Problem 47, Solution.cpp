#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient()
{
    cout << "Adding New Client :\n\n";

    sClient Client;
    
    cout << "Enter Account Number : ";
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter Pin Code : ";
    getline(cin, Client.PinCode);

    cout << "Enter Name : ";
    getline(cin, Client.Name);

    cout << "Enter Phone : ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance : ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClient Client, string Separator = "#||#")
{
    string Record = Client.AccountNumber + Separator;
    Record += Client.PinCode + Separator;
    Record += Client.Name + Separator;
    Record += Client.Phone + Separator;
    Record += to_string(Client.AccountBalance);

    return Record;
}

void SaveLineToFile(string FileName, string Record)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << Record << endl;
        MyFile.close();
    }    
}

void AddClient()
{
    sClient Client = ReadNewClient();
    SaveLineToFile("Clients.txt", ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        AddClient();
        cout << "\nClient Added Successfuly, do you want to add more : ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();

    system("pause>0");
}