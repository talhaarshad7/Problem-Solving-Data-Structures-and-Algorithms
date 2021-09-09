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
Node *swap(Node *head, int a, int b)
{
    int m = min(a, b);
    int n = max(a, b);
    int i;
    Node *temp1 = head, *temp2 = NULL;
    for (i = 0; i < m - 2; i++)
        temp1 = temp1->next;
    temp2 = temp1;
    for (; i < n - 2; i++)
        temp2 = temp2->next;
    Node *p1,*c1,*p2,*c2;
    p1=temp1;
    p2=temp2;
    c1=p1->next;
    c2=p2->next;
    p1->next=c2;
    p2->next=c1;
    return head;
}
void solve()
{
    Node *head = takeInput();
    int a, b;
    cin >> a >> b;
    head = swap(head, a, b);
    print(head);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}