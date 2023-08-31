#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void sieve(int n)
{
    vector<bool> vb(n + 1, true);
    for (int i = 2; i * i < n; i++)
    {
        if (vb[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                vb[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (vb[i] == true)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    return 0;
}