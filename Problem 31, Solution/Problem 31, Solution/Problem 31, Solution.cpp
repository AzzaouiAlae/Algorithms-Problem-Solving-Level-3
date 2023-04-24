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

char ReadChar(string msg)
{
    char MyChar;
    cout << msg;
    cin >> MyChar;
    return MyChar;
}

short LetterCounter(string Text, char Letter)
{
    short Counter = 0;
    for (int i = 0; i < Text.length(); i++)
    {
        if (Text[i] == Letter)
            Counter++;
    }
    return Counter;
}

char InvertChar(char MyChar)
{
    return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
}

short LetterCounterAllCase(string Text, char Letter, bool MatchCase = true)
{
    short Counter = 0;
    if (MatchCase)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] == Letter)
                Counter++;
        }
    }
    else
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] == Letter || InvertChar(Text[i]) == Letter)
                Counter++;
        }
    }
    return Counter;
}

int main()
{
    string Text = ReadText("Enter your Text : ");

    char MyLetter = ReadChar("\nEnter your character : ");

    cout << "\nLetter \'" << MyLetter << "\' Count = " << LetterCounter(Text, MyLetter) << endl;

    cout << "\nLetter \'" << MyLetter << "\' Or \'" << InvertChar(MyLetter)
         << "\' Count = " << LetterCounterAllCase(Text, MyLetter, false) << endl;
}