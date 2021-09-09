#include<iostream>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int m=s.length();
    int n=t.length();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++)
    dp[0][i]=0;
    for(int i=0;i<=m;i++)
    dp[i][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[m-i]==t[n-j])
            dp[i][j]=1+dp[i-1][j-1];
            else
            {
                int a=dp[i-1][j-1];
                int b=dp[i][j-1];
                int c=dp[i-1][j];
                dp[i][j]=max(a,max(b,c));
            }
        }
    }
    cout<<dp[m][n]<<endl;
}