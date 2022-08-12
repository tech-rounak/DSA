#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    int size, cap, front;
    int *ar;
    Queue(int c)
    {
        front = 0;
        cap = c;
        size = 0;
        ar = new int[cap];
    }
    bool isFull()
    {
        return (size >= cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            // cout << front << " " << size << endl;
            ar[(front + size) % cap] = x;
            size++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
            return;
        front++;
        front = front % cap;
        size--;
    }
    int getFront()
    {
        return ar[front];
    }
    int getRear()
    {
        return ar[(front + size - 1) % cap];
    }
    void display()
    {
        cout << front << " " << size << endl;
        for (int i = front; i < front + size; i++)
        {
            cout << ar[i % cap] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(5);
    q.dequeue();
    q.enqueue(50);
    q.dequeue();
    q.enqueue(59);
    q.enqueue(53);
    q.display();
    // cout << q.isEmpty() << " " << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
}