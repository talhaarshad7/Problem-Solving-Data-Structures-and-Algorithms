#include <iostream>
using namespace std;
#include "nodeclass.cpp"
class Pair
{
public:
    Node *head;
    Node *tail;
};
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
Pair rev(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair so = rev(head->next);
    so.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = so.head;
    ans.tail = head;
    return ans;
}
void solve()
{
    Node *head = takeInput();
    int k;
    cin >> k;
    int count = 1;
    Node *h = head, *t = head,*nh,*start=NULL,*pt=NULL;
    Pair p;
    if(k==0)
    start=head;
    else
    while (t!=NULL)
    {
        if (count == k)
        {
            count = 1;
            nh=t->next;
            t->next=NULL;
            p=rev(h);
            p.tail->next=nh;
            if(start==NULL)
            start=p.head;
            if(pt==NULL)
            {
                pt=p.tail;
                t=nh;
                h=nh;
            }
            else
            {
                pt->next=p.head;
                pt=p.tail;
                h=nh;
                t=nh;
            }
        }
        else
        {
            count++;
            t=t->next;
        }
    }
    print(start);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}