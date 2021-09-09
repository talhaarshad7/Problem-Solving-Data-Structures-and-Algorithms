#include<iostream>
using namespace std;
int last(int a[],int x,int n)
{
    if(n==0)
    return -1;
    int sp=last(a+1,x,n-1);
    if(sp==-1)
    {
        if(a[0]==x)
        return 1;
        else 
        return sp;
    }
    return sp+1;
}
int main()
{
    int a[]={5,5,3,2,5,2};
    cout<<last(a,5,6);
}