//����һ����С������
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

int n,m,mat[N][N],d[N];
bool mark[N];
int ans,Max[N][N],pre[N],s[N];
//Max[i][j]��ʾi ��j·�������ߵ�ֵ
void Prim(){
	int i,j,Min,mi,t=0;
	memset( mark, 0, sizeof( mark ) );
	for( i=1 ; i <= n ; ++i ){
		d[i] = mat[i][1];
		pre[i] = 1;
	}
	d[1] = 0;
	mark[1] = true;
	s[t++] = 1;//������С�������ϵĽڵ�
	for( i=1 ; i < n ; ++i){
		Min = inf; mi = i;
		for( j=1 ; j <= n ; ++j)
			if( !mark[j] && d[j] < Min ){
				Min = d[j];
				mi = j;
			}
		ans += Min;
		mark[mi] = true;
		for( j=0 ; j < t ; ++j )//�����ǰ�ҵ��Ľڵ㵽��С��������ÿһ�����·���ϵ�����
			Max[mi][s[j]]=Max[s[j]][mi]=max(Max[pre[mi]][s[j]],Min);
		s[t++] = mi;
		for( j=1 ; j <= n ; ++j )
			if( !mark[j] && d[j] > mat[mi][j] ){
				d[j] = mat[mi][j];
				pre[j] = mi;
			}
	}
}
int main(){
	int T,a,b,c;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			mat[a][b] = mat[b][a] = c;
		}
		ans = 0;
		Prim();
		int Min = inf;
		for(int i=1 ; i <= n ; ++i)//ö����С��������ı�
			for(int j=1 ; j <= n ; ++j)
				if(i!=j && i!=pre[j] && j!=pre[i] && mat[i][j]!=inf)
					Min = min( mat[i][j]-Max[i][j], Min );
		if( Min ) printf("%d\n", ans);
		else printf("Not Unique!\n");
	}
	return 0;
}
//���������ȳ��ɳڴﵽ�����Ҽ���������
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

int n,m,mat[N][N],d[N];
bool mark[N];
int ans,change[N];
bool Prim(){
	int i,j,Min,mi;
	memset( mark, 0, sizeof( mark ) );
	memset( change, 0, sizeof( change ) );
	for( i=1 ; i <= n ; ++i ){
		d[i] = mat[i][1];
		if( d[i] != inf ) change[i]++;
	}
	d[1] = 0;
	mark[1] = true;
	for( i=1 ; i < n ; ++i){
		Min = inf; mi = i;
		for( j=1 ; j <= n ; ++j)
			if( !mark[j] && d[j] < Min ){
				Min = d[j];
				mi = j;
			}
		ans += Min;
		mark[mi] = true;
		if( change[mi] > 1 ) return false;
		for( j=1 ; j <= n ; ++j )
			if( !mark[j] ){
				if( d[j] > mat[mi][j] ){
					d[j] = mat[mi][j];
					change[j] = 1;
				}
				else if( d[j] == mat[mi][j] )
					change[j] ++;
			}
	}
	return true;
}
int main(){
	int T,a,b,c;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i)
			for(int j=1 ; j <= n ; ++j)
				mat[i][j] = inf;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &a, &b, &c);
			mat[a][b] = mat[b][a] = c;
		}
		ans = 0;
		if( Prim() ) printf("%d\n", ans);
		else printf("Not Unique!\n");
	}
	return 0;
}