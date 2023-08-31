#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int maxProfit(int arr[], int n)
{
    int currMax = 0;
    int minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            currMax += arr[i] - arr[i - 1];
        }
    }
    return currMax;
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

    cout << maxProfit(arr, n) << endl;

    return 0;
}