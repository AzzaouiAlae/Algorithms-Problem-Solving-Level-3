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

void UpperFirstLetterWords(string &Text)
{
    bool isFirstLetter = true;

    for (int i = 0; i < Text.length(); i++)
    {
        if (isFirstLetter && Text[i] != ' ')
            Text[i] = toupper(Text[i]);

        isFirstLetter = Text[i] == ' ' ? true : false;
    }
}

int main()
{
    string Text = ReadText("Enter your Text : ");

    UpperFirstLetterWords(Text);

    cout << "\nString After Conversion : \n";
    cout << Text << endl;
}