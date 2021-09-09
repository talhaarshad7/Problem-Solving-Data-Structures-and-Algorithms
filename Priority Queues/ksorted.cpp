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
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(a[i]);
    int j = 0;
    for (int i = k; i < n; i++)
    {
        a[j] = pq.top();
        pq.pop();
        j++;
        pq.push(a[i]);
    }
    while (!pq.empty())
    {
        a[j++] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}