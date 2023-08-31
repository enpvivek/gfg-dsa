#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void previousGreaterElem(int arr[], int n)
{
    stack<int> st;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        res = st.empty() ? (-1) : (arr[st.top()]);
        cout << res << " ";
        st.push(i);
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
    previousGreaterElem(arr, n);

    return 0;
} 