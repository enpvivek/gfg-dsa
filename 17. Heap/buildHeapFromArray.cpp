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
    void heapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = 0;
        if (lt < size && arr[lt] < arr[i])
        {
            smallest = lt;
        }
        if (rt < size && arr[rt] < arr[smallest])
        {
            smallest = rt;
        }
        if (smallest != 0)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    int extractMin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        int temp = arr[0];
        arr[0] = arr[size - 1];
        heapify(0);
        return temp;
    }
    void decreaseKey(int idx, int key)
    {
        if (idx > size)
            return;
        arr[idx] = key;
        while (idx != 0 && arr[idx] < arr[parent(idx)])
        {
            swap(arr[idx], arr[parent(idx)]);
            idx = parent(idx);
        }
    }
    void deleteKey(int i)
    {
        swap(arr[i], arr[size - 1]);
        size--;
        heapify(i);
    }
    void deleteKey2(int i)
    {
        if (i >= size)
        {
            return; // Invalid index
        }
        decreaseKey(i, INT_MIN); // Decrease the key at index 'i' to the minimum value
        extractMin();            // Remove the minimum element, which is now at index 'i'
    }
    void buildHeap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            heapify(i);
        }
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
    h.decreaseKey(3, 9);
    h.seeMin();

    return 0;
}