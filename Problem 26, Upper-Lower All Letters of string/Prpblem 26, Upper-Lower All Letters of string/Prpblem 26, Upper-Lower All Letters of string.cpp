#include <iostream>
#include <string>

using namespace std;

string ReadText(string msg)
{
    string Text;
    cout << msg;
    getline(cin, Text);
    return Text;
}

string ToUpper(string Text)
{
    for (short i = 0; i < Text.length(); i++)    
        Text[i] = toupper(Text[i]);

    return Text;
}

string ToLower(string Text)
{
    for (short i = 0; i < Text.length(); i++)
        Text[i] = tolower(Text[i]);

    return Text;
}

int main()
{
    string Text = ReadText("Enter your Text : ");

    cout << "\nString After Upper : \n";
    cout << ToUpper(Text) << endl;

    cout << "\nString After Lower : \n";
    cout << ToLower(Text) << endl;
}