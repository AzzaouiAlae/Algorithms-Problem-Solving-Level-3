#include <iostream>
#include <iomanip>

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
            Matrix[i][j] = RandomNum(1, 50);        
    }
}

void PrintMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            cout << setw(3) << Matrix[i][j] << "  ";
        cout << endl;
    }
}

short MaxNumberInMatrix(short Matrix[3][3], short Rows, short Colms)
{
    short MaxNumber = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Matrix[i][j] > MaxNumber)
                MaxNumber = Matrix[i][j];
        }
    }
    return MaxNumber;
}

short MinNumberInMatrix(short Matrix[3][3], short Rows, short Colms)
{
    short MinNumber = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (Matrix[i][j] < MinNumber)
                MinNumber = Matrix[i][j];
        }
    }
    return MinNumber;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix[3][3];
    FillRandomMatrix(Matrix, 3, 3);

    cout << "Matrix1:\n";
    PrintMatrix(Matrix, 3, 3);

    cout << "\nMax Number in Matrix is : " << MaxNumberInMatrix(Matrix, 3, 3) << endl;

    cout << "\nMin Number in Matrix is : " << MinNumberInMatrix(Matrix, 3, 3) << endl;
}