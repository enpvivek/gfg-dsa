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

void bfsTraversalOfTree(vector<int> arr[], int n, int start)
{
    queue<int> q;
    q.push(start);
    bool visited[n + 1] = {false};
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : arr[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    cout << endl;
}

void bfs(vector<int> arr[], int n, int s, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto it : arr[u])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

void bfsT(vector<int> arr[], int n)
{
    bool visited[n + 1] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            bfs(arr, n, i, visited);
        }
    }
    cout << endl;
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
    bfsTraversalOfTree(arr, n, 0);
    bfsT(arr, n);

    return 0;
}