#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MinMaxDS
{
    deque<int> dq;
    void insertMax(int x)
    {
        dq.push_back(x);
    }
    void insertMin(int x)
    {
        dq.push_front(x);
    }
    int getMin(int x)
    {
        return dq.front();
    }
    int getMax(int x)
    {
        return dq.back();
    }
    void extractMin(int x)
    {
        dq.pop_front();
    }
    void extractMax(int x)
    {
        dq.pop_back();
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}