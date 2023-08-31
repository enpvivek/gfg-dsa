#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int countSet(int n)
{
    int res = 0;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            res++;
        }
        n = n / 2;
    }
    return res;
}

int countSetBits(int n)
{
    int res = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n);

    return 0;
}