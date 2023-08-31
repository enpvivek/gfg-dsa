#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void reverseStr(string &s, int low, int high)
{
    while (low < high)
    {
        swap(s[low], s[high]);
        low++, high--;
    }
}

void reverseTheWords(string &s)
{
    int start = 0;
    for (int end = 0; end < s.length(); end++)
    {
        if (s[end] == ' ')
        {
            reverseStr(s, start, end - 1);
            start = end + 1;
        }
    }
    reverseStr(s, start, s.length() - 1);
    reverseStr(s, 0, s.length() - 1);
}

string reverseWords(string s)
{
    string b;
    string tmp = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] == ' ')
        {

            reverse(tmp.begin(), tmp.end());
            b += tmp;
            b += " ";
            tmp = "";
        }
        else if (i == 0)
        {
            tmp += s[i];
            reverse(tmp.begin(), tmp.end());
            b += tmp;
        }
        else
        {
            tmp += s[i];
            // cout << tmp;
        }
    }

    return b;
}

int main()
{

    string s;
    getline(cin, s);

    cout << reverseWords(s);

    return 0;
}