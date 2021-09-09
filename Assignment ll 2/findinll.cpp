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
int find(Node *head,int n)
{
    if(head==NULL)
    return -1;
    else if(head->data==n)
    return 0;
    else
    {
        int so=find(head->next,n);
        if(so==-1)
        return so;
        else
        return so+1;
    }
}
void solve()
{
    Node *head=takeInput();
    int n;
    cin>>n;
    int i=find(head,n);
    cout<<i<<endl;
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}