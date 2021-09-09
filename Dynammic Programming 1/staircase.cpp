#include<iostream>
using namespace std;
int step(int n)
{
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    int ans=dp[n];
    delete dp;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<step(n)<<endl;
}