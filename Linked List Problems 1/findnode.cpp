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
int find(Node*head,int n)
{
    int i=-1;
    while(head)
    {
        i++;
        if(head->data==n)
        return i;
        head=head->next;
    }
    return -1;
}
void solve()
{
    Node *head=takeInput();
    int n;
    cin>>n;
    cout<<find(head,n)<<endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}