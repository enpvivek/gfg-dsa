#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void printList(vector<int> arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (auto it : arr[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    vector<int> arr[n];
    addEdge(arr, 0, 1);
    addEdge(arr, 0, 2);
    addEdge(arr, 1, 2);
    addEdge(arr, 1, 3);
    printList(arr, n);

    return 0;
}