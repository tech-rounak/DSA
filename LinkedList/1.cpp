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
void InsertAtBeginning(int n)
{
    Node *tmp = new Node(n);
    tmp->next = head;
    head = tmp;
}
void InsertAtEnd(int n)
{
    Node *i;

    if (head == NULL)
    {
        head = new Node(n);
    }
    else
    {
        i = head;
        while (i->next != NULL)
            i = i->next;
        i->next = new Node(n);
    }
}
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
void PrintLinkedListRecurssive(Node *head)
{
    if (head == NULL)
    {
        cout << " NULL" << endl;
        return;
    }
    else
    {
        cout << head->data << " ";
        PrintLinkedListRecurssive(head->next);
    }
}
void SearchInALinkedList(Node *head, int x, int pos)
{
    if (head->next == NULL)
    {
        cout << "Not Found " << endl;
        return;
    }
    else if (head->data == x)
    {
        cout << "Found at positon :" << pos << endl;
        return;
    }
    else
        SearchInALinkedList(head->next, x, pos + 1);
}

void InsertAtAnyPosition(int n, int pos)
{
    Node *i = head;
    int cnt = 0;
    while (i != NULL)
    {
        i = i->next;
        cnt++;
    }
    if (pos == 1)
        InsertAtBeginning(n);
    else if (pos >= cnt + 1)
        InsertAtEnd(n);
    else
    {
        int cnt = 1;
        i = head;
        Node *tmp = new Node(n);
        while (i->next != NULL && cnt < pos - 1)
        {
            i = i->next;
            cnt++;
        }
        tmp->next = i->next;
        i->next = tmp;
    }
}
void Delete_Any_Pos(int pos)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty";
    }
    Node *i = head, *tmp;
    int cnt = 1;

    // tmp=i;
    while (i->next != NULL && cnt < pos)
    {
        // cout<<" "
        tmp = i;
        i = i->next;
        cnt++;
    }
    if (pos == 1)
    {
        head = head->next;

        free(i);
    }
    else
    {
        tmp->next = i->next;
        free(i);
    }
}
void Insert_Sorted(int n)
{
    // int pos = 1;
    Node *tmp = new Node(n);
    if (head == NULL)
    {
        tmp->next = head;
        head = tmp;
    }
    else if (n < head->data)
    {
        // cout << head->data << " ";
        tmp->next = head;
        head = tmp;
    }
    else
    {
        int cnt = 1;
        Node *i = head;
        while (i->next != NULL && n < i->next->data)
        {
            i = i->next;
        }
        if (i->next != NULL)
        {
            // cout << i->data << "=== ";
            tmp->next = i->next;
            i->next = tmp;
        }
        else
        {
            //cout << i->data << "=== ";
            tmp->next = NULL;
            i->next = tmp;
        }
    }
    // return tmp;
}
void middle_element()
{
    Node *slow = head, *fast = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL)
            break;
    }
    cout << slow->data << " ";
}
void find_nth_node_from_end(int n)
{
    Node *fi = head, *se = head;
    for (int i = 1; i < n && fi != NULL; i++)
    {
        fi = fi->next;
    }
    if (fi == NULL)
    {
        cout << "NOT PRESENT";
    }
    while (fi->next != NULL)
    {
        se = se->next;
        fi = fi->next;
    }
    cout << se->data;
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
    {
        int ele = rand() % 100;
        InsertAtEnd(ele);
        // cout << ele << "- ";
    }
    PrintLinkedList(head);
    find_nth_node_from_end(41);
    cout << endl;
}
