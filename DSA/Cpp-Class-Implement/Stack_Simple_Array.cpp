#include <iostream>
#include <limits.h>
using namespace std;

class Stack
{
private:
    int capacity;
    int *array;
    int top;

public:
    Stack(int size) : capacity(size), top(-1)
    {
        array = new int[capacity];
    }

    ~Stack()
    {
        delete[] array;
    }

    bool empty();

    bool full();

    void push(int);

    int pop();

    int Top();

    int size();

    void display();
};

// return ture if the Stack is empty
bool Stack::empty()
{
    return top == -1;
}

// return true if the Stack is full
bool Stack::full()
{
    return top == (capacity - 1);
}

// to append an element on the top of the Stack(FIFO)
void Stack::push(int data)
{
    if (full())
    {
        cout << "Stack Overflow\n";
        return;
    }
    array[++top] = data;
}

// to remove and an element from the top of the Stack
int Stack::pop()
{
    if (empty())
    {
        cout << "Stack Underflow\n";
        return INT_MIN;
    }
    return array[top--];
}

// to return the top element
int Stack::Top()
{
    if (empty())
    {
        cout << "Empty Stack\n";
        return INT_MIN;
    }
    return array[top];
}

// return the size of the Stack
int Stack::size()
{
    return top + 1;
}

// to display the element of the Stack
void Stack::display()
{
    if (empty())
    {
        cout << "Empty Stack\n";
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << stack.Top() << endl;

    stack.display();
}