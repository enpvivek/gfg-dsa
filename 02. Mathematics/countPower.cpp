#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int power(int x, int n)
{
    int res = 1;
    if (n == 0)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        res *= x;
    }
    return res;
}

int findPower(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int temp = findPower(x, n / 2);
    temp = temp * temp;
    if (n % 2 == 0)
    {
        return temp;
    }
    else
    {
        return temp * x;
    }
}

int getPower(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            res = res * x;
        }
        x = x * x;
        n = n / 2;
    }
    return res;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << getPower(x, n);

    return 0;
}