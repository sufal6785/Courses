#include <iostream>
#include <limits.h>
using namespace std;

class Queue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int val) : data(val), next(nullptr) {}
    };
    Node *front, *rear;
    int size_n;

public:
    Queue() : front(nullptr), rear(nullptr), size_n(0) {}

    ~Queue()
    {
        while (front)
        {
            Node *temp = front->next;
            delete front;
            front = temp;
        }
    }

    bool empty();

    void enQueue(int data);

    int deQueue();

    int Front();

    int size();

    void display();
};

// return true if the Queue is empty
bool Queue::empty()
{
    {
        return front == nullptr;
    }
}

// append an element at the end of the Queue
void Queue::enQueue(int data)
{
    Node *newNode = new Node(data);
    if (!front)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    size_n++;
}

// remove and return the first element
int Queue::deQueue()
{
    if (empty())
    {
        cout << "Queue Underflow\n";
        return INT_MIN;
    }
    int data = front->data;
    if (front == rear)
    {
        delete front;
        front = rear = nullptr;
    }
    else
    {
        Node *temp = front->next;
        delete front;
        front = temp;
    }
    size_n--;
    return data;
}

// return the first element
int Queue::Front()
{
    if (empty())
    {
        cout << "Empty Queue\n";
        return INT_MIN;
    }

    return front->data;
}

// display the Queue
void Queue::display()
{
    if (empty())
    {
        cout << "Empty Queue\n";
        return;
    }
    Node *current = front;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
