#include <iostream>
using namespace std;
void dfs(int **edges, int n, int s, int *visited)
{
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == s)
            continue;
        if (edges[s][i] && visited[i] == false)
        {
            dfs(edges, n, i, visited);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
        edges[i] = new int[n];
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int *visited = new int[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    dfs(edges, n, 0, visited);
    bool c = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            c = false;
            break;
        }
    }
    cout << boolalpha << c << endl;
}