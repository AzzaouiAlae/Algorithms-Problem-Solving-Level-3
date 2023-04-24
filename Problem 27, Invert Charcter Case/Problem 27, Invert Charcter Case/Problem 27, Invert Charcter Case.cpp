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
	if ((int)MyChar >= 65 && (int)MyChar <= 90)
		MyChar = tolower(MyChar);
	else if ((int)MyChar >= 97 && (int)MyChar <= 122)
		MyChar = toupper(MyChar);
	return MyChar;
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