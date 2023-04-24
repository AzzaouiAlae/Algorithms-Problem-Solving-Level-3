#include <iostream>
#include <string>

using namespace std;

string ReplaceText(string Text, string Search, string Replace)
{
    short pos = Text.find(Search);

    while (pos != string::npos)
    {
        Text = Text.replace(pos, Search.length(), Replace);
        pos = Text.find(Search);
    }
    return Text;
}

int main()
{
    string Text = "Welcom to Morocco, Morocco is a nice country";

    cout << ReplaceText(Text, "Morocco", "USA");
}