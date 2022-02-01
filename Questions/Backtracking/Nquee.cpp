// N queen problem states that there is a chessboard of nxn size in which we have to arrange n queens such that no queen attack other
//Ex for n = 4,
// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0
//is correct output

#include <iostream>
using namespace std;
//Function to check whether a position is safe or not
bool isSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < n; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    int rows = x;
    int cols = y;
    while (rows >= 0 && cols >= 0)
    {
        if (arr[rows][cols] == 1)
            return false;
        rows--;
        cols--;
    }
    rows = x;
    cols = y;
    while (rows >= 0 && cols < n)
    {
        if (arr[rows][cols] == 1)
            return false;
        rows--;
        cols++;
    }

    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x == n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }
            arr[x][col] = 0; //Backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }

    if (nQueen(a, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
                cout<<endl;
        }
    }
    return 0;
}