#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
    unordered_map<int, bool> u;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        u[a[i]] = true;
    int maxLen = 0;
    int start, end;
    unordered_map<int, bool>::iterator it;
    for (it = u.begin(); it != u.end(); it++)
    {
        int x = it->first;
        int t = x;
        int l = 1;
        int s, e;
        e = t;
        if (it->second)
        {
            while (u.count(++t) > 0 && u[t] == true)
            {
                u[t] = false;
                l++;
                e = t;
            }
            t = x;
            s = t;
            while (u.count(--t) > 0 && u[t] == true)
            {
                u[t] = false;
                l++;
                s = t;
            }
        }
        else
        continue;
        if (l > maxLen)
        {
            start = s;
            end = e;
            maxLen = l;
        }
    }
    cout<<start<<" "<<end;
}