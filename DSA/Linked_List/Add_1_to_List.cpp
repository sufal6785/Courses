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

class Solution {
  public:
  
    Node *reverse(Node *head){
                Node *curr = head, *prev = nullptr, *temp;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {

        head = reverse(head);
        
        Node *prev = head;
        int carry = 1;
        
        while(prev && carry){
            int sum = carry;
            if(prev){
                sum += prev->data;
                prev->data = sum%10;
                carry = sum/10;
                if(!prev->next && carry == 1){
                    prev->next= new Node(1);
                    prev = prev->next;
                }
                prev = prev->next;
            }
        }
        
        
        return reverse(head);
    }
};