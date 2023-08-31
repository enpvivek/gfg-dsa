#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void printMatrix(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        if (i % 2 != 0)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
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