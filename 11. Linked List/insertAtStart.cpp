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
void printLL(Node *curr)
{
    if (curr == NULL)
    {
        cout << endl;
        return;
    }

    cout << curr->data << "->";
    printLL(curr->next);
}

Node *insertAtHead(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    printLL(head);
    Node *head2 = NULL;
    head2 = insertAtHead(head2, 1);
    printLL(head2);
    return 0;
}