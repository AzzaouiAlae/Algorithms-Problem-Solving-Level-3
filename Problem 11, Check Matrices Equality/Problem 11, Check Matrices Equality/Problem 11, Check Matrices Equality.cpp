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
            Matrix[i][j] = RandomNum(1, 10);
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

//string MatrixEquality(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Colms)
//{
//    int SumMatrix1 = SumMatrix(Matrix1, 3, 3), SumMatrix2 = SumMatrix(Matrix2, 3, 3);
//    string  Result =  (SumMatrix1 == SumMatrix2) ? "\nYes : Matrices are equal.\n" : "\nNo : Matrices are Not equal.\n";
//    return Result;
//}

bool MatrixEquality(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Colms)
{
    return SumMatrix(Matrix1, 3, 3) == SumMatrix(Matrix2, 3, 3);
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3], Matrix2[3][3];

    FillRondomMatrix(Matrix1, 3, 3);

    FillRondomMatrix(Matrix2, 3, 3);

    cout << "Matrix1\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2\n";
    PrintMatrix(Matrix2, 3, 3);

    if (MatrixEquality(Matrix1, Matrix2, 3, 3))    
        cout << "\nYes : Matrices are equal.\n";
    else
        cout << "\nNo : Matrices are not equal.\n";
    
}