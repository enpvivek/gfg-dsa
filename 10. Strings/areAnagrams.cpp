#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool areAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

bool areAnagrams(string s1, string s2)
{

    int count[256] = {0};
    if (s1.length() != s2.length())
    {
        return false;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string s1, s2;
    cin >> s1 >> s2;

    areAnagram(s1, s2) ? (cout << "Yes") : (cout << "No");

    return 0;
}