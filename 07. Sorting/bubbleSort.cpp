#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void bubbleSort(int arr[], int n)
{
    int x = n;
    while (x--)
    {
        for (int i = 1; i <= x; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
    }
    return;
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

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}