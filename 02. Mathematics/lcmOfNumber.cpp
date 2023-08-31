#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int findLCM(int a, int b)
{
    int res = max(a, b);
    while (true)
    {
        if (res % a == 0 && res % b == 0)
        {
            return res;
        }
        res++;
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

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << LCM(a, b);

    return 0;
}