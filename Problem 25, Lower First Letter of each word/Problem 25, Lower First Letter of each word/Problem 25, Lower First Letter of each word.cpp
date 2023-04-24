#include <iostream>
#include <string>

using namespace std;

string ReadText(string mesg)
{
    string Text;
    cout << mesg;
    getline(cin, Text);
    return Text;
}

string LowerFirstLetter(string Text)
{
    bool isFirstLetter = true;
    for (int i = 0; i < Text.length(); i++)
    {
        if (isFirstLetter && Text[i] != ' ')
            Text[i] = tolower(Text[i]);

        isFirstLetter = Text[i] == ' ' ? true : false;
    }
    return Text;
}

int main()
{
    string Text = ReadText("Eneter your Text : ");

    cout << endl << LowerFirstLetter(Text) << endl;

}