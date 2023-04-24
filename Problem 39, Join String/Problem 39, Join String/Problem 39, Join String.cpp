#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector <string>& MyListe, string Delim)
{
    string JoinNames = "";
    for (string& Name : MyListe)
        JoinNames += (Name + Delim);

    
    return JoinNames.substr(0, JoinNames.length() - Delim.length());
}

int main()
{
    vector <string> MyListe = {"Alae", "Oussama", "Salwa", "Younes"};
    cout << "Vector after join:\n\n";
    cout << JoinString(MyListe, " ") << endl;
}