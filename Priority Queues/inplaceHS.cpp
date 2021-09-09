#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (a[parentIndex] > a[childIndex])
            {
                int temp = a[parentIndex];
                a[parentIndex] = a[childIndex];
                a[childIndex] = temp;
            }
            else
            break;
            childIndex = parentIndex;
        }
    }
    int size = n;
    for (int i = 0; i < n - 1; i++) //while(size>1)
    {
        int min = a[0];
        a[0] = a[size - 1];
        a[size - 1] = min;
        size--;
        int pi = 0;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        while (lci < size)
        {
            int mi = pi;
            if (a[mi] > a[lci])
                mi = lci;
            if (rci < size && a[mi] > a[rci])
                mi = rci;
            if (mi == pi)
                break;
            int temp = a[mi];
            a[mi] = a[pi];
            a[pi] = temp;
            pi = mi;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}