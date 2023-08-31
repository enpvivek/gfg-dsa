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
            return mid;
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

int binSearch(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] < x)
    {
        binSearch(arr, mid + 1, high, x);
    }
    else
    {
        binSearch(arr, low, mid - 1, x);
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << binSearch(arr, 0, n - 1, x);

    return 0;
}