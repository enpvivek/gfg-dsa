#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void prinCeil(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int res = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                res = min(arr[j], res);
            }
        }
        res == INT_MAX ? (cout << -1 << " ") : (cout << res << " ");
    }
}

void printLeftCeil(int arr[], int n)
{
    set<int> st;
    st.insert(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        auto nextIt = st.lower_bound(arr[i]);
        if (nextIt == st.end())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << *nextIt << " ";
        }
        st.insert(arr[i]);
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
    printLeftCeil(arr, n);

    return 0;
}           