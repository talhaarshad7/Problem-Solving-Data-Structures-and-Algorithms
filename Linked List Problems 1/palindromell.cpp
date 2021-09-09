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
int length(Node *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}
void solve()
{
    Node *head = takeInput();
    int l = length(head);
    int flag = 0;
    Node *temp1 = head;
    for (int i = l; i >= (l / 2) + 1; i--)
    {
        int count = 0;
        Node *temp = head;
        while (count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp->data != temp1->data)
        {
            flag = 1;
            break;
        }
        else
            temp1 = temp1->next;
    }
    if (flag == 0)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}