#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void spiralTraversal(vector<vector<int>> &arr, int m, int n)
{
    int top = 0, right = n - 1, bottom = m - 1, left = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
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

    spiralTraversal(arr, m, n);

    return 0;
}