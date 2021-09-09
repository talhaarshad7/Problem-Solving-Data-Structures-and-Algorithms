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
int length(Node *head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
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
    int l=length(head);
    int u;
    cin>>u;
    int n=l-u;
    Node* temp=head;
    int count = 0;
    while(count < n-1)
    {
        count++;
        temp=temp->next;
    }
    Node *temp1=temp->next;
    temp->next=NULL;
    Node *temp2=temp1;
    while(temp2->next!=NULL)
    temp2=temp2->next;
    temp2->next=head;
    head=temp1;
    print(head);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}