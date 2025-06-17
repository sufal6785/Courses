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

// Time Complexity O(n)
//  Space Complexity O(n)

class Solution
{
public:
    
};