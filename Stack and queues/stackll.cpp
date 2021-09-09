using namespace std;
template <typename T>
class Node
{
    public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class Stack
{
    private:
    Node<T> *head;
    int size;
public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (size != 0)
            newNode->next = head;
        head = newNode;
        size++;
    }
    T pop()
    {
        if (head == NULL)
            return -1;
        T element = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return element;
    }
    T top()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }
};