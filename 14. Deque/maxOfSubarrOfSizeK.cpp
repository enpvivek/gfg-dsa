#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void maxOfSubarr(int arr[], int n, int k)
{

    for (int i = 0; i < n - k + 1; i++)
    {
        int res = 0;
        for (int j = i; j < i + k; j++)
        {
            res = max(arr[j], res);
        }
        cout << res << " ";
    }
}

void printKMax(int arr[], int n, int k)
{

    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_back();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << endl;
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

    printKMax(arr, n, k);

    return 0;
}