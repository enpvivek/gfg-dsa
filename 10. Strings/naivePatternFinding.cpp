#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void patternPrint(string s, string p)
{
    for (int i = 0; i <= s.length() - p.length(); i++)
    {
        string x = s.substr(i, p.length());
        if (x == p)
        {
            cout << i << " ";
        }
    }
}

void findPattern(string s, string p)
{
    for (int i = 0; i <= s.length() - p.length(); i++)
    {
        for (int j = 0; j < p.length(); j++)
        {
            if (s[i + j] != p[j])
            {
                break;
            }
            if (j == p.length() - 1)
            {
                cout << i << " ";
            }
        }
    }
}

int main()
{

    string s, p;
    cin >> s >> p;
    findPattern(s, p);

    return 0;
}