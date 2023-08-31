#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void primeFactors(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i) == true)
        {
            int x = i;
            while (n % x == 0)
            {
                cout << i << " ";
                x = x * i;
            }
        }
    }
}

void findPrimeFactors(int n)
{
    if (n <= 1)
        return;
    for (int i = 2; i * i < n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n >= 2)
    {
        cout << n << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    findPrimeFactors(n);

    return 0;
}