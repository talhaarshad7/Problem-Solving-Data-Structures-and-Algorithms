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
    Node *head = takeInput();
    int m, n;
    cin >> m >> n;
    Node *temp = head, *prev = NULL;
    int mm = 1, nn = 1;
    if(m==0)
    head=NULL;
    else{
    while (temp != NULL)
    {
        if (mm <= m)
        {
            mm++;
            prev = temp;
            temp = temp->next;
        }
        else if (nn <= n)
        {
            nn++;
            Node *f=temp;
            temp = temp->next;
            delete f;
        }
        else if (nn == n+1)
        {
            prev->next = temp;
            prev = temp;
            mm = 2;
            nn = 1;
            temp = temp->next;
        }
    }
    prev->next = NULL;}
    print(head);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}