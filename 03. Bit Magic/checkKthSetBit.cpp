#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if ((n && (1 << (k - 1))) != 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}