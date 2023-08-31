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

void printCLL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << "->";
    for (Node *p = head->next; p != head; p = p->next)
    {
        cout << p->data << "->";
    }
}

Node *insertAtHead(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return temp;
}

Node *insertEfficientAtHead(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    swap(head->data, temp->data);
    return head;
}

Node *insertAtTail(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    swap(head->data, temp->data);
    return temp;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    swap(head->data, head->next->data);
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    // printCLL(head);
    head = insertAtHead(head, 5);
    // printCLL(head);
    head = insertEfficientAtHead(head, 0);
    head = insertAtTail(head, 35);
    // printCLL(head);
    head = deleteHead(head);
    printCLL(head);
    return 0;
}