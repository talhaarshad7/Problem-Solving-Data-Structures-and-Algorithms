#include <iostream>
using namespace std;
#include <queue>
#include <unordered_map>
vector<int> *component(int **edges, int n, int s, bool *visited)
{
    queue<int> pending;
    pending.push(s);
    visited[s] = true;
    vector<int> *temp = new vector<int>;
    while (pending.size() != 0)
    {
        int f = pending.front();
        pending.pop();
        temp->push_back(f);
        for (int i = 0; i < n; i++)
        {
            if (i == f)
                continue;
            if (edges[f][i] && !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
    return temp;
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
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            vector<int> *c = component(edges, n, i, visited);
            for (int i = 0; i < c->size(); i++)
                cout << c->at(i) << " ";
            cout << endl;
        }
    }
}