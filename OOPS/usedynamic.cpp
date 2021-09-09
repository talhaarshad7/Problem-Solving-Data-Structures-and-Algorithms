#include<iostream>
using namespace std;
#include "dynamicarray.cpp"
int main()
{
    DynamicArray d1;
    d1.add(1);
    d1.add(2);
    d1.add(3);
    d1.add(4);
    d1.add(5);
    d1.add(6);
    d1.display();
    DynamicArray d2=d1;
    d2.data[0]=9;
    d2.display();
    d1.display();
    DynamicArray d3(d1);
    d3.display();
}