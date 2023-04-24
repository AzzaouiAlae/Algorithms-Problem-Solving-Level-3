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
};

string ReadAccountNum()
{
	cout << "Please enter the account number : ";
	string AccNum;
	cin >> AccNum;
	return AccNum;
}

vector <string> SplitString(string Text, string Delim)
{
	short pos;
	string sWord;
	vector <string> vString;
	while ((pos = Text.find(Delim)) != string::npos)
	{
		sWord = Text.substr(0, pos);
		if (sWord != "")		
			vString.push_back(sWord);
		
		Text = Text.erase(0, pos + Delim.length());
	}
	if(Text != "")
		vString.push_back(Text);

	return vString;
}

sClient ConvertLineToRecord(string Line, string Separator = "#||#")
{
	sClient Client;
	vector <string> vString = SplitString(Line, Separator);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

vector <sClient> LoadRecordFromFile(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	vector <sClient> vClients;

	if (MyFile.is_open())
	{
		string Line = "";

		while (getline(MyFile, Line))		
			vClients.push_back(ConvertLineToRecord(Line));
		
		
		MyFile.close();
	}
	return vClients;
}

bool FindClientByAccNum(string AccountNumber, sClient &Client)
{
	vector <sClient> Clients = LoadRecordFromFile(ClientsFileName);

	for (sClient C : Clients)
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
	cout << "\nThe Following are client details\n";
	cout << "\nAccount Number  : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone           : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;
}

int main()
{
	string AccountNumber = ReadAccountNum();

	sClient Client;
	
	if (FindClientByAccNum(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
		cout << "The Account Number (" << AccountNumber << ") is not found\n";

	system("pause>0");
}