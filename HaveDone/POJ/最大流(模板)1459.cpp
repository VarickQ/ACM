//邻接阵 和 邻接表
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define min( a, b ) ((a)<(b)?(a):(b))
const int inf = 1000000000;
const int M = 15000;
const int N = 105;
//typedef long long ll;

int n,np,nc,m,ans;
int map[N][N];
int que[M],pre[N];
bool vis[N];

bool bfs(){                   //  bfs求增广路径。
    int head, tail;
    memset(vis, 0, sizeof(vis));
    head = tail = 1;
    que[tail ++] = n;
    vis[n] = true;
    while(tail > head){
        int u = que[head ++];
        for(int i = 0; i <= n + 1; i ++){
            if(!vis[i] && map[u][i]){
                pre[i] = u;
                if(i == n + 1) return true;
                que[tail ++] = i;
                vis[i] = true;
            }
        }
    }
    return false;
}
 
void end(){                   //  end注满增广路径。
    int i, sum = inf;
    for(i = n + 1; i != n; i = pre[i])
        sum = min(sum, map[pre[i]][i]);
    for(i = n + 1; i != n; i = pre[i]){
        map[pre[i]][i] -= sum;
        map[i][pre[i]] += sum;//  逆的边要再增加。
    }
    ans += sum;
}

int main(){
	int u,v,z;
	while( scanf("%d%d%d%d",&n,&np,&nc,&m) != EOF ){
		memset( map, 0, sizeof( map ) );
		while( m-- ){
			while(getchar() != '(');
			scanf("%d,%d)%d", &u, &v, &z);
			map[u][v] += z;
		}
		while( np-- ){
			while(getchar() != '(');
			scanf("%d)%d", &u, &z);
			map[n][u] = z;
		}
		while( nc-- ){
			while(getchar() != '(');
			scanf("%d)%d", &u, &z);
			map[u][n+1] = z;
		}
		ans = 0;
		while( bfs() ) end();
		printf("%d\n", ans);
	}
	return 0;
}




//邻接表
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define min( a, b ) ((a)<(b)?(a):(b))
const int inf = 1000000000;
const int M = 150000;
const int N = 105;
//typedef long long ll;

int n,np,nc,m,ans;
struct A{
	int u,v,w,next,re;
}a[M];
int heade[N],k;
int qu[M],pre[M];
bool vis[N];
void add( int u, int v, int c ){
	a[k].u = u;
	a[k].v = v;
	a[k].w = c;
	a[k].next = heade[u];
	a[k].re = k+1;
	heade[u] = k++;

	a[k].u = v;
	a[k].v = u;
	a[k].w = 0;
	a[k].next = heade[v];
	a[k].re = k-1;
	heade[v] = k++;
}
bool EK(){
	int head,tail,i,u,v;
	memset(vis,0,sizeof(vis));
	head = tail = 1;
	qu[tail++] = n;
	vis[n] = true;
	while(head < tail){
		u = qu[head++];
		for(i=heade[u] ; i!=-1 ; i=a[i].next){
			v = a[i].v;
			if(!vis[v] && a[i].w){
				pre[v] = i;
				if(v == n+1) return true;
				qu[tail++] = v;
				vis[v] = true;
			}
		}
	}
	return false;
}
void end(){
	int i, sum = inf, kk=k;
	for( i=n+1 ; i != n ; i=a[a[kk].re].v){
		kk = pre[i];
		sum = min( sum, a[kk].w);
	}
	for( i=n+1 ; i != n ; i=a[a[k].re].v){
		k = pre[i];
		a[k].w -= sum;
		a[a[k].re].w += sum;
	}
	ans += sum;
}

int main(){
	int u,v,z;
	while( scanf("%d%d%d%d",&n,&np,&nc,&m) != EOF ){
		memset( heade, -1, sizeof( heade ) );
		while( m-- ){
			while(getchar() != '(');
			scanf("%d,%d)%d", &u, &v, &z);
			add( u, v, z );
		}
		while( np-- ){
			while(getchar() != '(');
			scanf("%d)%d", &u, &z);
			add( n, u, z );
		}
		while( nc-- ){
			while(getchar() != '(');
			scanf("%d)%d", &u, &z);
			add( u, n+1, z );
		}
		ans = 0;
		while( EK() ) end();
		printf("%d\n", ans);
	}
	return 0;
}