#include<iostream>
using namespace std;
#include<climits>
//BUG
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n+1;i++)
    cin>>a[i];
    int dp[n][n];
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;j++)
        {
            if(g==0)
            dp[i][j]=0;
            else if(g==1)
            dp[i][j]=a[i]*a[j]*a[j+1];
            else
            {
                int min=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int lc=dp[i][k];
                    int rc=dp[k+1][j];
                    int mc=a[i]*a[k+1]*a[j+1];
                    int tc=lc+rc+mc;
                    if(tc<min)
                    min=tc;
                }
                dp[i][j]=min;
            }
        }
    }
    cout<<dp[0][n]<<endl;
}