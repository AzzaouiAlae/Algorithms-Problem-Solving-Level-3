#include <iostream>

using namespace std;

int ReadNum(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}

void PrintFibanacci(int Fibanacci)
{
    int Num1 = 1, Num2 = 1, Temp = 0, Counter = 2;

    cout << Num1 << "  " << Num2 << "  ";

    for (int i = 2; i < Fibanacci; i++)
    {
        cout << Num1 + Num2 << "  ";
        Temp = Num2;
        Num2 = Num1 + Num2;
        Num1 = Temp;
    }
}

int main()
{
    int Fibanacci = ReadNum("enter your Number : ");

    PrintFibanacci(Fibanacci);
}