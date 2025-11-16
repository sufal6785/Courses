#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Priority_Queue
{
private:
    vector<T> v;

    void heapify_down(int i)
    {
        int n = (int)v.size();
        while (true)
        {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && v[l] > v[largest])
                largest = l;
            if (r < n && v[r] > v[largest])
                largest = r;

            if (i == largest)
                break;
            swap(v[i], v[largest]);
            i = largest;
        }
    }

    void heapify_up(int i)
    {
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (v[p] >= v[i])
                break;
            swap(v[i], v[p]);
            i = p;
        }
    }

public:
    Priority_Queue()
    {
    }

    void enqueue(T data)
    {
        v.push_back(data);

        heapify_up(v.size() - 1);
    }

    T dequeue()
    {

        T data = v.front();
        swap(v[v.size() - 1], v[0]);
        v.pop_back();

        heapify_down(0);

        return data;
    }

    // Change Priority
    void replace(T data, int i)
    {
        int size = (int)v.size();
        if (i < 0 || i >= size)
            return;

        T old = v[i];
        v[i] = data;
        if (data > old)
        {
            heapify_up(i);
        }
        if (data < old)
        {
            heapify_down(i);
        }
    }

    void print()
    {
        for (auto val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    Priority_Queue<int> pq;

    pq.enqueue(3);
    pq.enqueue(4);
    pq.enqueue(2);
    pq.enqueue(5);
    pq.enqueue(7);
    pq.enqueue(8);

    // cout << pq.dequeue() << endl;

    pq.print();
    pq.replace(0,2);
    pq.print();
}