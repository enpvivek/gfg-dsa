#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void leftMostRepeating(string s)
{

    int count[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] > 1)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
}

int leftMostRepeatingChar(string s)
{

    int count[256] = {-1};
    for (int i = 0; i < 256; i++)
    {
        count[i] = -1;
    }
    int res = INT_MAX;
    for (int i = 0; i < s.length(); i++)
    {
        int fi = count[s[i]];
        if (count[s[i]] == -1)
        {
            count[s[i]] = i;
        }
        else
        {
            res = min(res, fi);
        }
    }
    return (res == INT_MAX) ? (-1) : res;
}

int main()
{

    string s;
    cin >> s;

    leftMostRepeating(s);

    return 0;
}