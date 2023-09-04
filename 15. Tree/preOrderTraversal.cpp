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

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    preOrderTraversal(root);

    return 0;
}