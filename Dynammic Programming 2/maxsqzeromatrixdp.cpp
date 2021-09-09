#include<iostream>
using namespace std;
#include<climits>
int main()
{
    int x,y;
    cin>>x>>y;
    int a[x][y];
    int dp[x][y];
    for(int i=0;i<x;i++)
    for(int j=0;j<y;j++)
    cin>>a[i][j];
    for(int i=0;i<y;i++)
    {
        if(a[0][i]==0)
        dp[0][i]=1;
        else
        dp[0][i]=0;
    }
    for(int i=0;i<x;i++)
    {
        if(a[i][0]==0)
        dp[i][0]=1;
        else
        dp[i][0]=0;
    }
    for(int i=1;i<x;i++)
    {
        for(int j=1;j<y;j++)
        {
            if(a[i][j]==0)
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            else
            dp[i][j]=0;
        }
    }
    int max=INT_MIN;
    for(int i=0;i<x;i++)
    for(int j=0;j<x;j++)
    if(dp[i][j]>max)
    max=dp[i][j];
    cout<<max;
}