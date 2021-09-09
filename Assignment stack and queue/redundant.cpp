#include<iostream>
using namespace std;
#include<stack>
bool isOperator(char st)
{
    return st=='+'||st=='/'||st=='*'||st=='-';
}
int main()
{
    stack<char> s;
    string st;
    cin>>st;
    bool r=0;
    for(int i=0;i<st.length();i++)
    {
        if(st[i]=='('||isOperator(st[i]))
        s.push(st[i]);
        if(st[i]==')')
        {
            int flag=0;
            while(s.top()!='(')
            {
                if(isOperator(s.top()))
                flag=1;
                s.pop();
            }
            if(flag==0)
            {
                r=1;
                break;   
            }
            s.pop();
        }
    }
    if(r==0)
    cout<<boolalpha<<r;
    else
    cout<<boolalpha<<r;

}