#include <iostream>
using namespace std;
#include "lenlinklist.cpp"
int ielement(Node *head, int i)
{
    while (head != NULL && i >= 0)
    {
        if (i == 0)
            return head->data;
        else
        {
            i--;
            head = head->next;
        }
    }
    return -1;
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
        cout << ielement(head, i) << endl;
    }
}