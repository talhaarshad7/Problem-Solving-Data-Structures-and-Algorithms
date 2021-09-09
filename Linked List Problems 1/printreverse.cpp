#include<iostream>
using namespace std;
#include"nodeclass.cpp"
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
int length(Node* head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}
void solve()
{
    Node* head=takeInput();
    int l=length(head);
    for(int i=l;i>0;i--)
    {
        Node *temp=head;
        int count=0;
        while(count<i-1)
        {
            count ++;
            temp=temp->next;
        }
        cout<<temp->data<<" ";
    }
    cout<<endl;
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}