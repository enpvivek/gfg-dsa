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

bool isBalancedTree(Node *root)
{
    if (root == NULL)
        return true;
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    return abs(lh - rh) <= 1 && isBalancedTree(root->left) && isBalancedTree(root->right);
}

int isBalancedEfficient(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalancedEfficient(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalancedEfficient(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

int maxWidthTree(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int maxWidth = 1;
    while (!q.empty())
    {
        int size = q.size();
        maxWidth = max(maxWidth, size);
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
    return maxWidth;
}

void spiralTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    stack<Node *> st;
    q.push(root);
    bool reverse = true;
    while (!q.empty())
    {
        int size = q.size();
        reverse = !reverse;
        while (size--)
        {
            Node *curr = q.front();
            q.pop();
            if (reverse)
            {
                st.push(curr);
            }
            else
            {
                cout << curr->key << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        if (reverse)
        {
            while (!st.empty())
            {
                cout << st.top()->key << " ";
                st.pop();
            }
        }
    }
}

void spiralStackLevelOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            if (s1.top()->left != NULL)
            {
                s2.push(s1.top()->left);
            }
            if (s1.top()->right != NULL)
            {
                s2.push(s1.top()->right);
            }
            cout << s1.top()->key << " ";
            s1.pop();
        }
        while (!s2.empty())
        {
            if (s2.top()->right != NULL)
            {
                s1.push(s2.top()->right);
            }
            if (s2.top()->left != NULL)
            {
                s1.push(s2.top()->left);
            }
            cout << s2.top()->key << " ";
            s2.pop();
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
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
    if (isBalancedEfficient(root) == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    cout << maxWidthTree(root) << endl;
    spiralTraversal(root);
    cout << endl;
    spiralStackLevelOrder(root);
    cout << endl;

    return 0;
}