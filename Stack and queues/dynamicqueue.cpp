#include<iostream>
using namespace std;
template <typename T>
class Queue
{
private:
    T *data;
    int size;
    int firstIndex;
    int nextIndex;
    int capacity;

public:
    Queue()
    {
        capacity=5;
        data = new T[5];
        size = 0;
        firstIndex = -1;
        nextIndex = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            int *newData=new int[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++)
            newData[j++]=data[i];
            for(int i=0;i<firstIndex;i++)
            newData[j++]=data[i];
            int *temp=data;
            data=newData;
            delete [] temp;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;           
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if (firstIndex == -1)
            firstIndex = 0;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};