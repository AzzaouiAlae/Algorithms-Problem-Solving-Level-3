#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int RandomMatrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            RandomMatrix[i][j] = RandomNumber(1, 100);
    }
}

void PrintMatrix(int RandomMatrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            cout << setw(3) << RandomMatrix[i][j] << "\t";

        cout << endl;
    }
}

short RowSum(int RandomMatrix[3][3], short RowNum, short Colms)
{
    short sum = 0;
    sum = 0;
    for (int i = 0; i < Colms; i++)
    {
        sum += RandomMatrix[RowNum][i];
    }
    return sum;
}

void PrintSumMatrix(int RandomMatrix[3][3], short Rows, short Colms)
{    
    for (int i = 0; i < Rows; i++)    
        cout << "Row " << i + 1 << " Sum = " << RowSum(RandomMatrix, i, 3) << endl;    
}

int main()
{
    srand((unsigned)time(NULL));

    int RandomMatrix[3][3];

    FillRandomMatrix(RandomMatrix, 3, 3);

    cout << "\nThe Following is a 3x3 random Matrix : \n";

    PrintMatrix(RandomMatrix, 3, 3);

    cout << "\n\nThe Following are the sum of row in Matrix : \n";

    PrintSumMatrix(RandomMatrix, 3, 3);

    system("pause>0");
}