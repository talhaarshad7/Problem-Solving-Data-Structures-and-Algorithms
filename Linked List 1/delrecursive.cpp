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
Node *del(Node *head, int i)
{
    if (i == 0)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    if (i < 0 || head == NULL)
        return head;
    head->next = del(head->next, i - 1);
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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        int i;
        cin >> i;
        head = del(head, i);
        print(head);
    }
}