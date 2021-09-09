#include<iostream>
using namespace std;
#include<cmath>
int ways(int n,int m)
{
    if(n<0)
    return 0;
    if(n==0)
    return 1;
    int s=0;
    for(int i=1;pow(i,m)<=n;i++)
    s=s+ways(n-pow(i,m),m);
    return s;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<ways(n,m)<<endl;
}