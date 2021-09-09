#include<iostream>
using namespace std;
#include"complex.cpp"
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Complex c1(a,b);
    Complex c2(c,d);
    int s;
    cin>>s;
    if(s==1)
    {
        c1.add(c2);
        c1.print();
    }
    else if(s==2)
    {
        c1.multiply(c2);
        c1.print();
    }
}