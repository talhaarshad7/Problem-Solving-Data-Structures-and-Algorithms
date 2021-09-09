#include<iostream>
using namespace std;
#include"queuell.h"
int main()
{
    QueueLL<int> q;
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        cin>>c;
        switch(c)
        {
            case 1:
            int d;
            cin>>d;
            q.enqueue(d);
            break;
            case 2:
            cout<<q.dequeue()<<endl;
            break;
            case 3:
            cout<<q.fronnt()<<endl;
            break;
            case 4:
            cout<<q.getSize()<<endl;
            break;
            case 5:
            cout<<q.isEmpty()<<endl;
            break;
        }
    }
}