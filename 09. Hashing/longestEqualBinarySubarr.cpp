#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int longestBinarySubArr(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 0)
            {
                sum--;
            }
            else if (arr[j] == 1)
            {
                sum++;
            }
            if (sum == 0)
            {
                res = max(res, j - i + 1);
            }
            // cout << sum << " ";
        }
        // cout << endl;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longestBinarySubArr(arr, n) << endl;

    return 0;
}