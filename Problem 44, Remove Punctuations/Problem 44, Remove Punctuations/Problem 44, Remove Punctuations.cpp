#include <iostream>
#include <string>

using namespace std;

string RemovePunct(string Text)
{
    for (int i = 0; i < Text.length(); i++)
    {
        if (ispunct(Text[i]))
            Text.erase(i, 1);
    }
    return Text;
}

int main()
{
    string Text = "Welcom to Morocco, Morroco is a nice country; it's amazing.";

    cout << "Original Text:\n" << Text;

    cout << "\n\nText after remove punctuations \n" << RemovePunct(Text) << "\n\n";    
}