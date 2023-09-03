#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int firstPetrolPump(int p[], int d[], int n)
{
    for (int start = 0; start < n; start++)
    {
        int curr_p = 0;
        int end = start;
        while (true)
        {
            curr_p += (p[end] - d[end]);
            if (curr_p < 0)
            {
                break;
            }
            end = (end + 1) % n;
            if (end == start)
            {
                return start + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int p[n];
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    cout << firstPetrolPump(p, d, n);

    return 0;
}