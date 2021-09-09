#include<iostream>
#include<climits>
using namespace std;
int step(int n,int *arr)
{
    if(n<=1)
    return 0;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(arr[n]!=-1)
    return arr[n];
    c=step(n-1,arr);
    if(n%3==0)
    a=step(n/3,arr);
    if(n%2==0)
    b=step(n/2,arr);
    arr[n]=1+min(a,min(b,c));
    return arr[n];
}
int step(int n)
{
    int *arr=new int[n+1];
    for(int i=0;i<n+1;i++)
    arr[i]=-1;
    return step(n,arr);
}
int main()
{
    int n;
    cin>>n;
    cout<<step(n);
}