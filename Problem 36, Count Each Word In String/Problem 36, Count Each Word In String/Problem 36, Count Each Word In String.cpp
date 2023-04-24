#include <iostream>
#include <string>

using namespace std;

string ReadString(string msg)
{
    string Text;
    cout << msg;
    getline(cin, Text);
    return Text;
}

short CountEachWordInText(string Text)
{
    short Counter = 0, pos = 0;
    string Delim = " ";

    while ((pos = Text.find(Delim)) != string::npos)
    {
        if (Text.substr(0, pos) != "")
        {
            Counter++;
            Text = Text.erase(0, pos + Delim.length());
        }        
    }

    if (Text != "")
        Counter++;

    return Counter;
}

int main()
{
    string Text = ReadString("Enter your text : ");

    cout << "\nThe number of words in your text is : " << CountEachWordInText(Text) << endl;
}