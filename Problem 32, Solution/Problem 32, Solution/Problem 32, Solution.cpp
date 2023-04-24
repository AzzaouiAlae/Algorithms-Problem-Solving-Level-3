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
    MyChar = tolower(MyChar);
    return ((MyChar == 'a') || (MyChar == 'e') || (MyChar == 'i') || (MyChar == 'o') || (MyChar == 'u'));
}

int main()
{
    char MyChar = ReadChar("Enter your Letter : ");

    if (isVowel(MyChar))
        cout << "\nYes Letter \'" << MyChar << "\' is vowel\n";
    else
        cout << "\nNo Letter \'" << MyChar << "\' is vowel\n";
}