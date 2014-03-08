��ο�08����Ҽ�ѵ�����ġ��� �Ừ�̡�����˷�����Ϣѧ�е�Ӧ�á�
���Դ������������Ľ��ۣ�01�ڽӾ���A��K�η�C=A^K��C[i][j]��ʾi�㵽j�����þ���K���ߵ�·������
����Floyd�㷨�������ԣ�����ͨ�������ķ������ҵ����·�ģ��ر��ʺϴ��⣬�������ǲ���N-1���㣬�󵽵����Ǿ���N���ߵ����·����������ÿһ��floydֻ����һ����Ļ�����ô����Floyd N�εĻ�������Բ���N���㡣
/*Floyd(������)*/
/*N��Floyd*/
/*���S��Eǡ�þ���N����(���ظ���)�����·��*/
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
		if( v[a] == 0 )//��ɢ��
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
void solve(int n){//n��floyd
	while( n ){
		if( n&1 ){
			floyd(temp,ans,mat);
			copy(ans,temp);//���´�ͼ
		}
		floyd(temp,mat,mat);
		copy(mat,temp);//�޸�ͼ
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