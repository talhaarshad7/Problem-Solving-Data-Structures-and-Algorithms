#include<iostream>
using namespace std;
#include"stackarraytemplate.cpp"
int main()
{
    StackUsingArray<float> s;
    s.push(21.6);
    s.push(34.5);
    s.push(65.8);
    s.push(1669.876);
    s.push(98.65);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
}