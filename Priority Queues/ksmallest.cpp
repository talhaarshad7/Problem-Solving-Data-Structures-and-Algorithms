#include<iostream>
using namespace std;
#include<queue>
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    pq.push(a[i]);
    for(int i=k;i<n;i++)
    {
        if(pq.top()>a[i])
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}