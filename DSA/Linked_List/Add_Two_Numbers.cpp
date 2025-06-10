#include <iostream>
using namespace std;

// Structure of the linked list node is as
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
        if (!head)
            return NULL;
        if (head->next == NULL)
            return head;
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

    Node *addTwoLists(Node *num1, Node *num2)
    {
        int carry = 0;
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node *head = NULL, *tail = NULL;
        while (num1 || num2 || carry)
        {
            int sum = carry;
            if (num1)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2)
            {
                sum += num2->data;
                num2 = num2->next;
            }

            push(&head, &tail, sum % 10);
            carry = sum / 10;
        }

        head = reverse(head);
        while (head->data == 0)
        {
            head = head->next;
        }
        return head;
    }
};