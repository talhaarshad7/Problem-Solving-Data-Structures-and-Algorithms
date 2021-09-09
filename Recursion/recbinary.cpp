#include<iostream>
using namespace std;
int bin(int a[],int f,int l,int x)
{
    int m=(f+l)/2;
    if(f>l)
    return -1;
    else if(x==a[m])
    return m;
    else if(x<a[m])
    return bin(a,f,m-1,x);
    else
    return bin(a,m+1,l,x);
}
int main()
{
    int n;
    cin>>n;
    int *a=new int(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int x;
    cin>>x;
    cout<<bin(a,0,n,x);
}