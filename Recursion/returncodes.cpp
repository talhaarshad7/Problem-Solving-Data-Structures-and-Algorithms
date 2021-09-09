//not working
#include<iostream>
using namespace std;
int codes(string ip,string op[])
{
    if(ip[0]=='\0')
    {
        op[0][0]='\0';
        return 1;
    }
    string op1[20],op2[20];
    int n1=codes(ip.substr(1),op1);
    int n2=codes(ip.substr(2),op2);
    char aa=ip[0]-1+'a';
    char bb=(char)(stoi(ip.substr(0,2))+96);
    if(aa<'a'||aa>'z')
    return 0;
    else if(bb<'a'||bb>'z')
    return 0;
    else 
    {
        string a,b;
        a+=aa;
        b+=bb;
        int k=0;
        for(int i=0;i<n1;i++)
        op[k++]=a+op1[i];
        for(int j=0;j<n2;j++)
        op[k++]=b+op2[j];
        return k;
    }
}
int main()
{
    string ip;
    cin>>ip;
    string op[20];
    int len=codes(ip,op);
    for(int i=0;i<len;i++)
    cout<<op[i]<<endl;
}