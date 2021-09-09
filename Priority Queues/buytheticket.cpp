#include <iostream>
using namespace std;
#include <queue>
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    int t = 0;
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
        q.push(a[i]);
    }
    while (k != -2)
    {
        if (k == -1)
            k = n - 1;
        if (q.front() >= pq.top())
        {
            pq.pop();
            q.pop();
            t++;
            if(k==0)
            break;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        k--;
    }
    cout<<t;
}