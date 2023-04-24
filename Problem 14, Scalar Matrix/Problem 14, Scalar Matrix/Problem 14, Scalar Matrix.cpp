#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNum(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            Matrix[i][j] = RandomNum(1, 9);
            if (i == j)
              Matrix[i][j] = 5;
          else
              Matrix[i][j] = 0;
        }
    }
}

void PrintMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            printf(" %0*d  ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
}

bool IsScalarMatrix(short Matrix[3][3], short Rows, short Colms)
{
    short CheckNum;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (i == 0 && j == 0)
                CheckNum = Matrix[i][j];
            else if (i == j && CheckNum != Matrix[i][j])
                return false;
            else if (i != j && Matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix[3][3];

    FillRandomMatrix(Matrix, 3, 3);
    PrintMatrix(Matrix, 3, 3);

    if (IsScalarMatrix(Matrix, 3, 3))    
        cout << "\nYes: Matrix is scalar\n";
    else
        cout << "\nNo: Matrix is not scalar\n";
}