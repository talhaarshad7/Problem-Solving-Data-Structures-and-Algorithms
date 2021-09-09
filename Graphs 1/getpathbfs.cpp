#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
vector<int> *getPath(int **edges, int n, int s, int e, bool *visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(s);
    visited[s] = true;
    bool found = false;
    unordered_map<int, int> m;
    while (pendingNodes.size() != 0)
    {
        int f = pendingNodes.front();
        pendingNodes.pop();
        if (f == e)
        {
            found = true;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == f)
                continue;
            if (edges[f][i] && visited[i] != true)
            {
                pendingNodes.push(i);
                visited[i] = true;
                m[i] = f;
            }
        }
    }
    if (found)
    {
        vector<int> *temp = new vector<int>;
        int current = e;
        temp->push_back(e);
        while (current != s)
        {
            current = m[current];
            temp->push_back(current);
        }
        return temp;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
        edges[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool(n);
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int sv, ev;
    cin >> sv >> ev;
    vector<int> *temp = getPath(edges, n, sv, ev, visited);
    if (temp != NULL)
    {
        for (int i = 0; i < temp->size(); i++)
            cout << temp->at(i) << " ";
    }
}