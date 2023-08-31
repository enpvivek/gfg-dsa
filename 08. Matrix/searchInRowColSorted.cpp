#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void searchInMatrix(vector<vector<int>> arr, int R, int C, int X)
{
    int idxA = -1, idxB = -1; // Initialize with -1 instead of 0
    for (int i = 0; i < R; i++)
    {
        if (arr[i][0] <= X)
        {
            if (arr[i][0] == X)
            {
                cout << i << " " << 0 << endl;
                return;
            }
            idxA = i;
        }
    }
    for (int j = 0; j < C; j++)
    {
        if (arr[0][j] <= X)
        {
            if (arr[0][j] == X)
            {
                cout << 0 << " " << j << endl;
                return;
            }
            idxB = j;
        }
    }
    for (int i = 1; i <= idxA; i++)
    { // Use 1 instead of idxA
        for (int j = 1; j <= idxB; j++)
        { // Use 1 instead of idxB
            if (arr[i][j] == X)
            {
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    cout << "Element not found." << endl; // Add a message if element is not found
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> arr;
    for (int i = 0; i < R; i++)
    {
        vector<int> v;
        for (int j = 0; j < C; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        arr.push_back(v);
    }
    int X = 63;

    searchInMatrix(arr, R, C, X);

    for (int i = 0; i < R; i++)
    {

        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
