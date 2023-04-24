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

enum enSmallCapital { Small = 0, Capital = 1, All = 2 };

short CountLettersCase(string Text, enSmallCapital Case = All)
{
    short Counter = 0;
    if (Case == All)
        return Text.length();

    if (Case == Small)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (islower(Text[i]))
                Counter++;
        }
    }
    else
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (isupper(Text[i]))
                Counter++;
        }
    }
    return Counter;
}

short CountSmallLetters(string Text)
{
    short Counter = 0;
    for (int i = 0; i < Text.length(); i++)
    {
        if (islower(Text[i]))
            Counter++;
    }
    return Counter;
}

short CountCapitalLetters(string Text)
{
    short Counter = 0;
    for (int i = 0; i < Text.length(); i++)
    {
        if (isupper(Text[i]))
            Counter++;
    }
    return Counter;
}

int main()
{
    string Text = ReadText("Enter your Text : ");

    cout << "\nText Lenght = " << Text.length() << endl;
    cout << "Text Capital Letters Count = " << CountLettersCase(Text, Capital) << endl;
    cout << "Text Small Letters Count = " << CountLettersCase(Text, Small) << endl;
}