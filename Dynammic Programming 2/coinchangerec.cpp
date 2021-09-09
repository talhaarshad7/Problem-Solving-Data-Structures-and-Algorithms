#include<iostream>
using namespace std;
int change(int m,int *arr,int n,int size)
{
    if(m==0)
    return 1;
    if(m<0||n==size)
    return 0;
    int op=change(m,arr,n+1,size)+change(m-arr[n],arr,n,size);
    return op;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int m;
    cin>>m;
    cout<<change(m,a,0,n)<<endl;
    delete [] a;
}