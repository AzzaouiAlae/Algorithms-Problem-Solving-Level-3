#include <iostream>

using namespace std;

short RandomNum(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
            Matrix[i][j] = RandomNum(1, 50);        
    }
}

void PrintMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
            printf(" %*i  ", 3, Matrix[i][j]);

        cout << endl;
    }
}

bool CheckNumberInMatrix(short Matrix[3][3], short Number, short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Number == Matrix[i][j])
                return true;
        }
    }
    return false;
}

void PrintIntersectNum(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            if (CheckNumberInMatrix(Matrix2, Matrix1[i][j], 3, 3))            
                cout << Matrix1[i][j] << "\t";
        }
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3], Matrix2[3][3];

    FillRandomMatrix(Matrix1, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    FillRandomMatrix(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Number are :\n";
    PrintIntersectNum(Matrix1, Matrix2, 3, 3);
}