#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector <string>& MyVecListe, string Delim)
{
    string JoinNames = "";
    for (string& Name : MyVecListe)
        JoinNames += (Name + Delim);


    return JoinNames.substr(0, JoinNames.length() - Delim.length());
}

string JoinString(string MyArrListe[], short Lenght, string Delim)
{
    string JoinNames = "";
    for (int i = 0; i < Lenght; i++)
        JoinNames += (MyArrListe[i] + Delim);


    return JoinNames.substr(0, JoinNames.length() - Delim.length());
}

int main()
{
    vector <string> MyListe = { "Alae", "Oussama", "Salwa", "Younes" };
    cout << "Vector after join:\n\n";
    cout << JoinString(MyListe, " ") << endl;
    string MyArrListe[] = { "Alae", "Oussama", "Salwa", "Younes" };

    cout << "\nArray after join:\n\n";
    cout << JoinString(MyArrListe, 4, "|") << endl;

}