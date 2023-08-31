#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int longestSubarrWithSum(int arr[], int n, int sum)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == sum)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

int longestSubarrSum(int arr[], int n, int sum)
{
    int res = 0, preSum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == sum)
        {
            res = i + 1;
        }
        if (m.find(preSum - sum) == m.end())
        {
            m.insert({preSum, i});
        }
        if (m.find(preSum - sum) != m.end())
        {
            res = max(res, i - m[preSum - sum]);
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
    cout << longestSubarrSum(arr, n, sum) << endl;

    return 0;
}