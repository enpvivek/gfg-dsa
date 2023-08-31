#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isPalindrome(int n)
{
    string s = to_string(n);
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            return false;
        }
        i++;
    }
    return true;
}

int reverseNumber(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}

int main()
{
    int n;
    cin >> n;
    (n == reverseNumber(n)) ? cout << "Yes" << endl : cout << "No" << endl;
    // cout << isPalindrome(n);
    return 0;
}