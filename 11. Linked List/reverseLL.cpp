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
    cout << endl;
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

void printMiddle(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
}

void printNthFromEnd(Node *head, int n)
{
    if (head == NULL)
    {
        return;
    }
    int length = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    if (n > length)
    {
        return;
    }
    else
    {
        curr = head;
        for (int i = 1; i < length - n + 1; i++)
        {
            curr = curr->next;
        }
        cout << curr->data << endl;
    }
}

void printNthFromEndEfficient(Node *head, int n)
{
    if (head == NULL)
    {
        return;
    }
    Node *first = head;
    for (int i = 0; i < n; i++)
    {
        if (first->next == NULL)
        {
            return;
        }
        first = first->next;
    }
    Node *second = head;
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data << endl;
}

Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    head = sortedInsert(head, 35);
    printLL(head);
    printNthFromEnd(head, 3);
    printNthFromEndEfficient(head, 3);
    head = reverseLinkedList(head);
    printLL(head);

    return 0;
}