/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/min-stack/?envType=problem-list-v2&envId=stack

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$$ -->

*/

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> ele, min;

public:
    MinStack() {}

    void push(int val)
    {
        ele.push(val);
        if (min.empty() || min.top() >= val)
        {
            min.push(val);
        }
    }

    void pop()
    {
        if (ele.top() == min.top())
        {
            min.pop();
        }
        ele.pop();
    }

    int top()
    {
        return ele.top();
    }

    int getMin()
    {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */