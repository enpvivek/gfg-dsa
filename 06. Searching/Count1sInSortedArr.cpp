#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            while (mid < n)
            {
                if (arr[mid + 1] != arr[mid] || mid == n - 1)
                {
                    return mid;
                }
                else
                {
                    mid++;
                }
            }
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
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
    int lastOccur = binarySearch(arr, n, 0);
    cout << lastOccur << endl;
    cout << n - lastOccur - 1;

    return 0;
}