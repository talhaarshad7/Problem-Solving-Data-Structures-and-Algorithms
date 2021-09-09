#include<iostream>
using namespace std;
#include<math.h>
#include<climits>
int main()
{
    int n;
    cin>>n;
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    dp[i]=INT_MAX;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        dp[i]=min(dp[i],dp[i-j*j]+1);
    }
    
    cout<<dp[n];
}