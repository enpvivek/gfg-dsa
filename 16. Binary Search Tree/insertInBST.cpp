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

Node *insertInBST(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (root->key > x)
    {
        root->left = insertInBST(root->left, x);
    }
    else
    {
        root->right = insertInBST(root->right, x);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insertInBST(root, 40);
    root = insertInBST(root, 50);
    root = insertInBST(root, 30);
    root = insertInBST(root, 20);
    root = insertInBST(root, 40);
    root = insertInBST(root, 70);
    root = insertInBST(root, 60);
    root = insertInBST(root, 80);
    int x = 40;
    bool found = searchInBST(root, x);
    if (found)
    {
        cout << "Element " << x << " found in the BST" << endl;
    }
    else
    {
        cout << "Element " << x << " not found in the BST" << endl;
    }

    return 0;
}