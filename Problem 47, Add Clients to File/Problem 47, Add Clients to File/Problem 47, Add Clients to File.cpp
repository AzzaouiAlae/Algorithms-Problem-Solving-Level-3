#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct sClient 
{
    string AccountNumber;
    string CodPine;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient()
{
    sClient Client;

    cout << "Adding New Client\n\n";

    cout << "Eneter Account Number : ";
    getline(cin, Client.AccountNumber);
    
    cout << "Eneter Cod Pine : ";
    getline(cin, Client.CodPine);

    cout << "Eneter Name : ";
    getline(cin, Client.Name);

    cout << "Eneter Phone : ";
    getline(cin, Client.Phone);

    cout << "Eneter Account Balance : ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToString(sClient Client, string Separator = "#||#")
{
    string data = Client.AccountNumber + Separator;
    data += Client.CodPine + Separator;
    data += Client.Name + Separator;
    data += Client.Phone + Separator;
    data += to_string(Client.AccountBalance);

    return data;
}

void SaveRecordToFile(string Record)
{
    fstream MyFile;
    MyFile.open("Data.txt", ios::out | ios::app);

    MyFile << Record << endl;

    MyFile.close();
}

bool ReadAgain()
{
    cout << "Client Added successefuly, do you wont to add more client (Y/N) : ";
    char MoreClient;
    cin >> MoreClient;
    cin.ignore(1, '\n');
    return MoreClient == 'y' || MoreClient == 'Y';
}

int main()
{
    do {
        system("cls");
        sClient Client = ReadNewClient();
        SaveRecordToFile(ConvertRecordToString(Client));
    } while (ReadAgain());
}