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
void Remove_Dup(Node *head)
{
    Node *curr = head;
    Node *tmp;
    while (curr->next != NULL && curr != NULL)
    {
        if (curr->data == curr->next->data)
        {
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
        }
        else
            curr = curr->next;
    }
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int ele = (i % 2 + 1) * 10;
        Insert_Sorted(ele);
        // cout << ele << "- ";
    }

    PrintLinkedList(head);
    Remove_Dup(head);
    PrintLinkedList(head);
    cout << endl;
}
