#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isPalindrome(string s)
{
    int start = 0, end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++, end--;
    }
    return true;
}

int main()
{

    string s;
    cin >> s;

    isPalindrome(s) ? (cout << "palindrome") : (cout << "not Palindrome");

    return 0;
}