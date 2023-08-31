#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MyStack
{
    int *arr;
    int cap;
    int top;
    MyStack(int n)
    {
        cap = n;
        arr = new int[cap];
        top = -1;
    }
    void push(int n)
    {
        top++;
        arr[top] = n;
    }
    void pop()
    {
        arr[top] = 0;
        top--;
    }
    int size()
    {
        return top + 1;
    }
    int peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    MyStack s(5);
    s.push(10);
    cout << s.size();
    cout << s.peek();

    return 0;
}