#include <iostream>
using namespace std;
#include <cmath>
int count(int n,int *arr)
{
    if (n <= 1)
        return 1;
    int mod = (int)(pow(10, 9)) + 7;
    if(arr[n]!=-1)
    return arr[n];
    int a = count(n - 1,arr);
    int b = count(n - 2,arr);
    int temp1 = (int)(((long)(a)*a) % mod);
    int temp2 = (int)((2 * (long)(a)*b) % mod);
    arr[n] = (temp1 + temp2) % mod;
    return arr[n];
}
int main()
{
    int n;
    cin >> n;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
    arr[i]=-1;
    cout << count(n,arr) << endl;
}