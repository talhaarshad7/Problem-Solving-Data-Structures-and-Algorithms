#include<iostream>
using namespace std;
int check(int a[],int x,int n)
{
    if(n==0)
    return 0;
    if(a[n-1]==x)
    return 1;
    int so=check(a,x,n-1);
    int result=0|so;
    return result;
}
int check1(int a[],int x,int n)
{
    if(n==0)
    return 0;
    if(a[n-1]==x)
    return 1;
    return check1(a,x,n-1);
}

int main()
{
    int arr1[]={1,3,5};
    int a2[]={1};
    int arr3[]={1,3,5,8};
    cout<<check(arr1,5,3)<<endl;
    cout<<check(a2,0,1)<<endl;
    cout<<check(arr3,9,4)<<endl;
    cout<<check1(arr1,5,3)<<endl;
    cout<<check1(a2,0,1)<<endl;
    cout<<check1(arr3,9,4)<<endl;
}