#include<bits/stdc++.h>
using namespace std;
int stoi(string s,int n)
{
    if(n==1)
    return ((int)(s[0]-48));
    int so=stoi(s.substr(1),n-1);
    int op=(((int)(s[0]-48))*pow(10,n-1))+so;
    return op;
}
int main()
{
    string c;
    cin>>c;
    int n=c.length();
    int num=stoi(c,n);
    cout<<num;
}