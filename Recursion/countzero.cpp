#include<iostream>
using namespace std;
int zero(int n)
{
    if(n==0)
    return 0;
    int d=n%10;
    int so=zero(n/10);
    if(d==0)
    return 1+so;
    else 
    return 0+so;
}
int main()
{
    cout<<zero(10024203);
}