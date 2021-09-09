#include<iostream>
using namespace std;
int ret(string ip,string op[])
{
    if(ip.empty())
    {
        op[0]="";
        return 1;
    }
    string smallString=ip.substr(1);
    int smallOutputLength=ret(smallString,op);
    for(int i=0;i<smallOutputLength;i++)
    {
        op[i+smallOutputLength]=ip[0]+op[i];
    }
    return 2*smallOutputLength;
}
int main()
{
    string i;
    cin>>i;
    string *o=new string[100];
    int co=ret(i,o);
    for(int i=0;i<co;i++)
    cout<<o[i]<<endl;
}