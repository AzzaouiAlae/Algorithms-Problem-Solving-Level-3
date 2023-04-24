#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string Text)
{
    for (int i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ')
            return Text.substr(i , Text.length() - i);
    }
    return "";
}

string TrimRight(string Text)
{
    for (int i = Text.length() - 1; i >= 0; i--)
    {
        if (Text[i] != ' ')
            return Text.substr(0, i+1);
    }
    return "";
}

string Trim(string Text)
{    
    return TrimLeft(TrimRight(Text));
}

int main()
{
    string Text = "    Alae Azzaoui    ";

    cout << "Text       = " << Text << ".\n";

    cout << "Trim Left  = " << TrimLeft(Text) << ".\n";

    cout << "Trim Right = " << TrimRight(Text) << ".\n";

    cout << "Trim       = " << Trim(Text) << ".\n";
}