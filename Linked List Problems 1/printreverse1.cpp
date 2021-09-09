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
void revprint(Node *head)
{
    if(head==NULL)
    return;
    revprint(head->next);
    cout<<head->data<<" ";
}
void solve()
{
    Node* head=takeInput();
    revprint(head);
    cout<<endl;
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}