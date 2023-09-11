#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

int maxActivity(vector<pair<int, int>> &vp)
{
    sort(vp.begin(), vp.end(), cmp);
    int res = 0, maxLen = 0;

    for (int i = 0; i < vp.size(); i++)
    {
        maxLen = max(maxLen, vp[i].first);
    }

    vector<int> resArr(maxLen + 1, -1);

    for (int i = 0; i < vp.size(); i++)
    {
        int j = vp[i].first;
        while (j > 0 && resArr[j] != -1)
        {
            j--;
        }
        if (j != 0)
        {
            resArr[j] = i;
        }
    }

    for (int i = 1; i <= maxLen; i++)
    {
        if (resArr[i] != -1)
        {
            res += vp[resArr[i]].second;
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

    return 0;
}
