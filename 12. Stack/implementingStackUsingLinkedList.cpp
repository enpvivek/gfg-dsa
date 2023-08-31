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

struct MyStack
{
    Node *head;
    int size;
    MyStack()
    {
        head = NULL;
        size = 0;
    }
    void push(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        temp = head;
        size++;
    }
    void pop()
    {
        Node *temp = head;
        head = head->next;
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
    int peek()
    {
        return head->data;
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}