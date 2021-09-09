#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    int dp[m][n];
    dp[m-1][n-1]=a[m-1][n-1];
    for(int i=m-2;i>=0;i--)
    dp[i][n-1]=dp[i+1][n-1]+a[i][n-1];
    for(int i=n-2;i>=0;i--)
    dp[m-1][i]=dp[m-1][i+1]+a[m-1][i];
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]))+a[i][j];
        }
    }
    cout<<dp[0][0];
}