#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MyStack
{
    vector<int> v;
    int top;
    void push(int x)
    {
        top = 0;
        v.push_back(x);
    }
    void pop()
    {
        if (top == -1)
        {
            return;
        }
        v.pop_back();
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            return -1;
        }
        return v[top];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    MyStack s;
    s.push(10);
    cout << s.size();
    cout << s.peek();

    return 0;
}