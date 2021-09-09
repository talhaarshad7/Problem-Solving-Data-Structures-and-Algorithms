#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<queue>
int main()
{
    priority_queue<int,vector<int>,greater<int>> min;
    priority_queue<int> max;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(min.empty()&&max.empty())
        {
            max.push(a[i]);
            cout<<a[i]<<endl;
            continue;
        }
        if(a[i]<max.top())
        {
            max.push(a[i]);
            if(max.size()-min.size()>1)
            {
                min.push(max.top());
                max.pop();
            }
        }
        else
        {
            min.push(a[i]);
            if(min.size()-max.size()>1)
            {
                max.push(min.top());
                min.pop();
            }
        }
        if(max.size()==min.size())
        cout<<(max.top()+min.top())/2<<endl;
        else if(max.size()>min.size())
        cout<<max.top()<<endl;
        else
        cout<<min.top()<<endl;
    }
}