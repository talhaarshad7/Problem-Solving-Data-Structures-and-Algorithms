#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    int mod=(int)(pow(10,9))+7;
    for(int i=2;i<=n;i++)
    dp[i]=(int)(((long)(dp[i-1])*dp[i-1]) % mod)+(int)((2 * (long)(dp[i-1])*dp[i-2]) % mod);
    cout<<dp[n]<<endl;
}