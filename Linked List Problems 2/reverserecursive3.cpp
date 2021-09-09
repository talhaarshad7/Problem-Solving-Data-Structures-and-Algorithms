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
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *rev(Node *head)
{
    if(head==NULL||head->next==NULL)
    return head;
    Node *smallAns=rev(head->next);
    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallAns;
}
int main()
{
    Node *head = takeInput();
    head = rev(head);
    print(head);
}