#include<iostream>
using namespace std;
int sum(int a[],int n)
{
    if(n==0)
    return 0;
    int so=sum(a,n-1);
    int res=a[n-1]+so;
    return res;
}
int main()
{
    int arr1[]={1,3,5};
    int a2[]={1};
    int arr3[]={1,3,5,8};
    cout<<sum(arr1,3)<<endl;
    cout<<sum(a2,1)<<endl;
    cout<<sum(arr3,4)<<endl;
}