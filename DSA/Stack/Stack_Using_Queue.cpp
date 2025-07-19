#include <queue>
using namespace std;
class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int size = q.size();
        for (int i = 0; i < size - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int result = q.front();
        q.pop();
        return result;
    }

    int top()
    {
        int size = q.size();
        for (int i = 0; i < size - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int result = q.front();
        q.pop();
        q.push(result);
        return result;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack
{
private:
    queue<int> a, b;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        a.push(x);
    }

    int pop()
    {
        while (a.size() > 1)
        {
            b.push(a.front());
            a.pop();
        }
        int result = a.front();
        a.pop();
        swap(a, b);
        return result;
    }

    int top()
    {
        while (a.size() > 1)
        {
            b.push(a.front());
            a.pop();
        }
        int result = a.front();
        a.pop();
        b.push(result);
        swap(a, b);
        return result;
    }

    bool empty()
    {
        return a.empty();
    }
};