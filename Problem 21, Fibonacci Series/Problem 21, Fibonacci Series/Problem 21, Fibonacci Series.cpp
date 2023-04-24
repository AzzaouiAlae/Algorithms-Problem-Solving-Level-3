#include <iostream>

using namespace std;

int ReadNum(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}

void PrintFibonacci(int Fibonacci)
{
    int fibNumber = 0, Prev2 = 0, Prev1 = 1;
    cout << "1   ";
    for (int i = 2; i <= Fibonacci; i++)
    {
        fibNumber = Prev2 + Prev1;
        cout << fibNumber <<"   ";
        Prev2 = Prev1;
        Prev1 = fibNumber;
    }
}

int main()
{
    int Fibonacci = ReadNum("Enter your number : ");

    PrintFibonacci(Fibonacci);
}