#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText(string msg)
{
    string Text;
    cout << msg;
    getline(cin, Text);
    return Text;
}

vector <string> SplitString(string Text, string delim)
{
    vector <string> vecWords;
    short pos = 0;
    string sWord;
    while ((pos = Text.find(delim)) != string::npos)
    {
        sWord = Text.substr(0, pos);
        if (sWord != "")
        {
            vecWords.push_back(sWord);
            sWord = "";
        }

        Text = Text.erase(0, pos + delim.length());
    }

    if(Text != "")
        vecWords.push_back(Text);

    return vecWords;
}

short vectorCounts(vector <string> &MyWords)
{     
    short Counter = 0;
    for  (string &Word : MyWords)    
        Counter++;

    return Counter;    
}

void PrintVector(vector <string>& MyWords)
{
    for (string& Word : MyWords)
        cout << Word << endl;
}

int main()
{
    string Text = ReadText("enter your Text : ");

    vector <string> MyWords = SplitString(Text, " ");

    cout << "\nTokens = " << vectorCounts(MyWords) << endl;

    PrintVector(MyWords);
}