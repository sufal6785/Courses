/**/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// Time Complexity O(n)
//  Space Complexity O(n)
/*Constrains:*/

class Solution
{
public:
    
};