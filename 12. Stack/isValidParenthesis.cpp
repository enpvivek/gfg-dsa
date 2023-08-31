#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool isValidParenthesis(stack<char> st, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if (s[i] == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            if (s[i] == ']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    isValidParenthesis(st, s) ? cout << "yes" : cout << "no";

    // while (!st.empty()) {
    //     cout << st.top() << ' ';
    //     st.pop();
    // }

    return 0;
}