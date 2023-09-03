#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct MyQueue
{
    Node *front;
    Node *rear;
    int size;
    MyQueue()
    {
        Node *front = NULL;
        Node *rear = NULL;
        size = 0;
    }
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        Node *temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getFront()
    {   
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}