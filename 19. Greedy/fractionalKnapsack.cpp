#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = a.second / a.first;
    double r2 = b.second / b.first;
    return r1 > r2;
}

int maxValue(vector<pair<int, int>> &vp, int cap)
{
    sort(vp.begin(), vp.end(), cmp);
    int res = 0;
    int i = 0;
    while (i < vp.size() && cap > 0)
    {
        if (vp[i].first < cap)
        {
            res += vp[i].second;
            cap -= vp[i].first;
        }
        else
        {
            res += (vp[i].second / vp[i].first) * cap;
            cap = 0;
        }
        i++;
    }
    return res;
}

int main()
{
    int n, cap;
    cin >> n >> cap;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    cout << maxValue(vp, cap) << endl;
    ;
    return 0;
}