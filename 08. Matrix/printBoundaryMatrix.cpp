#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void printMatrix(int **arr, int m, int n)
{

    for (int j = 0; j < n; j++)
    {
        cout << arr[0][j] << " ";
    }

    for (int i = 1; i < m - 1; i++)
    {
        cout << arr[i][n - 1] << " ";
    }

    for (int j = n - 1; j >= 0; j--)
    {
        cout << arr[m - 1][j] << " ";
    }
    for (int i = m - 2; i >= 1; i--)
    {
        cout << arr[i][0] << " ";
    }
}
int main()
{
    int **arr;
    int m = 5, n = 5;
    arr = new int *[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    printMatrix(arr, m, n);

    return 0;
}