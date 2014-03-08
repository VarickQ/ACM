#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 105;
const int M = 25100;
const int MOD = 1000000007;
typedef long long ll;

int po[N];
struct Node {
	int x,y,step;
}cu;
bool su[M];
void getprime(){
	su[1] = su[0] = true;
	for(int i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(int j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
}
int cnt;
void init(){
	cnt = 1;
	po[0] = 1;
	for(int i=3 ; i <= 150 ; i+=2)
		po[cnt++] = i*i;
}
inline int getnum(int x,int y){
	int t = max(abs(x),abs(y));
	int s = po[t-1]+1;
	if( x==t && y==t ) return po[t];
	if( x==t ) return po[t]-(t-y);
	if( x==-t ) return s+2*t-1+(t-y);
	if( y==t ) return s+t-1-x;
	if( y==-t ) return po[t]-3*t+x;
}
int ans,v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[505][505];
Node qu[300000];
void bfs(int s,int d,int ed){
	cu.x = s; cu.y = d; cu.step = 0;
	int num,head=0,tail=0;
	qu[tail++] = cu;
	vis[cu.x][cu.y] = true;
	Node f,ff;
	while( head < tail ){
		ff = qu[head++];
		num = getnum(ff.x,ff.y);
		if( num == ed ){
			ans = ff.step;
			return ;
		}
		for(int i=0 ; i < 4 ; ++i)
		{
			f.x = ff.x+v[i][0];
			f.y = ff.y+v[i][1];
			f.step = ff.step+1;
			num = getnum(f.x,f.y);
			if( f.x>=-70 && f.x<=70 && f.y>=-70 && f.y<=70 && su[num]){
				if( !vis[f.x+150][f.y+150] ){
					vis[f.x+150][f.y+150] = true;
					qu[tail++] = f;
				}
			}
		}
	}
}
int main(){
	getprime();
	init();
	int x,y,cs=1;
	while( scanf("%d%d", &x, &y) != EOF ){
		printf("Case %d: ", cs++);
		if( !su[x] || !su[y] ){
			printf("impossible\n");continue;
		}
		int s,d;
		bool f = false;
		for(int i=-70 ; i <= 70 ; ++i){
			for(int j=-70 ; j <= 70 ; ++j){
				if( getnum(i,j) == x ){
					f = true; s = i; d = j;
					break;
				}
			}
			if( f ) break;
		}
		CLR( vis, 0 );
		ans = -1;
		bfs(s,d,y);
		if( ans == -1 ) printf("impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}