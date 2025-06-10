#include <iostream>
#include <limits.h>
using namespace std;

class Queue
{
private:
    int *array;
    int capacity;
    int front, rear;
    int size_n;

    // return true if full
    bool full()
    {
        return rear == (capacity - 1);
    }

    // double the current size of the array
    void resize()
    {
        int size = capacity;
        capacity *= 2;
        array = (int *)realloc(array, sizeof(int) * capacity);

        // wrapped the array
        if (front > rear)
        {
            for (int i = 0; i < front; i++)
            {
                array[i + size] = array[i];
            }

            rear += size;
        }
    }

public:
    Queue() : capacity(1), front(-1), rear(-1), size_n(0)
    {
        array = (int *)malloc(capacity * sizeof(int));
    }

    ~Queue()
    {
        delete[] array;
    }

    bool empty()
    {
        return front == -1;
    }

    void enQueue(int);

    int deQueue();

    int Front();

    int size();

    void display();
};

// append an element at the end of the queue
void Queue::enQueue(int data)
{
    if (full())
    {
        resize();
    }

    rear = (rear + 1) % capacity;
    array[rear] = data;

    if (empty())
    {
        front = rear;
    }

    size_n++;
}

// remove and return the first element
int Queue::deQueue()
{
    if (empty())
    {
        cout << "Queue Unerflow\n";
        return INT_MIN;
    }
    int data = array[front];

    if (front == rear)
        front = -1;
    else
        front = ((front + 1) % capacity);

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
    return array[front];
}

// return the size of the queue
int Queue::size()
{
    return size_n;
}

// display the queue
void Queue::display()
{
    if (empty())
    {
        cout << "Empty Queue" << endl;
        return;
    }
    int i = front;
    while (true)
    {
        cout << array[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % capacity;
    }
    cout << endl;
}

int main()
{
    Queue queue;
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);

    cout << queue.deQueue() << endl;
    cout << queue.Front() << endl;
    cout << queue.size() << endl;
    queue.display();
}