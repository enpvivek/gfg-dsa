#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct TwoStacks
{
    int *arr;
    int cap;
    int top1;
    int top2;
    TwoStacks(int n)
    {
        cap = n;
        top1 = -1;
        top2 = n;
        arr = new int[n];
    }
    void push1(int x)
    {
        if (top1 >= top2)
        {
            return;
        }
        top1++;
        arr[top1] = x;
    }
    void push2(int x)
    {
        if (top1 >= top2)
        {
            return;
        }
        top2--;
        arr[top2] = x;
    }
    void pop1()
    {
        if (top1 < 0)
        {
            return;
        }
        top1--;
    }
    void pop2()
    {
        if (top2 > cap - 1)
        {
            return;
        }
        top2++;
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}