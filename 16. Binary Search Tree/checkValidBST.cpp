#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int lcount;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
        lcount = 0;
    }
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    if (data > root->key)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->lcount++;
        root->left = insert(root->left, data);
    }
    return root;
}

bool isBST(Node *root, int minr = INT_MIN, int maxr = INT_MAX)
{
    if (root == NULL)
        return true;
    return ((root->key < maxr) && (root->key > minr) &&
            (isBST(root->left, minr, root->key)) &&
            (isBST(root->right, root->key, maxr)));
}

bool inorderIsBST(Node *root, Node *prev = NULL)
{
    if (root == NULL)
        return true;
    if (inorderIsBST(root->left, prev) == false)
    {
        return false;
    }
    if (root->key < prev->key)
    {
        return false;
    }
    prev = root;
    return inorderIsBST(root->right, prev);
}

int main()
{
    int n;
    cin >> n;

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    return 0;
}