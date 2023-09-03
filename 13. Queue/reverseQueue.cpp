#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void reverseQueue(queue<int> q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while (!q.empty())
    {
        std::cout << q.front() << " "; // Print the front element
        q.pop();                       // Remove the front element
    }
}

void recursivelyReverseQueue(queue<int> q)
{
    if (q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    recursivelyReverseQueue(q);
    q.push(x);
}

int main()
{
    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    myQueue.push(60);

    reverseQueue(myQueue);

    return 0;
}