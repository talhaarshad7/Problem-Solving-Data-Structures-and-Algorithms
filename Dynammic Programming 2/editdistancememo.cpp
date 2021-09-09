#include<iostream>
using namespace std;
#include<climits>
int edit(string s,string t,int **output)
{
    int m=s.length();
    int n=t.length();
    if(s.length()==0||t.length()==0)
    return max(s.size(),t.size());
    if(output[m][n]!=-1)
    return output[m][n];
    int ans;
    if(s[0]==t[0])
    ans=edit(s.substr(1),t.substr(1),output);
    else
    {
        //Insert
        int x=1+edit(s.substr(1),t,output);
        //Delete
        int y=1+edit(s,t.substr(1),output);
        //Replace
        int z=1+edit(s.substr(1),t.substr(1),output);
        int ans=min(x,min(y,z));
    }
    output[m][n]=ans;
    return ans;
}
int main()
{
    string s,t;
    cin>>s>>t;
    int m=s.length();
    int n=t.length();
    int **output=new int*[m+1];
    for(int i=0;i<m+1;i++)
    output[i]=new int[n+1];
    for(int i=0;i<s.length()+1;i++)
    for(int j=0;j<t.length()+1;j++)
    output[i][j]=-1;
    cout<<edit(s,t,output)<<endl;
}