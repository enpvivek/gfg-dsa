#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void freqInSortedArr(int arr[], int n)
{
    int freqCount = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] != arr[i])
        {
            // freqCount++;
            cout << arr[i] << " : " << freqCount << endl;
            freqCount = 1;
        }
        else
        {
            freqCount++;
        }
    }
    cout << arr[n - 1] << " : " << freqCount << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    freqInSortedArr(arr, n);

    return 0;
} 