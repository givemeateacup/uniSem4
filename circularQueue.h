#include <iostream>
using namespace std;

template <class t>
class circularQueue
{
public:
    int front;
    int rear;
    t *cQ;
    int count;
    int maxSize;

    circularQueue(int a)
    {
        cQ = new t[a];
        front = -1;
        rear = -1;
        count = 0;
        maxSize = a;
    }

    void enqueue(t a)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % maxSize;
        cQ[rear] = a;
        count++;
        cout << "Enqueued: " << a << endl;
    }

    t dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        t valueToReturn = cQ[front];
        if (count == 1) // Last element
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }
        count--;
        return valueToReturn; // and not like return cQ[(front - 1) % maxSize]; effects original front
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == maxSize;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;
        while (true)
        {
            cout << cQ[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }

    t frontValue() // Optional: peek at front
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return t(); // Return default value
        }
        return cQ[front];
    }

    virtual ~circularQueue()
    {
        delete[] cQ;
        cQ = nullptr;
    }
};

// template <class t>
// class myCQ : public circularQueue<t>
// {
// public:
//     myCQ(int a) : circularQueue<t>(a) {} // need constructor
// };
// int main()
// {
//     myCQ<int> q(5);
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.display();
//     q.dequeue();
//     q.display();
//     return 0;
// }