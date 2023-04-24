#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RondomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRondomMatrix(int Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            Matrix[i][j] = RondomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            cout << setw(3) << Matrix[i][j];        

        cout << endl;
    }
}

int ColmsSum(int Matrix[3][3], short Rows, short ColmNum)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
    {        
            Sum += Matrix[i][ColmNum];
    }
    return Sum;
}

void SumMatrixToArr(int Matrix[3][3], int MatrixSum[3], short Rows, short Colms)
{
    for (int i = 0; i < Colms; i++)
        MatrixSum[i] = ColmsSum(Matrix, 3, i);
}

void PrintArray(int MatrixSum[3], short Lengh)
{
    for (int i = 0; i < Lengh; i++)
        cout << "Colm " << i+1 << " Sum = " << MatrixSum[i] << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3], MatrixSum[3];

    FillRondomMatrix(Matrix, 3, 3);

    cout << "The Following is a 3x3 random Matrix : \n";

    PrintMatrix(Matrix, 3, 3);

    SumMatrixToArr(Matrix, MatrixSum, 3, 3);

    cout << "\n\nThe Following are the sum of Colms in Matrix : \n";

    PrintArray(MatrixSum, 3);
}