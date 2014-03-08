//1007
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N   = 105;

int mat[N][N];
int m,n,d[N],vis[N];
void dijkstra(){
	memset(vis,0,sizeof(vis));
	for(int i=1 ; i <= n ; i++) d[i] = inf;
	d[1] = 0;
	for(int i=1 ; i <= n ; i++)
	{
		int x,Min = inf;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[y] <= Min){
				Min = d[y];
				x = y;
			}
		vis[x] = true;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[x]+mat[x][y] < d[y])
				d[y] = d[x] + mat[x][y];
	}
}
int main(){
	int a,b,c;
	while( scanf("%d%d", &n, &m) && (n+m) ){
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if( mat[a][b] > c )
				mat[a][b] = mat[b][a] = c;
		}
		dijkstra();
		printf("%d\n", d[n]);
	}
	return 0;
}
//1006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N   = 1005;

int t,n;
int mat[N][N],d[N];
int qu[N*100];
bool v[N];
void spfa( int x ){
	memset( v, 0, sizeof( v ) );
	int i,head=0,tail=1;
	for( i=1 ; i <= n ; ++i )
		d[i] = inf;
	d[x] = 0;
	qu[0] = x;
	while( tail > head ){
		int u = qu[head];
		v[u] = true;
		for( i=1 ; i <= n ; ++i ){
			if( mat[u][i] && d[i]>d[u]+mat[u][i] ){
				d[i] = d[u]+mat[u][i];
				if( !v[i] ){
					v[i] = true;
					qu[tail++] = i;
				}
			}
		}
		v[u] = false;
		head++;
	}
}
int main(){
	int a,b,c;
	while( scanf("%d%d", &t, &n) == 2 ){
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < t ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if( mat[a][b] > c )
				mat[a][b] = mat[b][a] = c;
		}
		spfa( n );
		printf("%d\n", d[1]);
	}
	return 0;
}
//1003 差分约束
#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 10000000;
const int N = 10005;

struct A{
	int v,c,next;
}e[N*5];
int k,ed,heade[N],d[N];
int qu[N*100];
bool inqu[N];

void add(int u,int v,int w){
	e[k].v = v;
	e[k].c = w;
	e[k].next = heade[u];
	heade[u] = k++;
}

void spfa(){
	for(int i=1 ; i <= ed ; i++)
		d[i] = -inf;
	d[0] = 0;
	int head=0,tail=1;
	qu[0] = 0;
	while(tail > head){
		int u = qu[head];
		inqu[u] = true;
		for(int i=heade[u] ; i != 0 ; i=e[i].next){
			int v = e[i].v;
			if(d[v] < d[u] + e[i].c){
				d[v] = d[u] + e[i].c;
				if(!inqu[v]){
					inqu[v] = true;
					qu[tail++] = v;
				}
			}
		}
		inqu[u]=false;
		head++;
	}
}
int main()
{
	int i,a,b,n;
	ed = 0;
	k = 1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(b+1 > ed)ed = b+1;
		add(a,b+1,2);//2<=S[b+1]-S[a] 区间内至少要有两个
	}
	for(i=0 ; i <= ed ; i++)
	{
		add(i,i+1,0);//S[i+1] >= S[i] 在i+1的位置的个数一定比i处大
		add(i+1,i,-1);//S[i]+1>=S[i+1] 却一定小余等于在i处的个数+1
	}
	spfa();
	printf("%d\n",d[ed]);
	return 0;
}
//1005 最长路限制
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N   = 1005;

int mat[N][N];
int m,n,d[N],vis[N];
void dijkstra(){
	memset(vis,0,sizeof(vis));
	d[1] = inf;
	for(int i=1 ; i <= n ; i++)
	{
		int x,Max = 0;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[y] >= Max){
				Max = d[y];
				x = y;
			}
		vis[x] = true;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && min(d[x],mat[x][y]) > d[y])
				d[y] = min(d[x],mat[x][y]);
	}
}
int main(){
	int T, cs=1;
	int a,b,c;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		memset( mat, 0, sizeof( mat ) );
		memset( d, 0, sizeof( d ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			mat[a][b] = mat[b][a] = c;
		}
		dijkstra();
		printf("Scenario #%d:\n%d\n\n", cs++, d[n]);
	}
	//printf("\n");
	return 0;
}