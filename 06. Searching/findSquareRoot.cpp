#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int sqRoot(int n)
{
    int low = 1, high = 2;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid * mid == n || (((mid + 1) * (mid + 1) > n) && (mid * mid < n)))
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            high = high * 2;
            low = mid;
        }
        else if (mid * mid > n)
        {
            high = mid;
            low = low;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    cout << sqRoot(n) << endl;

    return 0;
}