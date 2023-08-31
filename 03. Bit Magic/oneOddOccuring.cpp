#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int oneOddOccuring(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count % 2 != 0)
        {
            return arr[i];
        }
    }
}

int OddOccuring(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
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
    cout << OddOccuring(arr, n);

    return 0;
}