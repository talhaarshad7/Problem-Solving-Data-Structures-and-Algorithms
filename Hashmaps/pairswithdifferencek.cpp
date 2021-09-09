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
    int k;
    cin>>k;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    m[a[i]]++;
    int c=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        if(x>=k)
        x=x-k;
        else
        x=x+k;
        m[a[i]]--;
        if(m[x]>0)
        c=c+m[x];
    }
    cout<<c<<endl;
}