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

char str[20][20],s[N*2][20];
bool mat[20][20],edm[20],stm[20],f;
int st,ed,len,p,ans[20],temp[20],Max;
int cmp( const void *a , const void *b ){
    return strcmp( (char*)a, (char*)b );
}
void dfs( int u, int l ){
	if( u == ed ){
		if( l > Max ){
			for(int i=0 ; i <= l ; ++i)
				ans[i] = temp[i];
			Max = l;
		}
		if( Max == p-1 ) f = true;
		return ;
	}
	stm[u] = false;
	for(int i=1 ; i <= len ; ++i){
		if( mat[u][i] && stm[i] ){
			temp[l+1] = i;
			dfs( i, l+1 );
			if( f ) return;
		}
	}
	stm[u] = true;
}
void dfslt( int u ){
	stm[u] = true;
	for(int i=1 ; i <= len ; ++i)
		if( mat[u][i] ){
			if(i==st||i==ed) stm[i] = true;
			else if( !stm[i] ) dfslt(i);
		}
}
void slove(){
	//ÅÐ¶ÏÁ¬Í¨ÐÔ
	memset( stm, 0, sizeof( stm ) );
	dfslt(ed);
	for(int i=1 ; i <= len ; ++i)
		edm[i] = stm[i];
	memset( stm, 0, sizeof( stm ) );
	dfslt(st);

	p = 0;
	for(int i=1 ; i <= len ; ++i)
		if( !edm[i] ) stm[i]=false;
		else if( stm[i] ) p++;
	if( !stm[ed] ){
		printf("what a pity\n"); return;
	}
	temp[0] = st;
	Max = 0;
	f = false;
	dfs( st, 0 );
	for(int i=0 ; i < Max ; ++i)
		printf("%s ", str[ans[i]]);
	printf("%s\n",str[ans[Max]]);
}
int main(){
	int T,n,cs=1,u,v;
	bool find;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		st = ed = -1;
		len = 0;
		u = 2*n;
		for(int i=1 ; i <= u ; ++i){
			scanf("%s", s[i]);
			find = false;
			for(int j=1 ; j <= len ; ++j)
				if( !strcmp(s[i],str[j]) ){
					find = true; break;
				}
			if( !find ){
				len++;
				strcpy( str[len], s[i] );
			}
		}
		//sort( str, str+len, cmp );
		qsort( str[1], len, sizeof( char )*20, cmp );
		memset( mat, 0, sizeof( mat ) );
		for(int i=1 ; i <= n ; ++i){
			for(int j=1 ; j <= len ; ++j){
				if( !strcmp(s[i*2-1],str[j]) ) u=j;
				if( !strcmp(s[i*2],str[j])) v=j;
			}
			mat[u][v] = mat[v][u] = true;
		}
		for(int i=1 ; i <= len ; ++i){
			if( !strcmp(str[i],"sea") ) st=i;
			if( !strcmp(str[i],"sky") ) ed=i;
		}
		printf("Case %d: ", cs++);
		if( st==-1 || ed==-1 )
			printf("what a pity\n");
		else slove();
	}
	return 0;
} 