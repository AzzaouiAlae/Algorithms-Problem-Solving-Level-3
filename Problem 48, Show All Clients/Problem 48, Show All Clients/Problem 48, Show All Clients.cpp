#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

void Print_(short _Num)
{
    for (short i = 0; i < _Num; i++)
    {
        cout << "_";
    }
    cout << endl;
}

string PrintTab(short TabNum)
{
    string tab = "";
    for (short i = 0; i < TabNum; i++)
    {
        tab += "\t";
    }
    return tab;
}

void PrintHeader(short NumOfClients)
{
    string List = "Clients List (" + to_string(NumOfClients) + ") Clients.";
    cout << setw(60) << List << endl;
    Print_(102);

    cout << left << setw(20) <<  "\n| Account Number" << setw(13) << "| Pin Code" << setw(35) 
        << "| Client Name" << setw(15) << "| Phone" << "| Account Balance\n";
    Print_(102);
}

vector <string> ImportRecordFile(string FileName, short & NumOfClients)
{
    vector <string> Clients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    string Line;
    while (getline(MyFile, Line))
    {
        Clients.push_back(Line);
        NumOfClients++;
    }
    MyFile.close();
    return Clients;
}

vector <string> SplitString(string Text, string Separator = "#||#")
{
    short pos = 0;
    string sWord;
    vector <string> Client;

    while ((pos = Text.find(Separator)) != string::npos)
    {
        sWord = Text.substr(0, pos);

        if (sWord != "")
        {
            Client.push_back(sWord);
            Text = Text.erase(0, sWord.length() + Separator.length());
        }
    }
    if (Text != "")    
        Client.push_back(Text);
    
    return Client;
}

void PrintClients(vector <string> &AllClients, short NumOfClients)
{
    vector <string> Client;
    for (int i = 0; i < NumOfClients; i++)
    {
        Client = SplitString(AllClients[i]);

        cout << "\n| " << left << setw(17) << Client[0] << "| " << setw(11) << Client[1] << "| " << setw(33)
            << Client[2] << "| " << setw(13) << Client[3] << "| "  << Client[4];
    }
    cout << "\n\n";
    Print_(102);
}

void PrintAllClients()
{
    short NumOfClients = 0;
    vector <string> AllClients = ImportRecordFile("Clients.txt", NumOfClients);
    PrintHeader(NumOfClients);

    PrintClients(AllClients, NumOfClients);
}

int main()
{
    PrintAllClients();

    system("pause>0");
}