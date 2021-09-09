#include<iostream>
using namespace std;
void toh(int n,char s,char a,char d)
{
    if(n==1)
    cout<<s<<" "<<d<<endl;
    else
    {
        toh(n-1,s,d,a);
        cout<<s<<" "<<d<<endl;
        toh(n-1,a,s,d);
    }
}
int main()
{
    toh(3,'a','b','c');
}