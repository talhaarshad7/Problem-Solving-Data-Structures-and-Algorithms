#include<iostream>
using namespace std;
#include<queue>
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bool c=true;
    for(int i=0;i<n;i++)
    {
        int l=2*i+1;
        int r=2*i+2;
        if(l<n)
        if(a[i]<a[l])
        {
            c=false;
            break;
        }
        if(r<n)
        if(a[i]<a[r])
        {
            c=false;
            break;
        }
    }
    cout<<boolalpha<<c<<endl;
}