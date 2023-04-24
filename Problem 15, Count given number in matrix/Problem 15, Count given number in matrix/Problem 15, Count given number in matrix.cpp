#include <iostream>

using namespace std;

short ReadNumber(string msg)
{
    short Num;
    cout << msg;
    cin >> Num;
    return Num;
}

short RandomNum(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(short Matrix[3][3], short Rows, short Colms)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            Matrix[i][j] = RandomNum(1, 5);
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

void SearchNumMatrix(short Matrix[3][3], short Rows, short Colms)
{
    short SearchNumber = ReadNumber("\nEnter the number to count in Matrix: ");

    short Count = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++)
        {
            if (SearchNumber == Matrix[i][j])            
                Count++;            
        }
    }

    cout << "\nNumber " << SearchNumber << " Count in matrix is : " << Count << endl;
}

int main()
{
    short Matrix[3][3];
    FillRandomMatrix(Matrix, 3, 3);

    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    SearchNumMatrix(Matrix, 3, 3);
}