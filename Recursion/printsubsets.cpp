#include<iostream>
using namespace std;
void print(int ip[],int n,int size,int op[],int m)
{
    if(n==size)
    {
        for(int i=0;i<m;i++)
        cout<<op[i]<<" ";
        cout<<endl;
        return;
    }
    print(ip+1,n+1,size,op,m);
    int newop[10];
    int i;
    for(i=0;i<m;i++)
    op[i]=ip[i];
    op[i]=ip[n];
    print(ip+1,n+1,size,op,m+1);
    return;
    
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int *op=new int[10];
    print(a,0,n,op,0);
    free(a);
}