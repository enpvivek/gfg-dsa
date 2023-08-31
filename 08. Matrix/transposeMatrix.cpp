#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void printMatrix(vector<vector<int>> &arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        { // j = i+1 to prevent swapping twice
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m = 5, n = 5;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        arr.push_back(v);
    }

    printMatrix(arr, m, n);

    return 0;
}