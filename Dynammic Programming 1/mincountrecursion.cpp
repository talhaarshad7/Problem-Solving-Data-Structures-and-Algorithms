#include<iostream>
using namespace std;
#include<math.h>
int count(int n)
{
    if(n<=3)
    return n;
    if(sqrt(n)*sqrt(n)==n)
    return 1;
    int ans=n;
    for(int i=1;i*i<n;i++)
    {
        ans=min(ans,count(n-i*i)+1);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<count(n)<<endl;
}