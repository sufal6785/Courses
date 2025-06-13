/*Here I used copy construcctor for deep copy, overload assignment operator,
check equality, concatenate two list using +, append another list using +=,
direct access the value using [] and overload insertion operator for output stream*/

#include <iostream>
using namespace std;

class List
{
private:
    // encapsulating node within list class to prventing external access & keeping it self contained
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int val) : data(val), next(nullptr) {}
    };
    Node *head, *tail;
    int size_n; // for calculating size without traversing the entire list

public:
    List() : head(nullptr), tail(nullptr), size_n(0) {}

    ~List() // List destructor to deallocate memory to prevent memory leaked
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;     // deleting current node
            current = nextNode; // shifting towards the next node
        }
    }

    // copy constructor
    List(const List &other) : head(nullptr), tail(nullptr), size_n(0)
    {
        Node *current = other.head;
        while (current)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    void push_back(int);

    void push_front(int);

    void insert(int, int);

    void pop_back();

    void pop_front();

    void pop(int);

    int size();

    void reverse();

    void display();

    // overloading assignment operator(=)
    List &operator=(const List &other)
    {
        if (this == &other) // check for self assignment
        {
            return *this;
        }

        while (head) // delete all existing nodes
        {
            pop_front();
        }

        Node *current = other.head;
        while (current) // copy each node from other list
        {
            push_back(current->data);
            current = current->next;
        }

        return *this;
    }

    // equality operator
    bool operator==(const List &other)
    {
        if (size_n != other.size_n)
            return false;

        Node *currentThis = head, *currentOther = other.head;
        while (currentThis && currentOther)
        {
            if (currentThis->data != currentOther->data)
                return false;

            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
        return true;
    }

    // concatenate two List(overloading + operator)
    List operator+(const List &other)
    {
        List result(*this);
        Node *current = other.head;
        while (current)
        {
            result.push_back(current->data);
            current = current->next;
        }

        return result;
    }

    //append another list
    List &operator+=(const List &other){
        Node *current = other.head;
        while(current){
            push_back(current->data);
            current = current->next;
        }
        return *this;
    }

    // overloading insertion (<<) operator for List
    // Allows printing the List object directly using cout << list;
    // Returns the output stream after printing all elements (or "Empty List" if the list is empty)
    friend ostream &operator<<(ostream &os, const List &other)
    {
        if (!other.head)
        {
            os << "Empty List\n"; // Print message if the list is empty
            return os;
        }
        Node *current = other.head;
        while (current)
        {
            os << current->data << " "; // Print each node's data
            current = current->next;
        }

        return os;
    }

    // Access index (0 based indexing)
    int &operator[](int index)
    {
        if (index < 0 || index >= size_n)
        {
            throw out_of_range("Invalid Index");
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            if (!current)
            {
                throw out_of_range("Invalid Index");
            }
            current = current->next;
        }
        return current->data;
    }
};

// push a data at the end of the list
void List::push_back(int data)
{
    Node *newNode = new Node(data); // allocating memory for  node
    if (head == nullptr)            // empty list
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode; // creating link
        tail = newNode;       // shifting tail to newnode
    }
    size_n++;
}

// push a data at first index
void List::push_front(int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr) // if tail is null, pointig head and tail to newNode
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size_n++;
}

// insert a data at a given position(0 based index)
void List::insert(int data, int position)
{
    if (position < 0 || position > size())
    {
        cout << "Invalid Index" << endl;
        return;
    }

    if (position == 0)
    {
        push_front(data);
        return;
    }

    if (position == size())
    {
        push_back(data);
        return;
    }

    Node *current = head, *prev = head;
    for (int i = 0; i < position; i++)
    {
        prev = current;
        current = current->next;
    }

    Node *newNode = new Node(data);
    prev->next = newNode;
    newNode->next = current;

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
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        current->next = nullptr; // marking the end of the list
        delete tail;             // deleting last node
        tail = current;          // updating tail to current
    }

    size_n--;
}

// remove the first element
void List::pop_front()
{
    if (head == nullptr) // empty list
    {
        cout << "Empty list" << endl;
        return;
    }

    if (head == tail) // single element
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *current = head;
        head = head->next;
        delete current;
    }

    size_n--;
}

// remove a given data on first occurance
void List::pop(int key)
{
    if (!head) // empty list
    {
        cout << "Empty List" << endl;
        return;
    }
    if (head && head->data == key) // key is first element
    {
        pop_front();
        return;
    }

    if (tail && tail->data == key) // key is last element
    {
        pop_back();
        return;
    }

    Node *current = head;
    Node *prev = head;
    while (current && current->data != key) // to find the key node
    {
        prev = current;
        current = current->next;
    }

    if (!current) // when key not found
    {
        cout << "Key not found" << endl;
        return;
    }

    Node *temp = current;       // to prevent memory leak
    prev->next = current->next; // skip current Node
    delete (temp);              // delet target node

    size_n--;
}

// return the size of the list
int List::size()
{
    return size_n;
}

// to reverse a list
void List ::reverse()
{
    if (!head || !head->next) // empty or single element
    {
        return;
    }
    Node *newHead = tail, *newTail = head, *current = head, *prev = nullptr;
    while (current)
    {
        // swap prev and next pointer and update current = current->next
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    // update head and tail
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

    lst.push_front(77);

    // lst.pop_front();

    // lst.pop_back();

    // lst.pop(77);

    // lst.pop(1);

    // lst.pop(3);

    // lst.reverse();
    // lst.reverse();

    // cout << lst.size() << endl;

    List ll, lss(lst);
    // ll = lst;
    // ll.push_back(8);

    ll += lss;
    cout<<ll<<endl;

    // lst.display();
    // ll.display();
    // lss.display();
    // cout<<(lst == ll)<<endl;

    // ll = lss + lst;
    // ll.display();

    // cout << lst << endl;
    // cout<<lst[2]<<endl;

}