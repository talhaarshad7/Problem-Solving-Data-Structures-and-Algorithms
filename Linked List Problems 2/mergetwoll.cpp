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
void solve()
{
    Node *h1 = takeInput();
    Node *h2 = takeInput();
    Node *fh = NULL, *ft = NULL;
    while (h1 != NULL && h2 != NULL)
    {
        if (fh == NULL || ft == NULL)
        {
            if (h1->data > h2->data)
            {
                fh = h2;
                ft = h2;
                h2 = h2->next;
            }
            else
            {
                fh = h1;
                ft = h1;
                h1 = h1->next;
            }
            continue;
        }
        if (h1->data> h2->data)
        {
            ft->next = h2;
            ft = h2;
            h2 = h2->next;
        }
        else
        {
            ft->next = h1;
            ft = h1;
            h1 = h1->next;
        }
    }
    if (h1 != NULL)
    ft->next = h1;
    else
    ft->next = h2;
    print(fh);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}