#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct sClient
{
    string AccoutNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector <string> SplitString(string Text, string delim)
{
    vector <string> vecWords;
    short pos = 0;
    string sWord;
    while ((pos = Text.find(delim)) != string::npos)
    {
        sWord = Text.substr(0, pos);
        if (sWord != "")
        {
            vecWords.push_back(sWord);
            sWord = "";
        }

        Text = Text.erase(0, pos + delim.length());
    }

    if (Text != "")
        vecWords.push_back(Text);

    return vecWords;
}

sClient ConvertRecordToStruct(string Data, string Separator = "#||#")
{
    sClient Client;

    vector <string> vData = SplitString(Data, Separator);    

    Client.AccoutNumber = vData[0];
    Client.PinCode = vData[1];
    Client.Name = vData[2];
    Client.Phone = vData[3];
    Client.AccountBalance = stod(vData[4]);

    return Client;
}

void PrintClientData(sClient Client)
{   

    cout << "\n\nThe following is extract record data : \n\n";
    cout << "Accout Number   : " << Client.AccoutNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

int main()
{
    string Record = "A15#||#1234#||#Alae Azzaoui#||#0622437387#||#2000";

    cout << "Line Record is : " << Record;

    sClient Client = ConvertRecordToStruct(Record);

    
    PrintClientData(Client);
}