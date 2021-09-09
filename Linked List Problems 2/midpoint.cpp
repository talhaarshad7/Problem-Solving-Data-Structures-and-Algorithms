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

void solve()
{
    Node *head=takeInput();
    if(head==NULL)
    return;
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}