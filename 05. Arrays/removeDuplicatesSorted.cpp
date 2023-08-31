#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int pos = 0;
    int curr = 0;
    int nxt = 1;
    while (nxt < n)
    {
        if (arr[curr] != arr[nxt])
        {
            arr[pos] = arr[curr];
            pos++;
            curr = nxt;
            nxt++;
        }
        else
        {
            nxt++;
        }
    }
    if (arr[pos] != arr[n - 1])
    {
        arr[pos] = arr[curr];
        return pos + 1;
    }
    else
    {
        return pos;
    }
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
    int pos = removeDuplicates(arr, n);
    for (int i = 0; i < pos; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}