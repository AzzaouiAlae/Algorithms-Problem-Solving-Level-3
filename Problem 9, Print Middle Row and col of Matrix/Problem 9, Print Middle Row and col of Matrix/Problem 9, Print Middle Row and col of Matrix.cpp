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

void PrintMidRowsMatrix(short Matrix[3][3], short MidRows, short Colms)
{
    for (int i = 0; i < Colms; i++)
        printf(" %0*d  ", 2, Matrix[MidRows][i]);
    cout << endl;
}

void PrintMidColmsMatrix(short Matrix[3][3], short Rows, short MidColms)
{
    for (int i = 0; i < Rows; i++)
        printf(" %0*d  ", 2, Matrix[i][MidColms]);
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3];

    FillRondomMatrix(Matrix1, 3, 3);

    cout << "Matrix : \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMid Row :\n";
    PrintMidRowsMatrix(Matrix1, 1, 3);

    cout << "\nMid Colm :\n";
    PrintMidColmsMatrix(Matrix1, 3, 1);


}