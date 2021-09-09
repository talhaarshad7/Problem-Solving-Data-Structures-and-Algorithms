#include<iostream>
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
Node *rev(Node *head)
{
    if(head->next==NULL)
    return head;
    Node *smallOutput=rev(head->next);
    Node *temp=smallOutput;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=head;
    head->next=NULL;
    return smallOutput;
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
void solve()
{
    Node *head=takeInput();
    head=rev(head);
    print(head);
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}