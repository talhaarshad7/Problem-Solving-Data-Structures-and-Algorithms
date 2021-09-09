#include<iostream>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int dp[n+1];
    dp[1]=1;
    for(int i=2;i<n+1;i++)
    {
        if(i-x==0||i-y==0)
        {
            dp[i]=1;
            continue;
        }
        int a=0,b=0,c=0;
        a=dp[i-1]^1;
        if(i-x>=1)
        b=dp[i-x]^1;
        if(i-y>=1)
        c=dp[i-y]^1;
        dp[i]=max(a,max(b,c));
    }
    if(dp[n]==1)
    cout<<"Beerus"<<endl;
    else
    cout<<"Whis"<<endl;
}