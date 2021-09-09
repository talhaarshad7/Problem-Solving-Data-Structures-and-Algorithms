#include<iostream>
#include<climits>
using namespace std;
int step(int n)
{
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=n;i++)
    {   
        int x,y=INT_MAX,z=INT_MAX;
        x=dp[i-1];
        if(i%2==0)
        y=dp[i/2];
        if(i%3==0)
        z=dp[i/3];
        int ans=1+min(x,min(y,z));
        dp[i]=ans;
    }
    int ans=dp[n];
    delete dp;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<step(n);
}