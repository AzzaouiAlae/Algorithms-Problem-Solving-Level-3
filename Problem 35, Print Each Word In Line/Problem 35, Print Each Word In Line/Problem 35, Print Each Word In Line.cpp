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

void PrintWord(string Text, short Start, short Stop)
{
    for (; Start <= Stop; Start++)    
        cout << Text[Start];
    
    cout << endl;
}

void PrintWordsInLine(string Text)
{
    short PrevNum = 0;
    cout << "\nYour Words in the text : \n\n";
    for (int i = 0; i < Text.length(); i++)
    {      
        if (Text[i] == ' ')
        {
            PrintWord(Text, PrevNum, i-1);
            PrevNum = i+1;            
        }
        else if (i + 1 == Text.length())        
            PrintWord(Text, PrevNum, i);
    }
}

int main()
{
    string Text = ReadText("Enter your Text : ");

    PrintWordsInLine(Text);
}