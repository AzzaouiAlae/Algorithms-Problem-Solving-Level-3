#include <iostream>

using namespace std;

void PrintFibonacciUsingRecursion(short Number, short Prev1, short Prev2)
{
    int FebNumber = 0;
    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev1 = Prev2;
        Prev2 = FebNumber;
        cout << FebNumber << "\t";
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    PrintFibonacciUsingRecursion(10, 1, 0);
}