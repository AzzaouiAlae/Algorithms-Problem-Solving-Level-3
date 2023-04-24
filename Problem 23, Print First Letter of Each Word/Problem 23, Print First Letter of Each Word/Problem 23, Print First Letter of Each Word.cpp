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

void PrintFirstLetterInEachWord(string Word)
{
    cout << Word[0] << endl;
    for (int i = 0; i < Word.length(); i++)
    {
        if (Word[i] == ' ')
            cout << Word[i+1] << endl;            
    }
    
}

int main()
{
    PrintFirstLetterInEachWord(ReadText("Enter your Text : "));
}