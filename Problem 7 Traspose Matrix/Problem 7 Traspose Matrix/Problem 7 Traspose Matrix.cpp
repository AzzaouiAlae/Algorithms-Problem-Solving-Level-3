#include <iostream>
#include <iomanip>

using namespace std;

void FillOrderMatrix(int Matrix[3][3], short Rows, short Colms)
{
    short Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            Counter++;
            Matrix[i][j] = Counter;
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            cout << setw(2) << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void FillTransporsedMatrix(int Matrix[3][3], int TransMatrix[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Colms; i++)
    {
        for (short j = 0; j < Rows; j++)
        {
            TransMatrix[i][j] = Matrix[j][i];
        }        
    }
}

int main()
{
    int Matrix[3][3], transMatrix[3][3];

    cout << "The Following is a 3x3 Orderd Matrix: \n";

    FillOrderMatrix(Matrix, 3, 3);

    PrintMatrix(Matrix, 3, 3);

    cout << "\nThe Following is the transporsed Matrix: \n";

    FillTransporsedMatrix(Matrix, transMatrix, 3, 3);

    PrintMatrix(transMatrix, 3, 3);

    system("pause>0");
}