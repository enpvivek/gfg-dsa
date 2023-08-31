#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool checkPalindrome(string s, int x)
{
    if (x >= s.length() / 2)
    {
        return true;
    }
    return (s[x] == s[s.length() - x - 1]) && checkPalindrome(s, x + 1);
}

int main()
{
    string s;
    cin >> s;
    (checkPalindrome(s, 0)) ? (cout << "Yes" << endl) : (cout << "No" << endl);

    return 0;
}