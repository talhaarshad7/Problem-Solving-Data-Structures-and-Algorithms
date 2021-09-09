#include <iostream>
using namespace std;
#include <unordered_map>
void solve()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[a[i]]++;
    n=min(n,m);
    for(int i=0;i<n;i++)
    {
        if(freq[b[i]]>0)
        {
            cout<<b[i]<<" ";
            freq[b[i]]--;
        }
    }
    cout << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}