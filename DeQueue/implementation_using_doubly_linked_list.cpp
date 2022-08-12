#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
struct Deque
{
    Node *front, *rear;
    Node *head;
    int size;
    Deque(Node *x)
    {
        head = x;
        front = rear = NULL;
        size = 0;
    }
    void insertEnd(int x)
    {
        Node *tmp = new Node(x);
        if (head == NULL)
        {
            head = tmp;
            front = head;
            rear = head;
            // cout << tmp->prev << "  " << tmp->data << " " << tmp->next << endl;
        }
        else
        {
            tmp->prev = rear;
            rear->next = tmp;
            rear = rear->next;
        }
        size++;
    }
    void insertFront(int x)
    {
        Node *tmp = new Node(x);
        if (head == NULL)
        {
            head = tmp;
            front = head;
            rear = head;
        }
        else
        {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
            front = tmp;
        }
        size++;
    }
    void deleteFront()
    {
        if (head == NULL)
        {
            cout << "Deque is Empty" << endl;
            return;
        }
        Node *tmp = head;
        if (head->next == NULL) // if deque has only one element;
        {
            front == NULL;
            rear = NULL;
            head = NULL;
            delete (tmp);
        }
        else
        {
            head = head->next;
            front = head;
            head->prev = NULL;
            delete (tmp);
        }
        size--;
    }
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "Deque is Empty" << endl;
            return;
        }
        Node *tmp = rear;
        if (rear == front) // if deque has only one element;
        {
            front == NULL;
            rear = NULL;
            head = NULL;
            delete (tmp);
        }
        else
        {
            // cout << "IFront
            rear = rear->prev;
            rear->next == NULL;
            // cout << rear->data << " " << endl;
            delete (tmp);
        }
        size--;
    }
    int getSize()
    {
        return size;
    }
    void getFront()
    {
        if (head == NULL)
            cout << "Deque is Empty" << endl;
        else
            cout << "Front : " << front->data << endl;
    }
    void getRear()
    {
        if (head == NULL)
            cout << "Deque is Empty" << endl;
        else
            cout << "Back : " << rear->data << endl;
    }
};
int main()
{
    Node *h = NULL;
    Deque q(h);
    q.insertEnd(34);
    q.insertEnd(33);
    q.insertFront(334);
    q.insertFront(353);
    q.insertFront(434);
    q.insertFront(32343);
    q.deleteFront();
    q.getRear();

    q.getFront();
    cout << "Size= " << q.getSize() << endl;
}