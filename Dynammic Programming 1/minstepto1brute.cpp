#include<iostream>
#include<climits>
using namespace std;
int step(int n)
{
    if(n<=1)
    return 0;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    c=step(n-1);
    if(n%3==0)
    a=step(n/3);
    if(n%2==0)
    b=step(n/2);
    return 1+min(a,min(b,c));
}
int main()
{
    int n;
    cin>>n;
    cout<<step(n);
}