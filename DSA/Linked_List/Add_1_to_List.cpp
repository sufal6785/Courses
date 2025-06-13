#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        Node *current = head, *prev = NULL;
        while (current)
        {
            Node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }

    void push(Node **head, Node **tail, int data)
    {
        Node *newNode = new Node(data);
        if (*head == NULL)
        {
            *head = *tail = newNode;
        }
        else
        {
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }

    Node *addOne(Node *head)
    {
        // Your Code here
        if (head == NULL)
        {
            return (new Node(1));
        }
        head = reverse(head);

        Node *newHead = NULL, *newTail = NULL;
        int carry = 1;
        while (head && carry)
        {
            int sum = carry;
            sum += head->data;
            push(&newHead, &newTail, sum % 10);
            carry = sum / 10;
            head = head->next;
        }
        while (head)
        {
            push(&newHead, &newTail, head->data);
            head = head->next;
        }

        if (carry)
        {
            push(&newHead, &newTail, carry);
        }
        
        return reverse(newHead);
    }
};