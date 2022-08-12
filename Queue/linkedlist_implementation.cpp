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
};
struct Queue
{
    Node *front, *rear;
    int size;
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void enqueue(int x)
    {
        Node *tmp = new Node(x);
        if (front == NULL)
        {
            front = tmp;
            rear = tmp;
        }
        else
        {
            rear->next = tmp;
            rear = rear->next;
        }
        size++;
    }
    void dequeue()
    {
        if (front == NULL)
            return;
        Node *tmp = front;
        front = front->next;
        // cout << rear->next << endl;
        if (front == NULL)
            rear = NULL;
        // cout << rear;
        size--;
        delete (tmp);
    }
    int getSize()
    {
        return size;
    }
    Node *getFront()
    {
        return front;
    }
    Node *getRear()
    {
        return rear;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.dequeue();
    // // q.dequeue();
    q.enqueue(50);
    q.enqueue(59);
    q.enqueue(53);
    cout << q.getSize() << endl;
    cout << q.getFront()->data << endl;
    cout << q.getRear()->data << endl;
    // q.display();
    // cout << q.isEmpty() << " " << q.isFull() << endl;
    // cout << q.getFront() << endl;
    // cout << q.getRear() << endl;
}