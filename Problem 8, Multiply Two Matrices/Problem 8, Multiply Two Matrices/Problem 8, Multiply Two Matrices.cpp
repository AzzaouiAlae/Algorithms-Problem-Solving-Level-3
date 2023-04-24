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

int MultiplyCalc(short Number1, short Number2)
{
    return Number1 * Number2;
}

void MultiplyMatrixs(short Matrix1[3][3], short Matrix2[3][3], short ResultMatrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)        
            ResultMatrix[i][j] = MultiplyCalc(Matrix1[i][j], Matrix2[i][j]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3], Matrix2[3][3], ResultMatrix[3][3];
    FillRondomMatrix(Matrix1, 3, 3);
    FillRondomMatrix(Matrix2, 3, 3);

    cout << "Matrix1 :\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2 :\n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nResult :\n";
    MultiplyMatrixs(Matrix1, Matrix2, ResultMatrix, 3, 3);
    
    PrintMatrix(ResultMatrix, 3, 3);

}