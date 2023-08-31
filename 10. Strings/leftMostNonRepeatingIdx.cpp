#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int leftMostNonRepeating(string s)
{

    int count[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int leftMostNonRepeatingChar(string s)
{
    int res = INT_MAX;
    int count[256];
    for (int i = 0; i < 256; i++)
    {
        count[i] = -1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] == -1)
        {
            count[s[i]] = i;
        }
        else
        {
            count[s[i]] = -2;
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] >= 0)
        {
            res = min(res, count[i]);
        }
    }
    return res;
}

int main()
{

    string s;
    cin >> s;

    cout << leftMostNonRepeating(s);

    return 0;
}