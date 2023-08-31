#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int tralingZeroes(int n)
{
    if (n < 5)
    {
        return 0;
    }
    return n / 5 + tralingZeroes(n / 5);
}

int countTrailingZeroes(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << tralingZeroes(n);

    return 0;
}