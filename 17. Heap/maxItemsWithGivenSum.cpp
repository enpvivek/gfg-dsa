#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int purchasingMaxItems(int arr[], int n, int sum)
{
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    while (!pq.empty() && sum >= 0)
    {
        if (pq.top() <= sum)
        {
            sum -= pq.top();
            res++;
            pq.pop();
        }
        else
        {
            return res;
        }
    }
    return res;
}

int items(int arr[], int n, int sum)
{
    int res = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sum)
        {
            res++;
            sum -= arr[i];
        }
        else
        {
            return res;
        }
    }
    return res;
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << purchasingMaxItems(arr, n, sum);

    return 0;
}