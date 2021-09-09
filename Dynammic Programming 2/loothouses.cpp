#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *dp = new int[n + 1];
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n + 1; i++)
        dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
    cout << dp[n] << endl;
}