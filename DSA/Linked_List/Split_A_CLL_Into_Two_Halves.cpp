/**/

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

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  *head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

/*Constraints
2 <= number of nodes <= 10^5
1 <= node->data <= 10^3*/
class Solution
{
public:
    // Function to split a circular linked list into two halves
    pair<Node *, Node *> splitList(struct Node *head)
    {
        // Initialize slow and fast pointers to find the middle
        Node *slow = head, *fast = head;

        // Move fast by two and slow by one until fast reaches end of list
        while (fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For even number of nodes, move fast to the last node
        if (fast->next != head) {
            fast = fast->next;
        }
        
        // Set the heads of the two halves
        Node *head1 = head;
        Node *head2 = slow->next;

        // Make the first half circular
        slow->next = head1;
        // Make the second half circular
        fast->next = head2;

        // Return the heads of the two halves
        return {head1, head2};
    }
};