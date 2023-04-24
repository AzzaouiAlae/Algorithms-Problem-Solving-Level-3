#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ToUpper(string Text)
{
    for (short i = 0; i < Text.length(); i++)
        Text[i] = toupper(Text[i]);

    return Text;
}

string JoinString(vector <string>& MyListe, string Delim)
{
    string JoinNames = "";
    for (string& Name : MyListe)
        JoinNames += (Name + Delim);


    return JoinNames.substr(0, JoinNames.length() - Delim.length());
}

vector <string> SplitString(string Text, string delim)
{
    vector <string> vecWords;
    short pos = 0;
    string sWord;
    while ((pos = Text.find(delim)) != string::npos)
    {
        sWord = Text.substr(0, pos);
        if (sWord != "")
        {
            vecWords.push_back(sWord);
            sWord = "";
        }

        Text = Text.erase(0, pos + delim.length());
    }

    if (Text != "")
        vecWords.push_back(Text);

    return vecWords;
}

string ReplaceText(string Text, string Search, string Replace, bool Case = true)
{
    vector <string> vString = SplitString(Text, " ");

    for (string& S : vString)
    {
        if (Case)
        {
            if (Search == S)
                S = Replace;
        }
        else
        {
            if (ToUpper(Search) == ToUpper(S))
                S = Replace;
        }
    }
    return JoinString(vString, " ");

}

int main()
{
    string Text = "Welcom to Morocco , Morocco is a nice country";

    cout << "Original Text match Case : \n" << Text << "\n\n";

    cout << "Replace Text match Case : \n" << ReplaceText(Text, "Morocco", "USA") << "\n\n";

    cout << "Replace Text dont match Case : \n" << ReplaceText(Text, "morocco", "USA", false) << "\n\n";
}