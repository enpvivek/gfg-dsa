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

Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->key > x)
    {
        root->left = deleteInBST(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = deleteInBST(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            deleteInBST(root->right, succ->key);
        }
        return root;
    }
}

Node *findFLoor(Node *root, int x, Node *closestSoFar = NULL)
{
    if (root == NULL)
    {
        return closestSoFar;
    }
    if (root->key <= x)
    {
        if (closestSoFar == NULL || root->key > closestSoFar->key)
        {
            closestSoFar = root;
        }
    }
    closestSoFar = findFLoor(root->left, x, closestSoFar);
    closestSoFar = findFLoor(root->right, x, closestSoFar);
    return closestSoFar;
}

Node *floorInBST(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key > x)
        {
            root = root->left;
        }
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
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
    cout << findFLoor(root, 41)->key << endl;
    cout << floorInBST(root, 41)->key << endl;

    return 0;
}