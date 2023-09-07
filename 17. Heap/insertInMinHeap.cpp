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
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void insert(int x)
    {
        if (size == cap)
        {
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void seeMin()
    {
        cout << arr[0] << endl;
    }
    
};

int main()
{
    int n;
    cin >> n;
    minHeap h(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.insert(x);
    }
    h.seeMin();

    return 0;
}