#include <bits/stdc++.h>
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
} *head = NULL;

void PrintLinkedList(Node *head)
{
    Node *i = head;
    while (i != NULL)
    {
        cout << i->data << " ";
        i = i->next;
    }
    cout << "NULL" << endl;
}

void Insert_Sorted(int n)
{
    // int pos = 1;
    Node *tmp = new Node(n);
    if (head == NULL || n < head->data)
    {
        tmp->next = head;
        head = tmp;
    }

    else
    {
        int cnt = 1;
        Node *i = head;
        while (i->next != NULL && n >= i->next->data)
        {
            i = i->next;
        }
        tmp->next = i->next;
        i->next = tmp;
    }
}
Node *Recursive_reverse(Node *head, Node *prev)
{
    if (head == NULL)
        return prev;

    Node *tmp = head->next;
    head->next = prev;
    return Recursive_reverse(tmp, head);
}

void reverse()
{
    Node *curr, *prev = NULL, *next;
    curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int ele = rand() % 100;
        Insert_Sorted(ele);
        // cout << ele << "- ";
    }
    PrintLinkedList(head);
    Node *tmp = Recursive_reverse(head, NULL);
    PrintLinkedList(tmp);

    cout << endl;
}
