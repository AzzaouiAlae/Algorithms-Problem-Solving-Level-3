#include <iostream>
#include <tchar.h>

using namespace std;

char ReadChar(string msg)
{
    char MyChar;
    cout << msg;
    cin >> MyChar;
    return MyChar;
}

bool isVowel(char MyChar)
{
    string Vowel = "aAeEiIoOuU";
    for (int i = 0; i < Vowel.length(); i++)
    {
        if (MyChar == Vowel[i])
            return true;
    }
    return false;
}

int main()
{
    char MyChar = ReadChar("Enter your Letter : ");

    if (isVowel(MyChar))
        cout << "\nYes Letter \'" << MyChar << "\' is vowel\n";
    else
        cout << "\nNo Letter \'" << MyChar << "\' is vowel\n";
}