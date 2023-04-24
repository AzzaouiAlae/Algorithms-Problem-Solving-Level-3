#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

short RandomNum(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FillRondomMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            Matrix[i][j] = RandomNum(1, 100);
    }
}

void PrintMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            printf(" %0*d  ", 2, Matrix[i][j]);

        cout << endl;
    }
}

int SumMatrix(short Matrix[3][3], short Rows, short Colms)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            Sum += Matrix[i][j];        
    }
    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));
    short Matrix[3][3];
    FillRondomMatrix(Matrix, 3, 3);

    cout << "Matrix 1 : \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "\nSum Of Matrix : " << SumMatrix(Matrix, 3, 3) << endl;
}