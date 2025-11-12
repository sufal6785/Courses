#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Max_Heap
{
private:
    int capacity;
    int size;
    int *arr;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    bool isFull()
    {
        return size == capacity;
    }

    void resize()
    {
        capacity *= 2;
        arr = (int *)realloc(arr, sizeof(int) * capacity);
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify_up(int i)
    {
        while (i > 0)
        {
            int p = parent(i);
            if (arr[p] >= arr[i])
                break;
            swap(arr[i], arr[p]);
            i = p;
        }
    }

    void heapify_down(int i)
    {

        while (true)
        {
            int largest = i;
            int l = left(i);
            int r = right(i);
            if (l < size && arr[l] > arr[largest])
                largest = l;
            if (r < size && arr[r] > arr[largest])
                largest = r;

            if (i == largest)
                break;
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

public:
    Max_Heap() : capacity(1), size(0)
    {
        arr = (int *)malloc(sizeof(int) * capacity);
    }

    ~Max_Heap()
    {
        free(arr);
    };

    void insert(int data)
    {
        if (isFull())
            resize();

        arr[size] = data;
        heapify_up(size);
        size += 1;
    }

    int getMin()
    {
        if (!size)
            return numeric_limits<int>::min();
        return arr[0];
    }

    int extractMax()
    {
        if (!size)
            return numeric_limits<int>::min();
        int max_value = arr[0];
        swap(arr[0], arr[size - 1]);
        size--;
        heapify_down(0);
        return max_value;
    }

    void replace(int position, int new_val)
    {
        if (position < 0 || position >= size)
            return;
        int old_val = arr[position];
        arr[position] = new_val;

        if (new_val > old_val)
        {
            heapify_up(position);
        }
        else if (new_val < old_val)
        {
            heapify_down(position);
        }
        else
            return;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Max_Heap h;

    h.insert(6);
    h.insert(2);
    h.insert(4);
    h.insert(1);
    h.insert(17);
    h.insert(5);
    h.insert(13);

    // cout << h.extractMax() << endl;


    h.replace(2,18);

    h.print();
}
