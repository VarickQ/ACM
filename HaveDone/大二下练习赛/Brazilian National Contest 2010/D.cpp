//D by zxp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 0x3f3f3f3f
const int N = 300;
int mat[N][N];
int dis[N];
int n, c;

void my_swap(int &a, int &b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int SPFA(int x)
{
	queue<int> Q;
	int v, u, i, j;
	bool vis[N] = {false};
	for(i = 0; i < n; ++ i)
		dis[i] = INF;
	Q.push(x);
	dis[x] = 0;
	vis[x] = true;
	while(!Q.empty())
	{
		v = Q.front();
		Q.pop();
		vis[v] = false;
		for(u = 0; u < n; ++ u)
		{
			if(dis[u] > dis[v] + mat[v][u])
			{
				dis[u] = dis[v] + mat[v][u];
				if(vis[u] == false)
				{
					Q.push(u);
					vis[u] = true;
				}
			}
		}
	}
	return dis[c - 1];
}

int main (){
	int m, k, u, v, cost;
	while (scanf ("%d%d%d%d", &n, &m, &c, &k) != EOF){
		if (n + m + c + k == 0)
			break;
		memset (mat, 0x3f3f, sizeof (mat));
		while (m --){
			scanf ("%d%d%d", &u, &v, &cost);
			if (u > v)
				my_swap(u, v);
			if (u < c){
				if (v < c){
					if (v == u + 1)
						mat[u][v] = cost;
				}
				else if (v >= c) mat[v][u] = cost;
			}
			else{
				mat[u][v] = mat[v][u] = cost;
			}
		}
		printf ("%d\n", SPFA(k));
	}
	return 0;
}