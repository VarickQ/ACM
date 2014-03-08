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
const int inf = 2000000000;
typedef long long LL;

/*=============== Dancing Link 模板 ==============*/
#define INF 0x3fffffff
const int head = 0;		//挂钩板头head = 0
const int MaxM = 1005;	//最大行数
const int MaxN = 1005;	//最大列数
const int MaxL = 100002;//最大节点数

int M, N;	//种类M(行),覆盖N(列)
int NUM;	//存储链表的个数
int S[MaxL];	//记录列节点个数
int U[MaxL], D[MaxL], L[MaxL], R[MaxL], C[MaxL];
//该行最左Lid，最右Rid，在C列
inline void Add( int Lid, int &Rid, int c ){
	U[NUM] = U[c];	D[U[c]] = NUM;	//上
	D[NUM] = c;		U[c] = NUM;		//下
	L[NUM] = Rid;	R[Rid] = NUM;	//左
	R[NUM] = Lid;	L[Lid] = NUM;	//右
	C[NUM] = c;		++S[c];			//列
	Rid = NUM;		++NUM;			//当前这个为该行最右
}
/*================== 精确覆盖 ====================*/
void remove( int c ){	//删除第c列
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	for (int i = D[c] ; i != c ; i = D[i]){
		for (int j = R[i] ; j != i ; j = R[j]){
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			--S[C[j]];
		}
	}
}
void resume( int c ){	//恢复第c列
	L[R[c]] = c;
	R[L[c]] = c;
	for (int i = U[c] ; i != c ; i = U[i]){
		for (int j = L[i] ; j != i ; j = L[j]){
			U[D[j]] = j;
			D[U[j]] = j;
			++S[C[j]];
		}
	}
}
bool DLX( int dep ){	//精确覆盖
	if (R[head] == head){
		//ansNum = dep;
		return true;
	}
	int Min = INF;
	int i, j, c;
	for (i = R[head] ; i != head ; i = R[i])
		if( S[i] < Min ) Min = S[c = i];
	remove( c );
	for (i = D[c] ; i != c ; i = D[i]){
		//Ans[dep] = Row[i];	//保存解
		for (j = R[i] ; j != i ; j = R[j])
			remove( C[j] );

		if( DLX(dep + 1) ) return true;

		for (j = L[i] ; j != i ; j = L[j])
			resume( C[j] );
	}
	resume( c );
	return false;
}
/*================== 重复覆盖 ====================*/
void remove_2( int c ){
	for (int i = D[c] ; i != c ; i = D[i]){
		R[L[i]] = R[i];
		L[R[i]] = L[i];
	}
}
void resume_2( int c ){
	for (int i = U[c] ; i != c ; i = U[i]){
		R[L[i]] = i;
		L[R[i]] = i;
	}
}
int Hash(){	//估价函数
	bool vis[MaxN];
	memset( vis, false, sizeof( vis ) );
	int ret = 0;
	for (int i = R[head] ; i != head ; i = R[i]){
		if (vis[C[i]]) continue;
		++ret;
		vis[C[i]] = true;
		for (int j = D[i] ; j != i ; j = D[j])
			for (int k = R[j] ; k != j ; k = R[k])
				vis[C[k]] = true;
	}
	return ret;
}
bool DLX_2( int dep, int limit ){	//	重复覆盖
	if (dep + Hash() > limit) return false;//剪枝
	if (R[head] == head) return true;
	int Min = INF;
	int i, j, c;
	for (i = R[head] ; i != head ; i = R[i])
		if( S[i] < Min ) Min = S[c == i];
	for (i = D[c] ; i != c ; i = D[i]){
		remove_2(i);
		for (j = R[i] ; j != i ; j = R[j])
			remove_2( j );

		if (DLX_2( dep+1, limit)) return true;

		for (j = L[i] ; j != i ; j = L[j])
			resume_2(j);
		resume_2(i);
	}
	return false;
}
/*============================================*/
int n, m;
void init(){
	M = n;
	N = m;
	for (int i = 1 ; i < N ; ++i){
		U[i] = D[i] = i;
		L[i] = i - 1;
		R[i] = i + 1;
		C[i] = i;
	}
	U[0] = D[0] = 0; L[0] = N; R[0] = 1; C[0] = 0;
	U[N] = D[N] = N; L[N] = N - 1; R[N] = 0; C[N] = N;
	memset( S, 0, sizeof( S ) );
	NUM = N + 1;
}
int main(){
	int c;
	while( scanf("%d%d", &n, &m) != EOF ){
		init();
		int Lid, Rid;
		for (int i = 1 ; i <= n ; ++i){
			Lid = Rid = NUM;
			for (int j = 1 ; j <= m ; ++j){
				scanf("%d", &c);
				if (c == 1)
					Add( Lid, Rid, j );
			}
		}
		if (DLX(0)) puts("Yes, I found it");
		else puts("It is impossible");
	}
	return 0;
}