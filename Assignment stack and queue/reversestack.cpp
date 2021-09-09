#include<iostream>
using namespace std;
#include<stack>
void rev(stack<int> &a,stack<int> &b)
{
    if(a.size()==1)
    return;
    int x=a.top();
    a.pop();
    rev(a,b);
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
    a.push(x);
    while(!b.empty())
    {
        a.push(b.top());
        b.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    stack<int> s1;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        s1.push(data);
    }
    stack<int> s2;
    rev(s1,s2);
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
}