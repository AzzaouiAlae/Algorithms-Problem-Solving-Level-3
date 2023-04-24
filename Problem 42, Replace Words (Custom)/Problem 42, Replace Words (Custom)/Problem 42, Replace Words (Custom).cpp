#include <iostream>
#include <string>

using namespace std;

string ToUpper(string Text)
{
    for (short i = 0; i < Text.length(); i++)
        Text[i] = toupper(Text[i]);

    return Text;
}

string ReplaceText(string Text, string Search, string Replace, bool Case = true)
{
    
    short pos;
    string strPart = "";

    if (Case)
    {
        while ((pos = Text.find(Search)) != string::npos)
        {
            strPart = Text.substr(0, pos);

            strPart += Replace;

            strPart += Text.substr(pos + Search.length(), Text.length() - 1);

            Text = strPart;
        }
    }
    else
    {
        string TextUpper = ToUpper(Text);
        while ((pos = ToUpper(Text).find(ToUpper(Search))) != string::npos)
        {
            strPart = Text.substr(0, pos);

            strPart += Replace;

            strPart += Text.substr(pos + Search.length(), Text.length() - 1);

            Text = strPart;
        }
    }

    return Text;
}

int main()
{
    string Text = "Welcom to Morocco, Morocco is a nice country";

    cout << "Original Text match Case : \n" << Text << "\n\n";

    cout << "Replace Text match Case : \n" << ReplaceText(Text, "morocco", "USA") << "\n\n";

    cout << "Replace Text dont match Case : \n" << ReplaceText(Text, "morocco", "USA", false) << "\n\n";
}