#include <iostream>
#include <string>

using namespace std;

string ReadText(string msg)
{
    cout << msg;
    string Text;
    getline(cin, Text);
    return Text;
}

bool isVowel(char MyChar)
{
    MyChar = tolower(MyChar);
    return ((MyChar == 'a') || (MyChar == 'e') || (MyChar == 'i') || (MyChar == 'o') || (MyChar == 'u'));
}

short VowelCount(string Text)
{
    short Count = 0;
    for (int i = 0; i < Text.length(); i++)
    {
        if (isVowel(Text[i]))
            Count++;
    }
    return Count;
}

int main()
{
    string Text = ReadText("Enter Your Text : ");

    cout << "\nNumber of vowels is : " << VowelCount(Text) << endl;
}