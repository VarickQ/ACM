//A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int M   = 20100;
const int N   = 105;

int a[N];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,cs=1,n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		sort(a,a+n);
		int Max = -1;
		for(int i=1 ; i < n ; ++i)
			if( a[i]-a[i-1] > Max )
				Max = a[i]-a[i-1];
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", cs++,a[n-1],a[0],Max);
	}
	return 0;
}
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int M   = 20100;
const int N   = 105;


int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,cs=1,n,y1,y2,y3,y4;
	char str[1000];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d\n", &n);
		y1 = y2 = y3 = y4 = 0;
		for(int j,i=0 ; i < n ; ++i){
			CLR( str, 0 );
			gets(str);
			bool f = false;
			for( j=0 ; str[j] ; ++j )
				if( str[j]==' ' ){
					f=true; break;
				}
			j++;
			if(f) f = false;
			else{
				y4++; continue;
			}
			//scanf("%s", str);
			int lim = 0;
			while( lim < 5 ){
				if( str[j]=='y' ){
					if( lim==0 ) y1++;
					else y2++;
					f = true;
				}
				for( ; str[j] ; ++j )
					if( str[j]==' ' ) break;
				j++;
				lim++;
			}
			if( !f ) y3++;
		}
		printf("Roll-call: %d\n", cs++);
		printf("Present: %d out of %d\n",y1,n);
		printf("Needs to study at home: %d out of %d\n",y2,n);
		printf("Needs remedial work after school: %d out of %d\n",y3,n);
		printf("Absent: %d out of %d\n",y4,n);
	}
	return 0;
}
//B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int M   = 20100;
const int N   = 105;

struct A{
	int a,b,t;
}x[5];
int judge(A a, A b){
	int d = abs(a.t-b.t);
	d = min( d, 12*60-d );
	return d;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,cs=1;
	scanf("%d", &T);
	while( T-- ){
		for(int i=0 ; i < 3 ; ++i){
			scanf("%d:%d", &x[i].a, &x[i].b);
			x[i].t = x[i].a*60+x[i].b;
		}
		int ans,cnt=0;
		if(judge(x[0],x[1]) == judge(x[0],x[2])){
			cnt++; ans = 0;
		}
		if(judge(x[1],x[0]) == judge(x[1],x[2])){
			cnt++; ans = 1;
		}
		if(judge(x[2],x[1]) == judge(x[2],x[0])){
			cnt++; ans = 2;
		}
		if( cnt != 1 )
			printf("Look at the sun\n");
		else
			printf("The correct time is %d:%02d\n",x[ans].a,x[ans].b);
	}
	return 0;
}
//J
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int M   = 360100;
const int N   = 650;

int Mat[N][N],id[N][N],Match[M];
bool mark[N][N],vis[M];
int n,dd;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool check(int x,int y){
	if( x>=1 && x<=n && y>=1 && y<=n && mark[x][y] )
		return true;
	return false;
}
bool find(int i){
	for(int j=1 ; j <= dd ; ++j){
		if( Mat[i][j] && !vis[j] ){
			vis[j] = true;
			if( Match[j]==0 || find(Match[j]) ){
				Match[j] = i;
				return true;
			}
		}
	}
	return false;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T,cs=1;
	char str[N];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		CLR( Mat, 0 );
		CLR( mark, 0 );
		for(int i=1 ; i <= n ; ++i){
			scanf("%s",str);
			for(int j=0 ; str[j] ; ++j)
				if( str[j] == '#' )
					mark[i][j+1] = true;
		}
		dd = 0;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				id[i][j] = ++dd;
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j){
				if( mark[i][j] ){
					int x,y;
					for(int v=0 ; v < 4 ; ++v){
						x = i+dir[v][0];
						y = j+dir[v][1];
						if( check(x,y) )
							Mat[id[i][j]][id[x][y]] = 1;
					}
				}
			}
		CLR( Match, 0 );
		int ans = 0;
		for(int i=1 ; i <= dd ; ++i){
			CLR( vis, 0 );
			if( find(i) ) ans++;
		}
		printf("Case %d: %d\n", cs++, ans/2);
	}
	return 0;
}
//H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 305000;
const int N = 30500;

struct A{
	double p,x,y,r;
}a[N];
bool check(A a,A b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))<=(a.r+b.r);
}
int n;
struct edge{
	int from,to,val,next;
}e[M];
int w[N],que[M],dis[N],edge,cur[N];
void add(int from,int to,int va){
    e[edge].from=from;
	e[edge].to=to;
	e[edge].val=va;
    e[edge].next=w[from];
	w[from]=edge++;

    e[edge].from=to;
	e[edge].to=from;
	e[edge].val=0;
    e[edge].next=w[to];
	w[to]=edge++;
}
int bfs(int n,int s,int t){
    int head,tail,id;
    head=tail=0;que[tail++]=s;
    memset(dis,-1,sizeof(int)*n);
	dis[s]=0;
	while(head<tail) // bfs,得到顶点i的距s的最短距离dis[i]
	{
		for(id=w[que[head++]];id!=-1;id=e[id].next)
			if(e[id].val>0&&dis[e[id].to]==-1)
            {
				dis[e[id].to]=dis[e[id].from]+1;
                que[tail++]=e[id].to;
                if(e[id].to==t) return 1;
            }
	}
    return 0;
}
int Dinic(int n,int s,int t){//0~n-1
    int Mflow=0,tmp,i;
    while(bfs(n,s,t)){
        int u=s,tail=0;
        for(i=0;i<n;i++) cur[i]=w[i];
        while(cur[s]!=-1){
			if(u!=t&&cur[u]!=-1&&e[cur[u]].val>0&&dis[u]!=-1&&dis[u]+1==dis[e[cur[u]].to]){
				que[tail++]=cur[u];
				u=e[cur[u]].to;
			}
            else if(u==t){
                for(tmp=inf,i=tail-1;i>=0;i--)
					tmp=min(tmp,e[que[i]].val);
                for(Mflow+=tmp,i=tail-1;i>=0;i--){
                    e[que[i]].val-=tmp;
                    e[que[i]^1].val+=tmp;
                    if(e[que[i]].val==0) tail=i;
                }
                u=e[que[tail]].from;
            }
            else{
                while(tail>0&&u!=s&&cur[u]==-1) u=e[que[--tail]].from;
                cur[u]=e[cur[u]].next;
            }
		}
    }
    return Mflow;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		memset(w,-1,sizeof(w));
		edge=0;
		int s=0,t=n+1;
		for(int i=1 ; i <= n ; ++i){
			scanf("%lf%lf%lf%lf",&a[i].p,&a[i].x,&a[i].y,&a[i].r);
			if( fabs(a[i].p-400) < eps )
				add( s, i, 2 );
			else if( fabs(a[i].p-789.0) < eps )
				add( i, t, 2 );
		}
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= n ; ++j)
				if( i!=j && check(a[i],a[j]) && a[i].p<a[j].p)
						add(i,j,1);
		}
		if( 2 == Dinic(t+1,s,t) )
			printf("Game is VALID\n");
		else printf("Game is NOT VALID\n");
	}
	return 0;
}
