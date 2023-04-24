#include <iostream>
#include <math.h>

using namespace std;

short RandomNum(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)        
            Matrix[i][j] = RandomNum(0, 1);        
    }
}

void PritMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            printf(" %*i  ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
}

short CountNumberInMatrix(short Matrix[3][3],short Number, short Rows, short Colms)
{
    short NumberCount = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Number == Matrix[i][j])
                NumberCount++;
        }
    }
    return NumberCount;
}

bool IsSparseMatrix(short Matrix[3][3], short Rows, short Colms)
{
    short MaxSize = Rows * Colms;
    
    return (ceil(MaxSize / 2) < CountNumberInMatrix(Matrix, 0, 3, 3));
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix[3][3];

    FillRandomMatrix(Matrix, 3, 3);

    cout << "Matrix:\n";
    PritMatrix(Matrix, 3, 3);

    if (IsSparseMatrix(Matrix, 3, 3))
        cout << "Yes: It's a Sparse Matrix \n";

    else
        cout << "No: It's not a Sparse Matrix \n";
}