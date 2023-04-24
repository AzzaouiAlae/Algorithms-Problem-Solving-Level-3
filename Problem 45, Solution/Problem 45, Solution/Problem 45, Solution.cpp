#include <iostream>
#include <string>

using namespace std;

struct sClientData
{
    string AccountNum;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClientData ReadNewClient()
{
    sClientData Client1;

    cout << "Please enter client data :\n\n";

    cout << "Enter account number : ";
    getline(cin, Client1.AccountNum);

    cout << "enter Pin Code : ";
    getline(cin, Client1.PinCode);

    cout << "Enter name : ";    
    getline(cin, Client1.Name);


    cout << "Enter phone number : ";
    getline(cin, Client1.Phone);

    cout << "Enter Account Balance : ";
    cin >> Client1.AccountBalance;

    return Client1;
}

string ConvertRecordToLine(sClientData client, string Separator)
{
    return client.AccountNum + Separator + client.PinCode +
           Separator + client.Name + Separator + client.Phone + Separator +
           to_string(client.AccountBalance);
}

int main()
{
    sClientData client = ReadNewClient();

    cout << "\n\n\n\nClient Record for saving is : \n" 
         << ConvertRecordToLine(client, "#||#") << endl;
}