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
const int inf = 1000000000;
const int M = 1000200;
const int N = 205;

int n,m,in[N],ans[N];
struct A{
	int v,next;
}e[40005];
int heade[N],k;
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
priority_queue<int> qu;
bool topsort(){
	int i,j;
	for( i=1 ; i <= n ; ++i )
		if(in[i] == 0)
			qu.push(i);
	for( i=n ; i >= 1 ; --i ){
		if( qu.empty() ) return false;
		int u = qu.top(); qu.pop();
		ans[u] = i;
		for( j=heade[u] ; j!=-1 ; j=e[j].next )
			if(--in[e[j].v] == 0 )
				qu.push(e[j].v);
	}
	return true;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		memset( in, 0, sizeof(in) );
		memset( ans, 0, sizeof( ans ) );
		memset( heade, -1, sizeof( heade ) );
		k = 0;
		scanf("%d%d", &n, &m);
		int a,b;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &a, &b);
			add( b, a );
			in[a]++;
		}
		if( !topsort() ) printf("-1\n");
		else {
			for(int i=1 ; i < n ; ++i)
				printf("%d ", ans[i]);
			printf("%d\n", ans[n]);
		}
	}
	return 0;
}