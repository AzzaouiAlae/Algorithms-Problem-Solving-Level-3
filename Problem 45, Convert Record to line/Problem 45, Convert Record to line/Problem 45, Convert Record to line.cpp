#include <iostream>
#include <string>

using namespace std;

struct ClientData
{ 
    string AccountNum; 
    int PinCode; 
    string Name; 
    string Phone; 
    float AccountBalance;
};

ClientData Client()
{
    ClientData Client1;

    cout << "Please enter client data :\n\n";

    cout << "Enter account number : ";
    getline(cin, Client1.AccountNum);

    cout << "enter Pin Code : ";
    cin >> Client1.PinCode;
    

    cout << "Enter name : ";
    cin.ignore(1, '\n');
    getline(cin, Client1.Name);
    

    cout << "Enter phone number : ";
    cin >> Client1.Phone;
    

    cout << "Enter Account Balance : ";
    cin >> Client1.AccountBalance;    
    

    return Client1;
}

string SaveClientToLine(ClientData client, string delim)
{
    return client.AccountNum + delim + to_string(client.PinCode) + 
           delim + client.Name + delim + client.Phone + delim + 
           to_string(client.AccountBalance);
}

int main()
{
    ClientData client = Client();

    cout << "\n\n\n\nClient Record for saving is : \n" << SaveClientToLine(client, "#||#") << endl;
}