#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool areAnagrams(string &pat, string &txt, int i)
{
    int count[256] = {0};
    for (int j = 0; j < pat.length(); j++)
    {
        count[pat[j]]++;
        count[txt[i + j]]--;
    }
    for (int j = 0; j < 256; j++)
    {
        if (count[j] != 0)
        {
            return false;
        }
    }
    return true;
}

bool checkAnagram(string &txt, string &pat)
{
    for (int i = 0; i <= txt.length() - pat.length(); i++)
    {
        if (areAnagrams(pat, txt, i) == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s, t;
    cin >> s >> t;
    checkAnagram(s, t) ? cout << "yes" : cout << "No";
    return 0;
}