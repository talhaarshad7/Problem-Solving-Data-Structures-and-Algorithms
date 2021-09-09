#include<iostream>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    r--;
    c--;
    int f=r/2;
    int s;
    if(r%2==0)
    s=2*c;
    else
    s=2*c+1;
    int final=f*10+s;
    cout<<final;

}