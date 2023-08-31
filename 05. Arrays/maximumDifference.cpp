#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int maxDiff(int arr[], int n)
{
    int maxDf = 0;
    int minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        maxDf = max(maxDf, arr[i] - arr[minIdx]);
        if (arr[minIdx] > arr[i])
        {
            minIdx = i;
        }
    }
    return maxDf;
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

    cout << maxDiff(arr, n) << endl;

    return 0;
}