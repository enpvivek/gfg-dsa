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

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->key << " ";
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    postOrderTraversal(root);

    return 0;
}