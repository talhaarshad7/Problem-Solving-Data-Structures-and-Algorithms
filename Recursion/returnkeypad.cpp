#include<iostream>
using namespace std;
string key[10]={"","","abc","def","ghi","jkl","mno","pqr","wxyz"};
void copy(string op[],int p,int t)
{
    int counter=p*t-1;
    for(int i=p-1;i>=0;i--)
    {
        for(int j=0;j<t;j++)
        {
            op[counter]=op[i];
            counter--;
        }
    }
}
int ret(int ip,string op[])
{
    if(ip==0)
    {
        op[0]="";
        return 1;
    }
    int prevlen=ret(ip/10,op);
    int cd=ip%10;
    int ld=key[cd].length();
    int nl=prevlen*ld;
    copy(op,prevlen,ld);
    int counter=0;
    for(int i=0;i<prevlen;i++)
    {
        for(int j=0;j<ld;j++)
        {
            op[counter]=op[counter]+key[cd][j];
            counter++;
        }
    }
    return nl;
}
int main()
{
    int ip;
    cin>>ip;
    string *op=new string[100];
    int co=ret(ip,op);
    for(int i=0;i<co;i++)
    cout<<op[i]<<endl;    
}