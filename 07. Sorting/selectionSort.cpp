#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void selectionSort(int arr[], int n)
{
    int x = 0;
    while (x < n)
    {
        int minIDX = x;
        for (int i = x + 1; i < n; i++)
        {
            if (arr[i] < arr[minIDX])
            {
                minIDX = i;
            }
        }
        swap(arr[minIDX], arr[x]);
        x++;
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

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}