#include<bits/stdc++.h>
using namespace std;
double geo(int k)
{
    if(k==0)
    return 1.0;
    double op=(1.0/(double)pow(2,k))+geo(k-1);
    return op;
}
int main()
{
    cout<<geo(3)<<endl;
    cout<<geo(4)<<endl;
}