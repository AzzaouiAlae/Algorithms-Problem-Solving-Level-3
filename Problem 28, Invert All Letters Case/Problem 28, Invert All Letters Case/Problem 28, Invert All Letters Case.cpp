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

char InvertChar(char MyChar)
{
    return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
}

string InvertTextLettersCase(string Text)
{
    for (short i = 0; i < Text.length(); i++)
        Text[i] = InvertChar(Text[i]);

    return Text;
}

int main()
{
    string Text = ReadText("Enter Your Text : ");

    cout << "\nText After Inverting All Letters Case : \n";
    cout << InvertTextLettersCase(Text) << endl;
}