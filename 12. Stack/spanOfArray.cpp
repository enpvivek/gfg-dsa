#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void printSpan(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] >= arr[j])
            {
                span++;
            }
            else if (arr[i] < arr[j])
            {
                span = 0;
            }
        }
        cout << span << " ";
    }
}

void printSpanStack(int arr[], int n)
{
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push({arr[i], i + 1});
            cout << 1 << " ";
        }
        else
        {
            while (!st.empty() && arr[i] > st.top().first)
            {
                st.pop();
            }
            if (st.empty())
            {
                st.push({arr[i], i + 1});
                cout << i + 1 << " ";
            }
            else
            {
                cout << i - st.top().second + 1 << " ";
                st.push({arr[i], i + 1});
            }
        }
    }
}

void printSpanSt(int arr[], int n)
{
    stack<int> st;
    int span = 0;
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (st.empty() == false && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        span = st.empty() ? (i + 1) : (i - st.top() + 1);
        cout << span << " ";
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
    printSpanStack(arr, n);

    return 0;
}