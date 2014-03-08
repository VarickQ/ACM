请参考08年国家集训队论文—— 俞华程《矩阵乘法在信息学中的应用》
线性代数中有这样的结论：01邻接矩阵A的K次方C=A^K，C[i][j]表示i点到j点正好经过K条边的路径数。
根据Floyd算法的特殊性，它是通过插入点的方法来找到最短路的，特别适合此题，假如我们插入N-1个点，求到的则是经过N条边的最短路。假设我们每一次floyd只插入一个点的话，那么单步Floyd N次的话，则可以插入N个点。
/*Floyd(倍增法)*/
/*N次Floyd*/
/*求从S到E恰好经过N条边(可重复走)的最短路。*/
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 105;
const int N   = 205;
typedef long long ll;

int n,t,s,e,cnt;
int v[1005];
int mat[N][N],ans[N][N],temp[N][N];

void init(){
	for(int i=0 ; i < N ; ++i){
		for(int j=0 ; j < N ; ++j)
			mat[i][j]=temp[i][j]=ans[i][j]=inf;
		ans[i][i] = 0;
	}
	memset( v, 0, sizeof( v ) );
	cnt = 0;
	int l,a,b;
	for(int i=0 ; i < t ; ++i){
		scanf("%d%d%d", &l, &a, &b);
		if( v[a] == 0 )//离散化
			v[a] = ++cnt;
		if( v[b] == 0 )
			v[b] = ++cnt;
		if( mat[v[a]][v[b]] > l )
			mat[v[a]][v[b]] = mat[v[b]][v[a]] = l;
	}
}
void floyd(int a[N][N],int b[N][N],int c[N][N]){
	int i,j,k;
	for( i=1 ; i <= cnt ; ++i )
		for( j=1 ; j <= cnt ; ++j )
			for( k=1 ; k <= cnt ; ++k )
				if( a[i][j] > b[i][k]+c[k][j] )
					a[i][j] = b[i][k]+c[k][j];
}
void copy(int a[N][N],int b[N][N]){
	for(int i=1 ; i <= cnt ; ++i)
		for(int j=1 ; j <= cnt ; ++j){
			a[i][j] = b[i][j];
			b[i][j] = inf;
		}
}
void solve(int n){//n次floyd
	while( n ){
		if( n&1 ){
			floyd(temp,ans,mat);
			copy(ans,temp);//更新答案图
		}
		floyd(temp,mat,mat);
		copy(mat,temp);//修改图
		n >>= 1;
	}
}
int main(){
	while( scanf("%d%d%d%d", &n,&t,&s,&e) != EOF ){
		init();
		solve(n);
		printf("%d\n", ans[v[s]][v[e]]);
	}
	return 0;
}