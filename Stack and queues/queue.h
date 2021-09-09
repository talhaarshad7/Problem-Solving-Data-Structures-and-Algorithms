template <typename T>
class Queue
{
private:
    T *data;
    int size;
    int capacity;
    int firstIndex;
    int nextIndex;

public:
    Queue(int s)
    {
        data = new T[s];
        capacity = s;
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
            cout << "Queue is full" << endl;
            return;
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