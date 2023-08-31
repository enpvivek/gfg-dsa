#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void fillLPS(string s)
{
    int n = s.length();
    int lps[n];
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << lps[i] << " ";
    }
}

void buildLpsNew(string s)
{
    vector<int> lps;
    lps.push_back(0);
    for (int i = 1; i < s.length(); i++)
    {
        if (lps[i - 1] < s.length() && s[lps[i - 1]] == s[i])
        {
            lps.push_back(lps[i - 1] + 1);
        }
        else
        {
            if (s[0] == s[i])
            {
                lps.push_back(1);
            }
            else
            {
                lps.push_back(0);
            }
        }
    }
    for (auto it : lps)
    {
        cout << it << " ";
    }
}

void buildLps(string s)
{
    int n = s.length();
    vector<int> lps;

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // cout << s.substr(0, i - j) << " " << s.substr(j, i - j ) << " ";
            if (s.substr(0, i - j) == s.substr(j, i - j))
            {
                lps.push_back(i - j);
                break;
            }
        }
        cout << endl;
    }
    for (auto it : lps)
    {
        cout << it << " ";
    }
}

int main()
{

    string s;
    cin >> s;
    buildLps(s);

    return 0;
}