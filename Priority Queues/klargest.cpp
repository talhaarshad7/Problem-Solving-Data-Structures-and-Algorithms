#include<iostream>
using namespace std;
#include<queue>
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>k;
    for(int i=0;i<k;i++)
    pq.push(a[i]);
    for(int i=k;i<n;i++)
    {
        if(a[i]>pq.top())
        {
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}