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
    if (head == NULL)
        return 0;
    int smallOutput = length(head->next);
    int output = 1 + smallOutput;
    return output;
}
int main()
{
    Node *head = takeInput();
    cout << length(head) << endl;
}