#include <iostream>
using namespace std;

class List
{
private:
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int val) : data(val), next(this) {}
    };
    Node *head;
    int size_n;

public:
    List() : head(nullptr), size_n(0) {}

    ~List()
    {
        if (head != nullptr)
        {
            Node *current = head;
            do
            {
                Node *nextNode = current->next;
                delete current;     // deleting current node
                current = nextNode; // shifting towards the next node
            } while (current != head);
            delete head;
        }
    }

    void push_back(int);

    void push_front(int);

    void pop_back();

    void pop_front();

    int size();

    void display();
};

// push a data at the end of the list
void List::push_back(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr) // empty list
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    size_n++;
}

// push a data at first index
void List::push_front(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    size_n++;
}

// remove the last element
void List::pop_back()
{
    if (head == nullptr) // empty list
    {
        cout << "Empty List" << endl;
        return;
    }

    if (head == head->next) // single element
    {
        delete head;
        head = nullptr;
        return;
    }
    else
    {
        Node *current = head, *prev = head;
        while (current->next != head)
        {
            prev = current;
            current = current->next;
        }

        prev->next = head; // marking the end of the list
        delete current;    // deleting last node
    }

    size_n--;
}

// remove the first element
void List::pop_front()
{
    if (head == nullptr) // empty list
    {
        cout << "Empty List" << endl;
        return;
    }

    if (head == head->next) // single element
    {
        delete head;
        head = nullptr;
        return;
    }
    else
    {
        Node *current = head;
        do
        {
            current = current->next;
        } while (current->next != head);

        Node *temp = head->next;
        delete head;
        head = temp;
        current->next = head;
    }

    size_n--;
}

// return the size of the list
int List::size()
{
    return size_n;
}

// print the list
void List::display()
{
    if (head == nullptr)
    {
        cout << "Empty List" << endl;
        return;
    }

    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main()
{
    List lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    // lst.push_back(4);

    lst.push_front(77);

    lst.pop_front();

    // lst.pop_back();

    cout << lst.size() << endl;

    lst.display();
}