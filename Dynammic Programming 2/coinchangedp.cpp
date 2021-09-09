#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int v;
    cin>>v;
    int dp[v+1];
    for(int i=0;i<v+1;i++)
    dp[i]=0;
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<v+1;j++)
        {
            dp[j]=dp[j]+dp[j-a[i]];
        }
    }
    cout<<dp[v];
}