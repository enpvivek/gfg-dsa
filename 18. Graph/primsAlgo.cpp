#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int primsMST(vector<int> graph[], int V)
{
    int res = 0;
    int key[V];
    bool mSet[V];
    fill(key, key + V, INT_MAX);
    fill(mSet, mSet + V, false);
    key[0] = 0;
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mSet[u] = true;
        res += key[u];
        for (int v = 0; v < V; v++)
        {
            if ((graph[u][v] != 0) && (!mSet[v]))
            {
                key[v] = min(graph[u][v], key[v]);
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> graph[n];
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            graph[i][j] = x; // Fixed assignment operator from == to =
        }
    }

    cout << primsMST(graph, n);

    return 0;
}