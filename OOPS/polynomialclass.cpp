#include <iostream>
using namespace std;
class Polynomial
{
public:
    int *a;
    int size;
    Polynomial()
    {
        a = new int[5];
        size = 5;
        for (int i = 0; i < size; i++)
            a[i] = 0;
    }
    Polynomial(Polynomial const &p)
    {
        a = new int[p.size];
        for (int i = 0; i < p.size; i++)
            a[i] = p.a[i];
        size = p.size;
    }
    void setCoefficient(int degree, int coefficient)
    {
        while (!(degree < size))
        {
            int *newA = new int[size * 2];
            for (int i = 0; i < size; i++)
                for (int i = 0; i < size * 2; i++)
                    newA[i] = 0;
            for (int i = 0; i < size; i++)
                newA[i] = a[i];
            size *= 2;
            delete[] a;
            a = newA;
        }
        a[degree] = coefficient;
    }
    Polynomial operator+(Polynomial const &p) const
    {
        Polynomial r;
        int n = min(size, p.size);
        for (int i = 0; i < n; i++)
        {
            int c = a[i] + p.a[i];
            r.setCoefficient(i, c);
        }
        int m = max(size, p.size);
        for (int i = n; i < m; i++)
        {
            if (size < p.size)
                r.setCoefficient(i, p.a[i]);
            else
                r.setCoefficient(i, a[i]);
        }
        return r;
    }
    Polynomial operator-(Polynomial const &p) const
    {
        Polynomial r;
        int n = min(size, p.size);
        for (int i = 0; i < n; i++)
        {
            int c = a[i] - p.a[i];
            r.setCoefficient(i, c);
        }
        int m = max(size, p.size);
        for (int i = n; i < m; i++)
        {
            if (size < p.size)
                r.setCoefficient(i, p.a[i]);
            else
                r.setCoefficient(i, a[i]);
        }
        return r;
    }
    Polynomial operator*(Polynomial const &p) const
    {
        Polynomial r;
        int s = size * p.size;
        int k = 0;
        for(int i=0;i<s;i++)
        r.setCoefficient(i,0);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < p.size; j++)
            {
                if (a[i] != 0 && p.a[j] != 0)
                {
                    r.a[i + j] += a[i] * p.a[j];
                }
            }
        }
        return r;
    }
    void operator=(Polynomial const &f)
    {
        for (int i = 0; i < size; i++)
            a[i] = 0;
        for (int i = 0; i < f.size; i++)
            this->setCoefficient(i, f.a[i]);
        size = f.size;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i] != 0)
                cout << a[i] << "x" << i << " ";
        }
        cout << endl;
    }
};