#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator; //Here it is compulsory to use THIS keyword as the parameters and the class memebers are of same name.
        this->denominator = denominator;
    }
    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator); // Here we can also use here this->numerator or this->denominator.But no need.
        for (int i = 2; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0) // Here we can also use here this->numerator or this->denominator.
                gcd = i;
        }
        numerator = numerator / gcd;     // Here we can also use here this->numerator or this->denominator.
        denominator = denominator / gcd; // Here we can also use here this->numerator or this->denominator.
    }
    void add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        numerator = x * numerator + y * f2.numerator;
        denominator = lcm; // Here we can also use here this->numerator or this->denominator.
        simplify();
    }
    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }
    void print()
    {
        cout << this->numerator << "/";
        cout << this->denominator << endl;
    }
};