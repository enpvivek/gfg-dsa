#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct minHeap
{
    int *arr;
    int size;
    int cap;
    minHeap(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }
    int left(int i)
    {
        return arr[2 * i + 1];
    }
    int right(int i)
    {
        return arr[2 * i + 2];
    }
    int parent(int i)
    {
        return arr[(i - 1) / 2];
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}