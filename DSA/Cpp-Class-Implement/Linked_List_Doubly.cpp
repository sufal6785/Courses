#include <iostream>
using namespace std;

class List
{
private:
    class Node
    {
    public:
        int data;
        Node *next, *prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node *head, *tail;
    int size_n;

public:
    List() : head(nullptr), tail(nullptr), size_n(0) {}

    int size();

    void push_back(int);

    void push_front(int);

    void insert(int, int);

    void pop_back();

    void pop_front();

    void pop(int);

    void reverse();

    void display();

    ~List()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
        head = tail = nullptr;
    }
};

// return the size of the list
int List::size()
{
    return size_n;
}

// push a data at the end of the list
void List::push_back(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size_n++;
}

// push a data at first index
void List::push_front(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    size_n++;
}

// insert a data at a given position(0 based index)
void List::insert(int val, int position)
{
    if (position < 0 || position > size())
    {
        cout << "Invalid Index" << endl;
        return;
    }

    if (position == 0)
    {
        push_front(val);
        return;
    }

    if (position == size())
    {
        push_back(val);
        return;
    }

    Node *current = head;
    for (int i = 1; i < position; i++) // to find the (position - 1)th node
    {
        current = current->next;
    }

    Node *newNode = new Node(val);

    newNode->next = current->next;
    newNode->next->prev = newNode; // backward link
    newNode->prev = current;
    current->next = newNode;

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

    if (head == tail) // single element
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *current = tail;
        tail = tail->prev;    // updating tail
        tail->next = nullptr; // marking the end of the list
        delete current;       // deleting last node
    }

    size_n--;
}

// remove the first element
void List::pop_front()
{
    if (head == nullptr)
    {
        cout<<"Empty List"<<endl;
        return;
    }

    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *current = head;
        head = head->next;
        head->prev = nullptr;
        delete current;
    }
    size_n--;
}

// remove a given data on first occurance
void List ::pop(int key)
{
    if (!head)
    {
        cout << "Empty List" << endl;
        return;
    }

    if (head->data == key)
    {
        pop_front();
        return;
    }

    if (tail->data == key)
    {
        pop_back();
        return;
    }

    Node *current = head;
    while (current && current->data != key)
    {
        current = current->next;
    }
    if (!current)
    {
        cout << "Key not found" << endl;
        return;
    }
    Node *temp = current;
    current->prev->next = current->next; // skipping the current node
    current->next->prev = current->prev; // backward link
    delete temp;                         // dealloacte memory for the current node

    size_n--;
}

// to reverse a list
void List ::reverse()
{
    // time O(n) and space O(1)
    if (!head || !head->next) // empty or single element
    {
        return;
    }

    Node *newHead = tail, *newTail = head, *current = head;
    while (current)
    {
        //swapping the next and prev pointers
        Node *temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    head = newHead;
    tail = newTail;
}

// print the list
void List::display()
{
    if (!head)
    {
        cout << "Empty List" << endl;
        return;
    }
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    List lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    lst.insert(7, 3);
    lst.pop(3);
    // cout << lst.size() << endl;
    lst.reverse();
    lst.reverse();
    lst.display();
}