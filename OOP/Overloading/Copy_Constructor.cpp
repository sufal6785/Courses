//Deep copy constructor
//Default copy constructor won't work when dynamic memory allocation is done
#include <iostream>
using namespace std;

class Array
{
private:
    int *array;
    int size;

public:
    Array(int sz) : size(sz)
    {
        array = new int[sz];
    }

    ~Array()
    {
        delete[] array;
    }

    void set(int data, int position)
    {
        array[position] = data;
    }

    int get(int position) const
    {
        return array[position];
    }

    //copy constructor for deep copy;
    Array(const Array &other)   //Array for Array refrence(ref)
    {
        this->size = other.size;
        this->array = new int[other.size];
        for (int i = 0; i < this->size; i++)
        {
            set(other.get(i),i);
        }
    }
};

int main()
{
    Array arr(5);
    for (int i = 0; i < 5; i++)
        arr.set(i, i);

    Array x(arr);
    x.set(77, 4);   //when the default copy constructor, arr.array[4] will also be 77
    for (int i = 0; i < 5; i++)
        cout << x.get(i) << endl;

    for (int i = 0; i < 5; i++)
        cout << arr.get(i) << endl;
}