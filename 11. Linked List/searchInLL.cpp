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

Node *insertAtTail(Node *head, int x)
{
    Node *temp = new Node(x);
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
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
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
    delete curr->next;
    curr->next = NULL;
    return head;
}

Node *insertInLL(Node *head, int pos, int x)
{
    Node *temp = new Node(x);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int searchInLL(Node *head, int x)
{
    int pos = 1;
    while (head != NULL)
    {
        if (head->data == x)
        {
            return pos;
        }
        head = head->next;
        pos++;
    }
    return -1;
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
    head = insertAtTail(head, 30);
    printLL(head);
    head = insertInLL(head, 3, 20);
    printLL(head);
    cout << searchInLL(head, 30);

    return 0;
}