#include <iostream>
using namespace std;
class DynamicArray
{
public:
    int capacity;
    int nextIndex;
    int *data;
    DynamicArray()
    {
        capacity = 5;
        nextIndex = 0;
        data = new int[5];
    }
    DynamicArray(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
            this->data[i] = d.data[i];
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
            this->data[i] = d.data[i];
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[capacity * 2];
            for (int i = 0; i < nextIndex; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    void add(int element, int i)
    {
        if (i < nextIndex)
            data[i] = element;
        else if (i == nextIndex)
            add(element);
        else
            return;
    }
    void display()
    {
        for (int i = 0; i < nextIndex; i++)
            cout << this->data[i] << " ";
        cout << endl;
    }
    int get(int i) const
    {
        if (i < nextIndex)
            return this->data[i];
        else
            return -1;
    }
};