#include <bits/stdc++.h>
using namespace std;
struct Deque
{
    int front, rear, cap;
    int *arr, size;
    Deque(int c)
    {
        cap = c;
        front = -1;
        rear = 0;
        size = 0;
        arr = new int[c];
    }
    bool isFull()
    {
        if (front == 1 && rear == cap - 1 || front == rear + 1)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void insertEnd(int x)
    {
        if (isFull())
        {
            cout << "Deque Full" << endl;
            return;
        }
        if (front == -1 && rear == 0)
        {
            arr[rear] = x;
            front++;
        }
        else
        {
            rear = rear + 1;
            arr[rear] = x;
        }
        size++;
    }
    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Deque Full" << endl;
            return;
        }
        if (front == -1 && rear == 0)
        {
            arr[rear] = x;
            front++;
        }
        else if (front == 0)
        {
            front = cap - 1;
            arr[front] = x;
        }
        else
        {
            front--;
            arr[front] = x;
        }
        size++;
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque Empty" << endl;
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
    void deleteEnd()
    {
        if (isEmpty())
        {
            cout << "Deque Empty" << endl;
            return;
        }
        size--;
        // cout << front << " " << rear << endl;
        rear = (rear - 1);
        if (rear < 0)
            rear = cap - 1;
    }
    int getSize()
    {
        return size;
    }
    int getFront()
    {
        // cout << front << endl;
        if (rear == 0 && front == 0 || rear != front)
            return arr[front];
        return -1;
    }
    int getRear()
    {
        // cout << rear << endl;
        if (rear == 0 && front == 0 || rear != front)
            return arr[rear];
        return -1;
    }
};
int main()
{
    Deque d(5);
    d.insertEnd(43);
    d.insertFront(64);
    d.insertFront(65);
    d.insertFront(45);
    d.insertEnd(34);
    // d.insertEnd(87);
    //    45 65 64 43 34
    // 43 34 45 65 64
    cout << "Size=" << d.getSize() << endl;
    // d.deleteFront();
    // d.deleteFront();
    d.deleteEnd();
    cout << "Size=" << d.getSize() << endl;
    d.deleteEnd();
    cout << "Size=" << d.getSize() << endl;
    d.deleteEnd();
    cout << "Size=" << d.getSize() << endl;
    d.deleteEnd();
    cout << "Size=" << d.getSize() << endl;
    d.deleteEnd();
    cout << "Size=" << d.getSize() << endl;
    d.deleteEnd();
    cout << "Size=" << d.getSize() << endl;
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
}