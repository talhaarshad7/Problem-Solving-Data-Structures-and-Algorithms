#include<iostream>
using namespace std;
#include<climits>
int count(int *a,int s,int e)
{
    if(s==e-1||s==e)
    return 0;
    int c=INT_MAX;
    for(int k=s+1;k<e;k++)
    {
        c=min(c,a[s]*a[e]*a[k]+count(a,s,k)+count(a,k,e));
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n+1;i++)
    cin>>a[i];
    cout<<count(a,0,n)<<endl;
}