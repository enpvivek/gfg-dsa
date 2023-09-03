#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MyStack
{
    queue<int> q1, q2;
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return q1.size();
    }
    int pop()
    {
        q1.pop();
    }
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}