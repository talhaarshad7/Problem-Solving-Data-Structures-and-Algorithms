#include<iostream>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int m=s.length();
    int n=t.length();
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++)
    dp[i][0]=i;
    for(int i=0;i<n+1;i++)
    dp[0][i]=i;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s[m-i]==t[n-j])
            dp[i][j]=dp[i-1][j-1];
            else
            {
                int x=dp[i-1][j]+1;
                int y=dp[i-1][j-1]+1;
                int z=dp[i][j-1]+1;
                int ans=min(x,min(y,z));
                dp[i][j]=ans;
            }
        }
    }
    cout<<dp[m][n]<<endl;
}