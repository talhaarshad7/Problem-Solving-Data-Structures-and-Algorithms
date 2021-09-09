#include<iostream>
using namespace std;
#include<queue>
void rev(queue<int> &q)
{
    if(q.size()==1)
    return;
    int x=q.front();
    q.pop();
    rev(q);
    q.push(x);
}
void solve()
{
    queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        q.push(c);
    }
    rev(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
  int testcase;
  cin>>testcase;
  while(testcase--)
  solve();
}