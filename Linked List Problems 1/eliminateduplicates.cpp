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
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void solve()
{
    Node *head=takeInput();
    Node *temp1=head;
    Node *temp2=head->next;
    while(temp2!=NULL)
    {
        if(temp2->data!=temp1->data)
        {
            temp1->next=temp2;
            temp1=temp2;
        }
        temp2=temp2->next;
    }
    temp1->next=NULL;
    print(head);
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}