#include <iostream>
#include <string>

using namespace std;

string RemovePunct(string Text)
{
    string Str = "";

    for (int i = 0; i < Text.length(); i++)
    {
        if (!ispunct(Text[i]))
            Str += Text[i];
    }
    return Str;
}

int main()
{
    string Text = "Welcom to Morocco, Morroco is a nice country; it's amazing.";

    cout << "Original Text:\n" << Text;

    cout << "\n\nText after remove punctuations \n" << RemovePunct(Text) << "\n\n";

    system("pause>0");
}