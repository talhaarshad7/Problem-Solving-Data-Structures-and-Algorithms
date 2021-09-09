#include <iostream>
using namespace std;
#include <algorithm>
class edge
{
public:
    int source, dest, weight;
};
bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}
int findParent(int v, int *parent)

{
    if (parent[v] == v)
        return v;
    findParent(parent[v], parent);
}
void kruskals(edge *input, int n, int e)
{
    //sort the input array basis of weights
    sort(input, input + e, compare);
    edge *output = new edge[n - 1];
    int count = 0;
    int i = 0;
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
    while (count != n - 1)
    {
        edge currentEdge = input[i];
        //check if we can add this edge in mst or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);
        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        else
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    edge *edges = new edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edges[i].source = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }
    kruskals(edges, n, e);
}