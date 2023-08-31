#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int zeroestoEnd(int arr[], int n)
{
    int curr = 0;
    int nxt = 0;
    while (nxt < n)
    {
        if (arr[nxt] != 0)
        {
            arr[curr] = arr[nxt];
            curr++;
            nxt++;
        }
        else
        {
            nxt++;
        }
    }
    return curr;
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
    int pos = zeroestoEnd(arr, n);
    for (int i = 0; i < pos; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}