#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

const string FileName = "Clients.txt";

struct sClients {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string Text, string Delim)
{
	vector <string> vString;
	short pos = 0;
	string sWord = "";
	
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

sClients ConvertLineToRecord(string Line, string Separator = "#||#")
{
	vector <string> vString = SplitString(Line, Separator);

	sClients Client;
	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

vector <sClients> LoadRecordClientsFromFile()
{
	vector <sClients> Clients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		sClients Client;

		while (getline(MyFile, Line))
		{
			if (Line != "")
			{				
				Clients.push_back(ConvertLineToRecord(Line));
			}
		}
	}
	return Clients;
}

void Print_(short _Num)
{
	for (short i = 0; i < _Num; i++)
	{
		cout << "_";
	}
	cout << endl;
}

void PrintClient(sClients Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(35) << Client.Name;
	cout << "| " << left << setw(13) << Client.Phone;
	cout << "| " << Client.AccountBalance << endl;
}

void PrintAllClients(vector <sClients> Clients)
{
	cout << setw(51) << "Clients List (" << Clients.size() << ") Client(s)\n";
	Print_(102);
	cout << "\n| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(35) << "Clients Name";
	cout << "| " << left << setw(13) << "Phone";
	cout << "| Account Balance\n";
	Print_(102);

	for (sClients Client : Clients)	
		PrintClient(Client);
	
	Print_(102);
}

void main()
{
	vector <sClients> Clients = LoadRecordClientsFromFile();

	PrintAllClients(Clients);
}