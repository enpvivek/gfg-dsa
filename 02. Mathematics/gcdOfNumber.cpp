#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int findGCD(int a, int b)
{
    int res = min(a, b);
    while (res > 0)
    {
        if (a % res == 0 && b % res == 0)
        {
            return res;
        }
        res--;
    }
    return res;
}

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b);

    return 0;
}