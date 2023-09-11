#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool checkSafe(int row, int col, int sol[4][4])
{
    for (int i = 0; i < col; i++)
    {
        if (sol[row][i] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (sol[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i < 4 && j >= 0; i++, j--)
    {
        if (sol[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool nQueensRec(int col, int sol[4][4])
{
    if (col == 4)
    {
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (checkSafe(i, col, sol))
        {
            sol[i][col] = 1;
            if (nQueensRec(col + 1, sol) == true)
            {
                return true;
            }
            sol[i][col] = 0;
        }
    }
    return false;
}

bool nQueens()
{

    int sol[4][4] = {0};
    if (nQueensRec(0, sol) == true)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    nQueens() ? (cout << "YES" << endl) : (cout << "NO" << endl);

    return 0;
}