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

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->key << " ";
    inOrderTraversal(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    inOrderTraversal(root);

    return 0;
}