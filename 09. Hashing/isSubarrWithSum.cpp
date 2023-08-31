#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isSum(int arr[], int n, int sum)
{
    int preSum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (s.find(preSum - sum) != s.end())
        {
            return true;
        }
        if (preSum == sum)
        {
            return true;
        }
        s.insert(preSum);
    }
    return false;
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
    isSum(arr, n, sum) ? (cout << "YES" << endl) : (cout << "NO" << endl);

    return 0;
}