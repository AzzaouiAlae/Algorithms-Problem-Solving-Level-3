#include <iostream>

using namespace std;

int ReadNum(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}

void FibanSerie(int Fibanacci)
{
    static int fibNumber = 0, Prev2 = 0, Prev1 = 1, Counter = 1;

    if(Prev2 == 0)
        cout << "1   ";

    fibNumber = Prev2 + Prev1;
    cout << fibNumber << "   ";
    Prev2 = Prev1;
    Prev1 = fibNumber;
    Counter++;
    if (Counter < Fibanacci)
        FibanSerie(Fibanacci);
}

int main()
{
    int Fibanacci = ReadNum("Enter your number : ");

    FibanSerie(Fibanacci);
}