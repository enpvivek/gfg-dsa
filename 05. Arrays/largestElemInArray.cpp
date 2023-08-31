#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int largestElem(int arr[], int n)
{
    int large = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    return large;
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

    cout << largestElem(arr, n);

    return 0;
}