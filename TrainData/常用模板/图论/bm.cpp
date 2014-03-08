//-----------------------------------------------------------------------------
// File: bm.cpp by zybx
//
// Desc: Bipartite Matching
//
// Date: 2004-7-10
//-----------------------------------------------------------------------------

#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647
#define MAX_VERTEX 256

int n, m;
bool adj[MAX_VERTEX][MAX_VERTEX];

int s, p[MAX_VERTEX];
queue<int> q;

int nummat, mat[MAX_VERTEX];
bool set[MAX_VERTEX], visit[MAX_VERTEX];

bool augment()
{
	int u, v;

	for(u = 0; u < n; u++)
		set[u] = false;
	p[s] = -1;
	set[s] = true;
	while(!q.empty())
		q.pop();
	q.push(s);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(v = 0; v < n; v++)
		{
			if(adj[u][v] && !set[v])
			{
				if(mat[v] < 0)
				{
					p[v] = u;
					while(p[v] != s)
					{
						mat[v] = p[v];
						mat[p[v]] = v;
						v = p[p[v]];
					}
					mat[v] = s;
					mat[s] = v;
					nummat++;
					return true;
				}
				else
				{
					p[v] = u;
					set[v] = true;
					p[mat[v]] = v;
					set[mat[v]] = true;
					q.push(mat[v]);
				}
			}
		}
	}

	return false;
}

void bm()
{
	int u;
	bool found = true;

	nummat = 0;
	for(u = 0; u < n; u++)
	{
		mat[u] = -1;
		visit[u] = false;
	}
	while(found)
	{
		found = false;
		for(s = 0; s < n; s++)
		{
			if(!visit[s] && mat[s] < 0)
			{
				visit[s] = true;
				if(augment())
					found = true;
			}
		}
	}
}

int main()
{
	int i, j, k;

	while(cin >> n >> m, n)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
				adj[i][j] = false;
		}
		for(i = 0; i < m; i++)
		{
			cin >> j >> k;
			adj[j][k] = true;
			adj[k][j] = true;
		}
		bm();
		cout << nummat << endl;
	}

	return 0;
}
