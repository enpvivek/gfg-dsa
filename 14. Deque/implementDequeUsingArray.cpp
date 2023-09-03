#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MyDeque
{
    int *arr;
    int cap;
    int size;
    MyDeque(int n)
    {
        cap = n;
        size = -1;
        arr = new int[cap];
    }
    bool isEmpty()
    {
        return size == -1;
    }
    int getSize()
    {
        return size + 1;
    }
    void insertRear(int x)
    {
        size++;
        arr[size] = x;
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            return;
        }
        arr[size] = 0;
        size--;
    }
    void insertFront(int x)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = x;
        size++;
    }
    void deleteFront()
    {
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getFront()
    {
        return arr[0];
    }
    int getRear()
    {
        return arr[size - 1];
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}