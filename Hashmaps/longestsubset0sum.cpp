#include<iostream>
using namespace std;
#include<unordered_map>
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    unordered_map<int,int> m;
    int sum=0,max=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(m.count(sum)>0)
        {
            int l=i-m[sum];
            if(l>max)
            max=l;
        }
        else
        {
            m[sum]=i;
        }
    }
    cout<<max;
}