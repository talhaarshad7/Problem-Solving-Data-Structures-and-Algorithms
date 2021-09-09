#include <iostream>
using namespace std;
#include "polynomialclass.cpp"
int main()
{
    int n;
    cin >> n;
    int *d1 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> d1[i];
    int *c1 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> c1[i];
    int m;
    cin >> m;
    int *d2 = new int[m];
    for (int i = 0; i < m; i++)
        cin >> d2[i];
    int *c2 = new int[m];
    for (int i = 0; i < m; i++)
        cin >> c2[i];
    Polynomial p, q;
    for (int i = 0; i < n; i++)
        p.setCoefficient(d1[i], c1[i]);
    for (int i = 0; i < m; i++)
        q.setCoefficient(d2[i], c2[i]);
    int c;
    cin >> c;
    Polynomial r;
    switch (c)
    {
    case 1:
        r = p + q;
        r.print();
        break;
    case 2:
        r = p - q;
        r.print();
        break;
    case 3:
        r = p * q;
        r.print();
        break;
    case 4:
        p = q;
        p.print();
        break;
    }
    delete [] c1,c2,d1,d2;
}