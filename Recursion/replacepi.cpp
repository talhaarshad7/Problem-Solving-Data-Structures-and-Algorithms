#include<iostream>
using namespace std;
void rep(char *s,int n)
{
    if(n==0)
    return;
    if(n==1)
    {
        cout<<s[0];
        return;
    }
    if(s[0]=='p'&&s[1]=='i')
    {
        cout<<"3.14";
        rep(s+2,n-2);
    }
    else
    {
        cout<<s[0];
        rep(s+1,n-1);
    }
}
int main()
{
    rep("xpix",4);
    cout<<endl;
    rep("pipi",4);
    cout<<endl;
    rep("pip",3);
}