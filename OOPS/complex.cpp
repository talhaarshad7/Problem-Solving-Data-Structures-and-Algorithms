#include<iostream>
using namespace std;
class Complex
{
    private:
    int real;
    int imag;
    public:
    Complex(int r,int i)
    {
        real=r;
        imag=i;
    }
    void add(Complex const &c1)
    {
        real=real+c1.real;//We can also use this->real in place of real.
        this->imag=imag+c1.imag;//no issue as this->imag == imag.
    }
    void multiply(Complex const &c1)
    {
        int real1=(real*c1.real)-(imag*c1.imag);
        int imag1=(real*c1.imag)+(imag*c1.real);
        real=real1;
        imag=imag1;
    }
    void print()
    {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};