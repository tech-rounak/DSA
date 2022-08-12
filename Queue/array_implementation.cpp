#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    int size, cap;
    int *ar;
    Queue(int c)
    {
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
        if (size == cap)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            ar[size] = x;
            size++;
        }
    }
    void dequeue()
    {
        for (int i = 0; i < size - 1; i++)
        {
            ar[i] = ar[i + 1];
        }

        size--;
    }
    int getFront()
    {
        return ar[0];
    }
    int getRear()
    {
        return ar[size - 1];
    }
};
int main()
{
    Queue q(5);
    q.enqueue(5);
    q.enqueue(55);
    q.enqueue(50);
    q.enqueue(59);
    q.enqueue(56);
    q.enqueue(53);

    cout << q.isEmpty() << " " << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
}