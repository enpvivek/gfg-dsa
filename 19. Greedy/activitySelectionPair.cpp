#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxActivity(vector<pair<int, int>> &vp)
{
    sort(vp.begin(), vp.end(), cmp);
    int res = 1;
    int prev = vp[0].second;
    for (int i = 1; i < vp.size(); i++)
    {
        if (vp[i].first >= prev)
        {
            res++;
            prev = vp[i].second;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    cout << maxActivity(vp) << endl;
    ;
    return 0;
}