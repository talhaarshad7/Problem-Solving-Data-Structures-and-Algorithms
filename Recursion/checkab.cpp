#include<iostream>
using namespace std;
int check(string s)
{
    if(s[0]=='\0')
    return 1;
    else
    {
        if(s[0]=='a')
        {
            if(s[1]=='a')
            return check(s.substr(1));
            else if(s[1]=='\0')
            return 1;
            else if(s[1]=='b'&&s[2]=='b')
            return check(s.substr(3));
            else
            return 0;
        }
        else
        return 0;
    }
}
int main()
{
    string s;
    cin>>s;
    if(s[0]=='a')
    {
        int f=check(s);
        if(f==1)
        cout<<"true";
        else
        cout<<"false";
    }
    else
    cout<<"false";
}