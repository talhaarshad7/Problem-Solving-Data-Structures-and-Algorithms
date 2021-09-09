#include<iostream>
using namespace std;
#include<climits>
int edit(string s,string t)
{
    if(s.length()==0||t.length()==0)
    return max(s.size(),t.size());
    if(s[0]==t[0])
    return edit(s.substr(1),t.substr(1));
    else
    {
        //Insert
        int x=1+edit(s.substr(1),t);
        //Delete
        int y=1+edit(s,t.substr(1));
        //Replace
        int z=1+edit(s.substr(1),t.substr(1));
        int ans=min(x,min(y,z));
        return ans;
    }
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<edit(s,t)<<endl;
}