#include<iostream>
#include<climits>
using namespace std;
int knap(int *w,int *v,int l,int n)
{
    if(l<=0)
    return 0;
    if(n==0)
    return 0;
    if(w[0]>l)
    return knap(w+1,v+1,l,n-1);
    int x=knap(w+1,v+1,l,n-1);
    int y=knap(w+1,v+1,l-w[0],n)+v[0];
    int ans=max(x,y);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int w[n],v[n];
    for(int i=0;i<n;i++)
    cin>>w[i];
    for(int i=0;i<n;i++)
    cin>>v[i];
    int l;
    cin>>l;
    cout<<knap(w,v,l,n);

}