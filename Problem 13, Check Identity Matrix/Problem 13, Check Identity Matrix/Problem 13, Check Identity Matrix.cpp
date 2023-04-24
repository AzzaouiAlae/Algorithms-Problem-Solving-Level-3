#include <iostream>

using namespace std;

int RandomNum(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)        
        {
            Matrix[i][j] = RandomNum(0, 10);
            /*if (i == j)
                Matrix[i][j] = 1;
            else
                Matrix[i][j] = 0;*/
        }
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

bool CheckIdentityMatrix(short Matrix[3][3], short Rows, short Colms)
{    
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (i == j && Matrix[i][j] != 1)
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

    if (CheckIdentityMatrix(Matrix, 3, 3))
        cout << "\nYes: Matrix is identity\n";
    else
        cout << "\nNo: Matrix is not identity\n";
    

}