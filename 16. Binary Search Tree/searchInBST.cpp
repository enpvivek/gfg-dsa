#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

bool searchInBST(Node *root, int x)
{
    if (root == NULL)
        return false;

    else if (root->key == x)
    {
        return true;
    }
    else if (root->key < x)
    {
        return searchInBST(root->right, x);
    }
    else
    {
        return searchInBST(root->left, x);
    }
}

bool searchIterative(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
        {
            return true;
        }
        else if (root->key < x)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    return 0;
}