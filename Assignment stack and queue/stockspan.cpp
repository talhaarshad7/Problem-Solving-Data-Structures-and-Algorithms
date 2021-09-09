#include<iostream>
using namespace std;
#include<stack>
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    stack<int> s;
    s.push(0);
    int span[n];
    span[0]=1;
    for(int i=1;i<n;i++)
    {
        int sp;
        while(!s.empty()&&(a[s.top()]<a[i]))
        s.pop();
        if(s.empty())
        sp=i+1;
        else
        sp=i-s.top();
        span[i]=sp;
        s.push(i);
    }
    for(int i=0;i<n;i++)
    cout<<span[i]<<" ";
}