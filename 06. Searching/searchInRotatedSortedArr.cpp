#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int searchRotated(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[low] < arr[mid] && (x < arr[mid] && x >= arr[low]))
        {
            high = mid - 1;
        }
        else if (arr[mid] < arr[high] && (x > arr[mid] && x <= arr[high]))
        {
            low = mid + 1;
        }
        else if (arr[low] < arr[mid] && !(x < arr[mid] && x >= arr[low]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    cout << searchRotated(arr, n, x);

    return 0;
}