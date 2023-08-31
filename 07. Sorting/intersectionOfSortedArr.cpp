#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void intersection(int A[], int B[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && A[i] == A[i - 1])
        {
            i++;
        }
        else if (j > 0 && B[j] == B[j - 1])
        {
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else if (A[i] == B[j])
        {
            cout << A[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    int A[m];
    int B[n];
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> B[j];
    }

    intersection(A, B, m, n);

    return 0;
}