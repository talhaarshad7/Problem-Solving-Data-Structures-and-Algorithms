#include<iostream>
using namespace std;
#include<unordered_map>
int main()
{
    string st;
    cin>>st;
    unordered_map<char,int> u;
    int n=st.length();
    for(int i=0;i<n;i++)
    {
        char c=st[i];
        if(u.count(c)>0)
        continue;
        else
        {
            u[c]=1;
            cout<<c;
        }
    }
}