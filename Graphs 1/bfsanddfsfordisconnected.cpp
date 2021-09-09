#include <iostream>
using namespace std;
#include <queue>
void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited);
        }
    }
}
void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete[] visited;
}
void printBFS(int **edges, int n, int sv, bool *visited)
{
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
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete[] visited;
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
    cout << "DFS" << endl;
    DFS(edges, n);
    cout << "BFS" << endl;
    BFS(edges, n);
    for (int i = 0; i < n; i++)
        delete[] edges[i];
}