#include<iostream>
using namespace std;
bool pal(char *s,int n)
{
    if(n==1||n==0)
    return true;
    bool so=pal(s+1,n-2);
    bool op;
    if(s[0]==s[n-1])
    op=true && so;
    else
    op= false&& so;
    return op;
}
int main()
{
    cout<<pal("abcba",5);
    cout<<pal("abccba",6);
    cout<<pal("abcde",5);
    cout<<pal("abcd",4);
}