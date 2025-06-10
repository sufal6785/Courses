#include <iostream>
#include <limits.h>
using namespace std;

class Queue
{
private:
    int *array;
    int capacity;
    int front, rear;

public:
    Queue(int size) : capacity(size), front(-1), rear(-1)
    {
        array = new int[capacity];
    }

    ~Queue()
    {
        delete[] array;
    }

    bool empty();

    bool full();

    void enQueue(int data);

    int deQueue();

    int Front();

    int size();

    void display();
};

// check if the queue is empty
bool Queue::empty()
{
    return front == -1;
}

// check if the queue is full
bool Queue::full()
{
    return (rear + 1) % capacity == front;
}

// to append an element at the end of the queue
void Queue::enQueue(int data)
{
    if (full())
    {
        cout << "Queue Overflow\n";
        return;
    }
    rear = (rear + 1) % capacity;
    array[rear] = data;

    if (empty())
    {
        front = rear;
    }
}

// remove and return the first element
int Queue::deQueue()
{
    if (empty())
    {
        cout << "Queue Underflow\n";
        return INT_MIN;
    }

    int data = array[front];

    if (rear == front)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }

    return data;
}

// return the first element
int Queue::Front()
{
    if (empty())
    {
        cout << "Queue Underflow\n";
        return INT_MIN;
    }

    return array[front];
}

// return the size of the Queue
int Queue::size()
{
    if (front <= rear)
    {
        return (rear - front + 1);
    }
    else
    {
        return (capacity + rear - front + 1) ;
    }
}

// display the queue
void Queue::display()
{
    if (empty())
    {
        cout << "Empty Queue\n";
        return;
    }
    int i = front;
    while (true)
    {
        cout << array[i] << " ";

        if (i == rear)
        {
            break;
        }
        i = (i + 1) % capacity;
    }
    cout << endl;
}

int main()
{
    Queue queue(4);
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    // queue.enQueue(5);

    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;

    queue.enQueue(5);
    queue.enQueue(6);
    queue.enQueue(7);

    cout << queue.size() << endl;

    queue.display();
}