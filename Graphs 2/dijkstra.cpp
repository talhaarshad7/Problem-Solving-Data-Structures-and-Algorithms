#include <iostream>
using namespace std;
#include <climits>
int minV(int *dist, bool *visited, int n)
{
    int min = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min == -1 || dist[i] < dist[min]))
            min = i;
    }
    return min;
}
void dijkstra(int **edges, int n)
{
    int *dist = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = minV(dist, visited, n);
        visited[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                int tdist = dist[minVertex] + edges[minVertex][j];
                if (tdist < dist[j])
                {
                    dist[j] = tdist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << i << " " << dist[i] << endl;
    delete[] visited;
    delete[] dist;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    dijkstra(edges, n);
}