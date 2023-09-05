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

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->key << " ";
}

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

void printKthNode(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->key << " ";
    }
    printKthNode(root->left, k - 1);
    printKthNode(root->right, k - 1);
}

void levelOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->key << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        delete temp;
        q.pop();
    }
}

void levelOrderByLine(Node *&root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << temp->key << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int maxElem(Node *root)
{
    if (root == NULL)
        return 0;

    return max(root->key, max(maxElem(root->left), maxElem(root->right)));
}

void printLeftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        // Process the first node of each level (leftmost node)
        cout << q.front()->key << " ";
        while (size--)
        {
            Node *current = q.front();
            q.pop();
            // Push the left child into the queue if it exists
            if (current->left != NULL)
                q.push(current->left);
            // Push the right child into the queue if it exists
            if (current->right != NULL)
                q.push(current->right);
        }
    }
}

int maxLevel = 0;

void printLeft(Node *root, int level)
{
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void printLeftRecursively(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        cout << q.front()->key << " ";
        while (size--)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

bool childrenSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->key;
    }
    if (root->right != NULL)
    {
        sum += root->right->key;
    }

    return ((root->key == sum) && childrenSum(root->left) && childrenSum(root->right));
}

int main()
{
    Node *root = new Node(120);
    root->left = new Node(90);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(30);
    inOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << heightOfTree(root) << endl;
    printKthNode(root, 2);
    cout << endl;
    // levelOrderTraversal(root);
    // levelOrderByLine(root);
    cout << getSize(root) << endl;
    cout << maxElem(root) << endl;
    printLeftView(root);
    cout << endl;
    printLeft(root, 1);
    cout << endl;
    printLeftRecursively(root);
    cout << endl;
    childrenSum(root) ? (cout << "YES" << endl) : (cout << "NO" << endl);

    return 0;
}