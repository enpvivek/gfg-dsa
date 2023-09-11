#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool checkSafe(int arr[4][4], int i, int j)
{
    if (i < 4 && j < 4 && arr[i][j] == 1)
    {
        return true;
    }
    return false;
}

bool solveMazeRec(int arr[4][4], int i, int j, int sol[4][4])
{
    if (i == 3 && j == 3)
    {
        sol[i][j] = 1;
        return true;
    }
    if (checkSafe(arr, i, j))
    {
        sol[i][j] = 1;
        if (solveMazeRec(arr, i + 1, j, sol) == true)
            return true;
        else if (solveMazeRec(arr, i, j + 1, sol) == true)
            return true;
        sol[i][j] = 0;
    }
    return false;
}

bool solveMaze(int arr[4][4])
{
    int sol[4][4] = {0};
    if (solveMazeRec(arr, 0, 0, sol) == true)
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
    int arr[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    solveMaze(arr) ? (cout << "YES" << endl) : (cout << "NO" << endl);

    return 0;
}