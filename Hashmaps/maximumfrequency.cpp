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
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++)
    freq[a[i]]++;
    int key=0;
    int value=0;
    for(int i=0;i<n;i++)
    {
        if(freq[a[i]]>value)
        {
            value=freq[a[i]];
            key=a[i];
        }
    }
    cout<<key<<endl;
}