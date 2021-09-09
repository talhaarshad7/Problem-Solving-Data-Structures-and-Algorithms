#include<iostream>
using namespace std;
bool hasPath(int **edges,int n,int c,int d,int *visited)
{
    if(c==d)
    return 1;
    int result =0;
    for(int i=0;i<n;i++)
    {
        if(i==c)
        continue;
        if(edges[c][i]&&!visited[i])
        {
            visited[i]=1;
            int x=hasPath(edges,n,i,d,visited);
            if(x)
            return x;
        }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, e;
	cin>>n>>e;

	int** edges = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}

	}

	int* visited = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin>>a>>b;

		edges[a][b] = 1;
		edges[b][a] = 1;
	}

	int c, d;
	cin>>c>>d;

	if(hasPath(edges, n, c, d, visited)){
		cout << "true" << '\n';
	}else{
		cout << "false" << '\n';
	}

	return 0 ; 
;
}