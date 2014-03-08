#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
const int N = 301;

int n, a[N][N], M[N][N][9][9];
void RMQ2(){
	int i, j, p, q;
	for( i=0 ; i < n ; ++i )
		for( j=0 ; j < n ; ++j )
			M[i][j][0][0] = a[i][j];
	for( p=0 ; (1<<p) <= n ; ++p ){
		for( q=0 ; (1<<q) <= n ; ++q ){
			if( p==0 && q==0 ) continue;
			for( i=0 ; i+(1<<p)-1 < n ; ++i ){
				for( j=0 ; j+(1<<q)-1 < n ; ++j ){
					if( p == 0 )
						M[i][j][p][q]=min(M[i][j][p][q-1],M[i][j+(1<<(q-1))][p][q-1]);
					else
						M[i][j][p][q]=min(M[i][j][p-1][q],M[i+(1<<(p-1))][j][p-1][q]);
				}
			}
		}
	}
}
int query(int x1,int y1,int x2,int y2){
	int x = log(x2-x1+1.0)/log(2.0);
	int y = log(y2-y1+1.0)/log(2.0);
	int a = M[x1][y1][x][y];
	int b = M[x2-(1<<x)+1][y2-(1<<y)+1][x][y];
	int ret = min( a, b );
	a = M[x1][y2-(1<<y)+1][x][y];
	b = M[x2-(1<<x)+1][y1][x][y];
	ret = min(min( ret, a ), b );
	return ret;
}
int main(){
	int T, q, x1, y1, x2, y2;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < n ; ++j)
				scanf("%d", &a[i][j]);
		RMQ2();
		scanf("%d", &q);
		for(int i=0 ; i < q ; ++i){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n", query(x1-1,y1-1,x2-1,y2-1));
		}
	}
	return 0;
}