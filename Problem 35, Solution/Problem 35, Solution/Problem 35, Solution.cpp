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

void PrintEachWord(string Text, string Delim)
{
    short pos;
    string sWord;

    cout << "\nYour Words in the Text :\n\n";

    while ((pos = Text.find(Delim)) != string::npos)
    {
        sWord = Text.substr(0, pos);
        if (sWord != "")
            cout << sWord << endl;

        Text = Text.erase(0, pos + Delim.length());
        sWord = "";
    }

    if (Text != "")
        cout << Text << endl;
}

int main()
{
    string Text = ReadText("enter your Text : ");

    PrintEachWord(Text, " ");
}