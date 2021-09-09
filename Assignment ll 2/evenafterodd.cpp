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
Node *setevenodd(Node *head)
{
    Node *he = NULL, *ho = NULL, *e = NULL, *o = NULL;
    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            if (o == NULL)
            {
                o = head;
                ho = head;
                head = head->next;
                continue;
            }
            o->next = head;
            o = head;
        }
        else
        {
            if (e == NULL)
            {
                e = head;
                he = head;
                head = head->next;
                continue;
            }
            e->next = head;
            e = head;
        }
        head = head->next;
    }
    if (ho != NULL && he != NULL)
    {
        o->next = NULL;
        e->next = NULL;
        o->next = he;
        return ho;
    }
    else if (ho == NULL)
    {
        e->next == NULL;
        return he;
    }
    else
    {
        o->next = NULL;
        return ho;
    }
}
void solve()
{
    Node *head = takeInput();
    head = setevenodd(head);
    print(head);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}