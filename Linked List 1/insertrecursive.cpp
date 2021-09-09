#include <iostream>
using namespace std;
#include "nodeclass.cpp"
Node *takeInput()
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *tail = NULL;
    while (n != -1)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> n;
    }
    return head;
}
Node *insert(Node *head, int i, int n)
{
    if (head==NULL)
    return NULL;
    else if (i == 0 && head!=NULL)
    {
        Node *newNode = new Node(n);
        newNode->next=head;
        head=newNode;
        return head;
    }
    else if (i == 1 && head!=NULL)
    {
        Node *newNode = new Node(n);
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }
    Node* smallOutput=insert(head->next,i-1,n);
    head->next=smallOutput;
    return head;
}
Node* insert2(Node* head,int i,int n)
{
    if(i==0)
    {
        Node* newNode=new Node(n);
        newNode->next=head;
        head=newNode;
        return head;
    }
    if(i<0||head==NULL)
    return head;
    head->next=insert2(head->next,i-1,n);
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
    Node* head=takeInput();
    int i,n;
    cin>>i>>n;
    head=insert2(head,i,n);
    print(head);
}