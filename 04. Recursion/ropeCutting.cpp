#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int maxPieces(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }

    int res = max(max(maxPieces(n - a, a, b, c), maxPieces(n - b, a, b, c)), maxPieces(n - c, a, b, c));

    if (res == -1)
    {
        return -1;
    }
    return 1 + res;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << maxPieces(n, a, b, c);

    return 0;
}