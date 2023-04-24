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

string ReverseWords(string Text)
{
    string Revers = "";
    for (int i = Text.length() - 1; i >= 0; i--)
    {
        if (Text[i] == ' ')
        {
            Revers += (Text.substr(i + 1, Text.length() - i - 1) + " ");
            Text.erase(i, Text.length() - i);
        }
    }
    if (Text != "")
        Revers += Text;

    return Revers;
}

int main()
{
    string Text = ReadText("Enter your Text : ");

    cout << "\n\n" << ReverseWords(Text) << "\n\n";
}