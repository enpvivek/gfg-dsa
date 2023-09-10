#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void shortestPathDAG(vector<int> adj[], int s, int n)
{
    int indegree[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topSortArr;
    while (!q.empty())
    {
        int u = q.front();
        topSortArr.push_back(u);
        q.pop();
        for (auto it : adj[u])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    vector<int> minDist(n, INT_MAX);
    minDist[s] = 0;
    for (auto u : topSortArr)
    {
        for (auto v : adj[u])
        {
            // if (minDist[v] > minDist[u] + weight(u, v))
            // {
            //     minDist[v] = minDist[u] + weight(u, v);
            // }
        }
    }
    for (auto it : minDist)
    {
        cout << it << " ";
    }
}

int main()
{
    // make graph
    return 0;
}