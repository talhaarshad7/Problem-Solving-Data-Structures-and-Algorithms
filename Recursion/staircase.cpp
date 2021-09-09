#include<iostream>
using namespace std;
int stcase(int n)
{
    if(n==0)
    return 1;
    else if(n<0)
    return 0;
    else
    {
        return stcase(n-1)+stcase(n-2)+stcase(n-3);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<stcase(n);
}