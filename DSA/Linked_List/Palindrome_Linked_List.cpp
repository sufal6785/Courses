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
    Node *getMiddle(Node *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(Node *head)
    {
        if (!head || !head->next)
            return true;

        // split the list, first one is from head to middle(exclude)
        Node *first = head;

        // reverse from the middle of the linked list
        Node *current = getMiddle(head);

        Node *prev = nullptr, *temp;
        while (current)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        // second list from the middle to the end of the list
        Node *second = prev;
        while (second)
        {
            if (first->data != second->data)
                return false;

            first = first->next;
            second = second->next;
        }
        return true;
    }
};
