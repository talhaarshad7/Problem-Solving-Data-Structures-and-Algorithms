#include<iostream>
using namespace std;
#include<stack>
void copystack(stack<int> &d,stack<int> s)
{
    if(s.size()==1)
    return;
    int x=s.top();
    s.pop();
    copystack(d,s);
    d.push(x);
}
int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    stack<int> s2=s1;
    while(!s2.empty())
    {
        cout<<s2.top()<<endl;
        s2.pop();
    }
    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
}