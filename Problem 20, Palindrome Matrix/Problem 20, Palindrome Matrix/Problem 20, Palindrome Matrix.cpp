#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)        
            cout << setw(3) << Matrix[i][j] << "   ";
        
        cout << endl;
    }
}

bool IsPalindrome(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Colms - 1 - j])
                return false;
        }
    }
    return true;
}

int main()
{
    short Matrix[3][3] = { {1,5,1}, {2,6,2}, {3,7,3} };

    short Matrix2[3][3] = { {1,5,1}, {2,6,3}, {3,7,3} };

    cout << "Matrix1 : \n";
    PrintMatrix(Matrix, 3, 3);

    if(IsPalindrome(Matrix, 3, 3))
        cout << "\nYes: It's Palindrom Matrix\n";
    else
        cout << "\nNo: It's not Palindrom Matrix\n";
    
}