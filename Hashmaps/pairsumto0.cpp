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
    unordered_map<int,int> f;
    for(int i=0;i<n;i++)
    f[a[i]]++;
    int p=0;
    for(int i=0;i<n;i++)
    {
        int x=f[-a[i]];
        while(x>0)
        {
            x--;
            if(a[i]>-a[i])
            cout<<a[i]<<" "<<-a[i];
            else
            cout<<-a[i]<<" "<<a[i];
            cout<<endl;
        }
        f[a[i]]--;
    }
}