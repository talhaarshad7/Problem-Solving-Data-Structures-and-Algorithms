template <typename T>
class Node
{
    public:
    T data;
    Node<T> *next;
    Node(T element)
    {
        data=element;
        next=NULL;
    }
};
template <typename T>
class QueueLL
{
    private:
    Node<T> *front;
    Node<T> *rear;
    int size;
    public:
    QueueLL()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }
    void enqueue(T element)
    {
        Node<T> *newNode=new Node<T>(element);
        if(front==NULL)
        {
            front=rear=newNode;
            size++;
            return;
        }
        rear->next=newNode;
        rear=newNode;
        size++;
    }
    T dequeue()
    {
        if(front==NULL)
        {
            return -1;
        }
        int ans=front->data;
        Node<T> *temp=front;
        front=front->next;
        delete temp;
        size--;
        if(size==0)
            front=rear=NULL;
        return ans;
    }
    T fronnt()
    {
        if(front==NULL)
        {
            return -1;
        }
        return front->data;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
};