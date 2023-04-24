#include <iostream>
#include <string>

using namespace std;

string ReplaceText(string Text, string Search, string Replace)
{
    short pos;
    string strPart = "";
    while ((pos = Text.find(Search)) != string::npos)
    {         
        strPart = Text.substr(0, pos);

        strPart += Replace;

        strPart += Text.substr(pos + Search.length(), Text.length() - 1);

        Text = strPart;
    }

    return Text;
}

int main()
{
    string Text = "Welcom to Morocco, Morocco is a nice country";

    cout << "Original Text : \n" << Text << "\n\n";

    cout << "Replace Text : \n" << ReplaceText(Text, "Morocco", "USA")<< "\n\n";
}