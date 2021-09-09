#include<iostream>
using namespace std;
#include<stack>
int main()
{
    stack<char> s;
    string st;
    cin>>st;
    int l=st.length();
    bool balance=1;
    for(int i=0;i<l;i++)
    {
        if(st[i]=='(')
        s.push(st[i]);
        else if(st[i]==')')
        {
            if(!s.empty())
            s.pop();
            else
            {
                balance=0;
                break;
            }
        }
    }
    if(s.empty()&&balance==1)
    cout<<"true";
    else
    cout<<"false";
}
