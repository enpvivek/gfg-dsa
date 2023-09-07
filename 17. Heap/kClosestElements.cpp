#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void kclosest(int arr[], int n, int x, int k)
{
    bool visited[n] = {false};
    for (int i = 0; i < k; i++)
    {
        int minElem = INT_MAX, minIdx = -1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && abs(arr[j] - x) < minElem)
            {
                minElem = abs(arr[j] - x);
                minIdx = j;
            }
        }
        cout << arr[minIdx] << " ";
        visited[minIdx] = true;
    }
}

struct ComparePair
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
};

void kClosestElements(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({abs(arr[i] - x), i});
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < abs(arr[pq.top().second] - x))
        {
            pq.pop();
            pq.push({abs(arr[i] - x), i});
        }
    }
    while (!pq.empty())
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}
int main()
{
    int n, x, k;
    cin >> n >> x >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    kClosestElements(arr, n, x, k);
    return 0;
}