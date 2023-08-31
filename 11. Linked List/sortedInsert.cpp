#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printLL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}
Node *sortedInsert(Node *head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        return temp;
    }
    if (d < head->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while ((curr->next != NULL) && (curr->next->data < d))
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    printLL(head);
    head = sortedInsert(head, 45);
    printLL(head);

    return 0;
}