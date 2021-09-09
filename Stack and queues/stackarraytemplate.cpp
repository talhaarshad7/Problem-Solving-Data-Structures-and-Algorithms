template <typename T>
class StackUsingArray
{
    private:
    T *data;
    int capacity;
    int nextIndex;
    public:
    StackUsingArray()
    {
        data=new T[4];
        capacity=4;
        nextIndex=0;
    }
    void push(T element)
    {
        if(nextIndex==capacity)
        {
            T *newArray=new T[2*capacity];
            for(int i=0;i<capacity;i++)
            newArray[i]=data[i];
            capacity*=2;
            delete [] data;
            data=newArray; 
        }
        data[nextIndex++]=element;
    }
    T pop()
    {
        if(nextIndex==0)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[--nextIndex];
    }
    T top()
    {
        if(nextIndex==0)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
    int size()
    {
        return nextIndex;
    }  
};