#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string fileName = "Clients.txt";

struct sClients {
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
    while ((pos = Text.find(Delim)) != string::npos)
    {
        string sWord = Text.substr(0, pos);
        if (sWord != "")
            vStr.push_back(sWord);

        Text.erase(0, pos + Delim.length());
    }
    if(Text != "")
        vStr.push_back(Text);

    return vStr;
}

sClients ConvertLineToRecord(string Line, string separator = "#||#")
{
    sClients Client;
    vector <string> vStr = SplitString(Line, separator);

    Client.AccountNumber = vStr[0];
    Client.PinCode = vStr[1];
    Client.Name = vStr[2];
    Client.Phone = vStr[3];
    Client.AccountBalance = stod(vStr[4]);

    return Client;
}

vector <sClients> LoadClientDataFromFile(string FileName)
{
    vector <sClients> Clients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        
        while (getline(MyFile, Line))        
            Clients.push_back(ConvertLineToRecord(Line));        
    }
    MyFile.close();
    return Clients;
}

void FindClientNum(vector <sClients> &Clients)
{
    string accoNum;
    cout << "Please enter Account Number : ";
    cin >> accoNum;
    for (int i = 0; i < Clients.size(); i++)
    {
        if (Clients[i].AccountNumber == accoNum)
        {
            cout << "\nThe Following are client details:\n\n";
            cout << "Account Number  : " << Clients[i].AccountNumber << endl;
            cout << "Pin Code        : " << Clients[i].PinCode << endl;
            cout << "Name            : " << Clients[i].Name << endl;
            cout << "Phone           : " << Clients[i].Phone << endl;
            cout << "Account Balance : " << Clients[i].AccountBalance << endl;
            return;
        }
    }
    cout << "\nClient With account number (" << accoNum << ") Not Found\n";
}

int main()
{
    vector <sClients> Clients = LoadClientDataFromFile(fileName);

    FindClientNum(Clients);
}