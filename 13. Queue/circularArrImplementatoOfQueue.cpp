#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MyQueue
{
    int *arr;
    int front;
    int size;
    int cap;
    MyQueue(int n)
    {
        cap = n;
        front = 0;
        size = 0;
        arr = new int[cap];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == cap;
    }
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return front;
        }
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return (front + size - 1) % cap;
        }
    }
    void queue(int x)
    {
        if (isFull())
        {
            return;
        }
        int rear = getRear();
        (size + front - 1) % cap;
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}