#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isSumZero(int arr[], int n)
{
    int preSum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (s.find(preSum) != s.end())
        {
            return true;
        }
        if (preSum == 0)
        {
            return true;
        }
        s.insert(preSum);
    }
    return false;
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
    isSumZero(arr, n) ? (cout << "YES" << endl) : (cout << "NO" << endl);

    return 0;
}