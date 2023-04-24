#include <iostream>
#include <string>

using namespace std;

char ReadChar(string msg)
{
	char MyChar;
	cout << msg;
	cin >> MyChar;
	return MyChar;
}

char InvertCharCase(char MyChar)
{	
	return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
}

int main()
{
	while (true)
	{
		system("cls");
		char MyChar = ReadChar("Enter your char : ");

		cout << InvertCharCase(MyChar) << endl;
		system("pause>0");
	}


}