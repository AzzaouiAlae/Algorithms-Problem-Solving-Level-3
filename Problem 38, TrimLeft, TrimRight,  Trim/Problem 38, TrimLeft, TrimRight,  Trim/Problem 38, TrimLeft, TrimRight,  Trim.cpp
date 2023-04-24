#include <iostream>
#include <string>

using  namespace std;

string TrimLeft(string Text)
{
    while (Text[0] == ' ')    
        Text = Text.erase(0, 1);

    return Text;
}

string TrimRight(string Text)
{
    while (Text[Text.length() - 1] == ' ')
        Text = Text.erase(Text.length() - 2, Text.length() - 1);

    return Text;
}

string Trim(string Text)
{
    Text = TrimLeft(Text);

    Text = TrimRight(Text);

    return Text;
}

int main()
{
    string Text = "    Alae Azzaoui    ";

    cout << "Text        = " << Text << "." << endl;

    cout << "\nTrim Left   = " << TrimLeft(Text) << "." << endl;

    cout << "\nTrim Right  = " << TrimRight(Text) << "." << endl;

    cout << "\nTrim   = " << Trim(Text) << "." << endl;
}