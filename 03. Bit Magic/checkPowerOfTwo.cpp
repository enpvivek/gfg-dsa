#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isPowerofTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    while (n != 1)
    {
        if (n % 2 != 0)
        {
            return false;
        }
        n = n / 2;
    }
    return true;
}

bool powTwo(int n)
{
    if (n == 0)
        return false;
    return ((n & (n - 1)) == 0);
}

int main()
{
    int n;
    cin >> n;
    powTwo(n) ? (cout << "Yes" << endl) : (cout << "NO" << endl);

    return 0;
}