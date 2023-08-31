#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int intersectionArr(int arr1[], int arr2[], int m, int n)
{
    int count = 0;
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr2[i]) != s.end())
        {
            count++;
            s.erase(arr2[i]);
        }
    }
    return count;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int arr1[m];
    int arr2[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    cout << intersectionArr(arr1, arr2, m, n);

    return 0;
}