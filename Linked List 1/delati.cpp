#include <iostream>
using namespace std;
#include "nodeclass.cpp"
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = head; //or tail=newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode; //tail=tail->next;
        }
        cin >> data;
    }
    return head;
}
Node *del(Node *head, int i)
{
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    int count = 0;
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        if (temp->next == NULL)
            return head;
        Node *p = temp->next;
        temp->next = temp->next->next;
        delete p;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        int i;
        cin >> i;
        head = del(head, i);
        print(head);
    }
}