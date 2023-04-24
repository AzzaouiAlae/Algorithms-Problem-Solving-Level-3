#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
            cout << setw(3) << Matrix[i][j];
        cout << endl;        
    }
}

bool IsScalarMatrix(short Matrix[3][3], short Rows, short Colms)
{
    short FirstNum = Matrix[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (j == i && FirstNum != Matrix[i][j])
                return false;
            else if (j != i && Matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    short Matrix[3][3] = { {5,0,0}, {0,5,0}, {0,0,5} };
    cout << "Matrix : \n";
    PrintMatrix(Matrix, 3, 3);

    if (IsScalarMatrix(Matrix, 3, 3))    
        cout << "\nYes: Matrix is Scalar\n";
    else
        cout << "\nNo: Matrix is not Scalar\n";

    system("pause>0");
}