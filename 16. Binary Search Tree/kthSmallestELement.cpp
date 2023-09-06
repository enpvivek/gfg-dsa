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

Node *kthSmallest(Node *root, int k)
{
    if (root == NULL)
        return NULL;
    if (root->lcount == k)
    {
        return root;
    }
    else if (root->lcount > k)
    {
        return kthSmallest(root->left, k);
    }
    else
    {
        return kthSmallest(root->right, k - root->lcount - 1);
    }
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

    int k;
    cin >> k;

    Node *kthNode = kthSmallest(root, k);
    if (kthNode != NULL)
    {
        cout << "Kth smallest element: " << kthNode->key << endl;
    }
    else
    {
        cout << "Invalid k value" << endl;
    }
    return 0;
}