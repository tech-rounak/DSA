#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int n)
    {
        data = n;
        next = NULL;
        prev = NULL;
    }
} *head = NULL;
void Insert_doubly_linked_list_last(int n)
{
    Node *tmp = new Node(n);
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        Node *i = head;
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = tmp;
        tmp->prev = i;
    }
}
void Insert_doubly_linked_list_begin(int n)
{
    Node *tmp = new Node(n);
    if (head == NULL)
    {
        head = tmp;
        head->prev = tmp;
    }
    else
    {
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
}

void print_double_linked_list()
{
    Node *i = head;
    while (i != NULL)
    {
        cout << i->data << " ";
        i = i->next;
    }
    cout << endl;
}
void delete_head()
{
    if (head == NULL || head->next == NULL)
        cout << "NULL\n";
    Node *tmp = head;
    head = head->next;
    head->prev = NULL;
    delete (tmp);
}
void delete_tail()
{
    if (head == NULL || head->next == NULL)
        cout << "NULL\n";
    Node *i = head;
    while (i->next != NULL)
        i = i->next;
    

    i->prev->next = NULL;
    delete (i);

    // head->prev = NULL;
}
void reverse()
{
    if (head == NULL || head->next == NULL)
        return;
    Node *i = head, *tmp;
    while (i != NULL)
    {
        tmp = i->prev;
        i->prev = i->next;
        i->next = tmp;

        i = i->prev;
    }
    head = tmp->prev;
}
int main()
{
    Insert_doubly_linked_list_last(23);
    Insert_doubly_linked_list_last(34);
    Insert_doubly_linked_list_last(232);
    Insert_doubly_linked_list_begin(455);
    Insert_doubly_linked_list_begin(453);
    Insert_doubly_linked_list_begin(53);
    Insert_doubly_linked_list_begin(43);
    Insert_doubly_linked_list_begin(435);
    print_double_linked_list();
    // reverse();
    delete_tail();
    // cout << head->next << " ";
    // cout << head->prev << " ";
    print_double_linked_list();
}