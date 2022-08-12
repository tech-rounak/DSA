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
void insert_at_end(int n)
{
    Node *tmp = new Node(n);
    if (head == NULL)
    {
        head = tmp;
        tmp->next = head;
        return;
    }
    else
    {
        tmp->next = head->next;
        head->next = tmp;
        int x = tmp->data;
        tmp->data = head->data;
        head->data = x;
        head = head->next;
    }
}
void print_ll()
{
    Node *curr = head;
    // cout << head<< " ";
    while (curr->next != head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << curr->data << " ";
    cout << endl;
}
void insert_at_begin(int n)
{
    Node *tmp = new Node(n);
    if (head == NULL)
    {
        head = tmp;
        tmp->next = head;
    }
    else
    {
        // adding tmp to second pos && swapp the first node with second;
        tmp->next = head->next;
        head->next = tmp;
        int x = tmp->data;
        tmp->data = head->data;
        head->data = x;
    }
}
void delete_head()
{
    if (head == NULL || head->next == NULL)
        delete (head);
    else
    {
        Node *tmp = head->next;
        head->data = head->next->data;
        head->next = head->next->next;
        delete (tmp);
        // free(tmp);
    }
}
int main()
{
    srand(time(NULL));
    // for (int i = 0; i < 15; i++)
    // {
    //     insert_at_end(rand() % 100);
    // }
    // print_ll();
    insert_at_end(45);
    insert_at_end(232);
    insert_at_end(2382);
    delete_head();
    print_ll();
}