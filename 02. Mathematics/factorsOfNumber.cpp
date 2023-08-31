#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void printFactors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

void findFactors(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
            {
                cout << n / i << " ";
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    findFactors(n);
    return 0;
}