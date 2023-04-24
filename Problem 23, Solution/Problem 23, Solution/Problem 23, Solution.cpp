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

void PrintFirstLetterWords(string Text)
{
    bool isFirstLetter = true;

    for (int i = 0; i < Text.length(); i++)
    {
        if (isFirstLetter && Text[i] != ' ')
            cout << Text[i] << endl;

        isFirstLetter = Text[i] == ' ' ? true : false;
    }
}

int main()
{
    PrintFirstLetterWords(ReadText("Enetr your Text : "));
}