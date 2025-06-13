#include <iostream>
#include <limits.h>
using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int val) : data(val), next(nullptr) {}
    };
    Node *top;
    int size_n;

public:
    Stack() : top(nullptr), size_n(0) {}

    ~Stack()
    {
        while (top)
        {
            Node *temp = top->next;
            delete top;
            top = temp;
        }
    }

    bool empty();

    void push(int);

    int pop();

    int Top();

    int size();

    void display();
};

// return ture if the Stack is empty
bool Stack::empty()
{
    return top == nullptr;
}

// to append an element on the top of the Stack(FIFO)
void Stack::push(int data)
{
    Node *newNode = new Node(data);
    size_n++;
    if (empty())
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

// to remove and an element from the top of the Stack
int Stack::pop()
{
    if (empty())
    {
        cout << "Stack Underflow\n";
        return INT_MIN;
    }
    int data = top->data;
    Node *temp = top->next;
    delete top;
    top = temp;

    size_n--;

    return data;
}

// to return the top element
int Stack::Top()
{
    if (empty())
    {
        cout << "Empty Stack\n";
        return INT_MIN;
    }
    return top->data;
}

// return the size of the Stack
int Stack::size()
{
    int size = 0;
    Node *current = top;
    while (current)
    {
        current = current->next;
        size++;
    }

    return size;
}

// to display the element of the Stack
void Stack::display()
{
    if (empty())
    {
        cout << "Empty Stack\n";
        return;
    }

    Node *current = top;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(4);

    cout<<stack.size()<<endl;

    stack.display();
}