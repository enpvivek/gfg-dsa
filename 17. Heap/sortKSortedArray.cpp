#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void sortKth(int arr[], int n)
{
    sort(arr, arr + n);
}

void sortKthSortedArr(int arr[], int k, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }
    int idx = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[idx++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        arr[idx++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sortKthSortedArr(arr, k, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}