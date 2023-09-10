#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void addEdgeDirected(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
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
    bool visited[n] = {false};
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
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            bfs(arr, n, i, visited);
        }
    }
    cout << endl;
}

void dfsRec(vector<int> arr[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto it : arr[s])
    {
        if (visited[it] == false)
        {
            dfsRec(arr, it, visited);
        }
    }
}

void dfs(vector<int> arr[], int s, int n)
{
    bool visited[n] = {false};
    dfsRec(arr, s, visited);
    cout << endl;
}

void shortestPath(vector<int> arr[], int s, int n)
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = -1;
    }
    dist[s] = 0;
    bool visited[n] = {false};
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it : arr[u])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                dist[it] = u + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

bool isUndirectedCyclicBFSHelper(vector<int> arr[], int s, int n, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> parent(n, -1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it : arr[u])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
                parent[it] = u;
            }
            else if (parent[u] != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool isUndirectedCyclicBFS(vector<int> arr[], int n)
{
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            if (isUndirectedCyclicBFSHelper(arr, i, n, visited) == true)
            {
                return true;
            };
        }
    }
    return false;
}

bool dfsHelper(vector<int> arr[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto it : arr[s])
    {
        if (visited[it] == false)
        {
            dfsHelper(arr, it, visited, s);
        }
        else if (parent != it)
        {
            return true;
        }
    }
    return false;
}

bool checkCircularUndirectedDFS(vector<int> arr[], int n)
{
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            if (dfsHelper(arr, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

bool dfsDirectedHelper(vector<int> arr[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for (auto it : arr[s])
    {
        if (visited[it] == false)
        {
            if (dfsDirectedHelper(arr, it, visited, recSt) == true)
            {
                return true;
            }
        }
        else if (recSt[it] == true)
        {
            return true;
        }
    }
    return false;
}

bool isCyclicDirectedDFS(vector<int> arr[], int n)
{
    bool visited[n] = {false};
    bool recSt[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            if (dfsDirectedHelper(arr, i, visited, recSt) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void topoligicalSort(vector<int> arr[], int n)
{
    int indegree[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (auto it : arr[i])
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
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : arr[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

int main()
{
    // Create an array of vectors to represent the graph
    int V = 8; // Number of vertices
    vector<int> adj[V];
    addEdgeDirected(adj, 0, 1);
    addEdgeDirected(adj, 1, 3);
    addEdgeDirected(adj, 1, 4);
    addEdgeDirected(adj, 2, 4);
    addEdgeDirected(adj, 2, 5);
    addEdgeDirected(adj, 2, 7);
    addEdgeDirected(adj, 3, 6);
    addEdgeDirected(adj, 4, 6);
    addEdgeDirected(adj, 4, 7);
    addEdgeDirected(adj, 5, 7);
    topoligicalSort(adj, V);

    return 0;
}
