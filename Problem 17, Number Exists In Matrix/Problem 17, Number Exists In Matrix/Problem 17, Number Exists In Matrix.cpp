#include <iostream>

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
            Matrix[i][j] = RandomNum(0, 100);
    }
}

void PritMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            printf(" %*i  ", 3, Matrix[i][j]);
        }
        cout << endl;
    }
}

int ReadNum(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
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

int main()
{
    srand((unsigned)time(NULL));

    short Matrix[3][3];

    FillRandomMatrix(Matrix, 3, 3);

    cout << "Matrix:\n";
    PritMatrix(Matrix, 3, 3);

    if (CheckNumberInMatrix(Matrix, ReadNum("\nEnter a Number to look for in matrix: "), 3, 3))
        cout << "\nYes: It's there \n";

    else
        cout << "\nNo: It's not there \n";


}