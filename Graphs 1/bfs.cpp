#include <iostream>
using namespace std;
#include <queue>
void bfs(int **edges, int n, int sv)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    while (pendingNodes.size() != 0)
    {
        int f = pendingNodes.front();
        pendingNodes.pop();
        cout << f << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == f)
                continue;
            if (edges[f][i] == 1 && !visited[i])
            {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
        edges[i] = new int[v];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            edges[i][j] = 0;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bfs(edges, v, 0);
    for (int i = 0; i < v; i++)
        delete[] edges[i];
}