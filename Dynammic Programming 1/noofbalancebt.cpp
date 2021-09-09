#include <iostream>
using namespace std;
#include <cmath>
int count(int n)
{
    if (n <= 1)
        return 1;
    int mod = (int)(pow(10, 9)) + 7;
    int a = count(n - 1);
    int b = count(n - 2);
    int temp1 = (int)(((long)(a)*a) % mod);
    int temp2 = (int)((2 * (long)(a)*b) % mod);
    int ans = (temp1 + temp2) % mod;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
}