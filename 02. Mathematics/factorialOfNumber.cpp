#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int findFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * (findFactorial(n - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << findFactorial(n);

    return 0;
}