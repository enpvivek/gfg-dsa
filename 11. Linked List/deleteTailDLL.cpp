#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

Node *insertAtHead(Node *head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    head->prev = temp;
    return temp;
}

Node *insertAtTail(Node *head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

Node *deleteHeadDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    head->prev = NULL;
    return head;
}

Node *deleteTailDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    delete temp;
    curr->next = NULL;
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = insertAtHead(head, 5);
    head = insertAtTail(head, 35);
    head = reverseDLL(head);
    head = reverseDLL(head);
    head = deleteHeadDLL(head);
    head = deleteTailDLL(head);
    printDLL(head);

    return 0;
}