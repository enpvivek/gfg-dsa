#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void previousSmaller(int arr[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << st.top() << " ";
        }
        st.push(i);
    }
}

void nextSmaller(int arr[], int n)
{
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            cout << n << " ";
        }
        else
        {
            cout << st.top() << " ";
        }
        st.push(i);
    }
}

int largestRectArea(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_area = 0;
        int x = i, y = i, l = 1;
        while (x > 0 && arr[x - 1] >= arr[i])
        {
            x--;
            l++;
        }
        while (arr[y + 1] >= arr[i] && y < n - 1)
        {
            y++;
            l++;
        }
        curr_area = arr[i] * l;
        cout << arr[i] << " " << l << endl;
        res = max(res, curr_area);
    }
    return res;
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
    previousSmaller(arr, n);
    cout << endl;
    nextSmaller(arr, n);

    return 0;
}