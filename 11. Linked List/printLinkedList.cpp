#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
}
void printLLRecursive(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }

    cout << curr->data << "->";
    printLL(curr->next);
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    printLL(head);
    return 0;
}