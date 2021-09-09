#include<iostream>
using namespace std;
#include"stackll.cpp"
int main()
{
    int t;
    cin>>t;
    Stack<int> s;
    while(t--)
    {
        int c;
        cin>>c;
        switch(c)
        {
            case 1:
            int x;
            cin>>x;
            s.push(x);
            break;
            case 2:
            cout<<s.pop()<<endl;
            break;
            case 3:
            cout<<s.top()<<endl;
            break;
            case 4:
            cout<<s.getSize()<<endl;
            break;
            case 5:
            cout<<boolalpha<<s.isEmpty()<<endl;
            break;
        }
    }

}