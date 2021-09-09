#include<iostream>
using namespace std;
int first(int a[],int x,int n)
{
    if(n==0)
    return -1;
    if(a[0]==x)
    return 0;
    else{
    int so=first(a+1,x,n-1);
    return so==-1?-1:so+1;
    }
}
int main()
{
    int arr1[]={1,3,5,5,5};
    int a2[]={1};
    int arr3[]={1,3,5,8};
    cout<<first(arr1,5,3)<<endl;
    cout<<first(a2,1,1)<<endl;
    cout<<first(arr3,9,4)<<endl;
}