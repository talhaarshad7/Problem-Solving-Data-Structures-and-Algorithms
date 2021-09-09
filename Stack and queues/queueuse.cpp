#include<iostream>
using namespace std;
#include"queue.h"
int main()
{
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    
    cout<<q.dequeue()<<endl;
    
    cout<<q.dequeue()<<endl;
}