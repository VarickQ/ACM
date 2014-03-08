#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
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
const int N = 35;
typedef long long ll;

int m,cnt[N];
char s1[N],s2[N];
int C(int n, int k){
	int r = 1,i;
	for (i = 1; i <= k; ++ i) {
		r *= (n-i+1); r /= i;
	}
	return r;
}
//统计各个节点的子节点个数
void dfs( int preS, int preE, int posS ){
	if( preS == preE ) return ;
	int pPre = preS+1, pPos;
	char ch;
	while( pPre <= preE ){
		ch = s1[pPre];
		cnt[preS]++;
		pPos = posS;
		while( ch != s2[pPos] ) pPos++;
		dfs( pPre, pPre+pPos-posS, posS );
		pPre = pPre+pPos-posS+1;
		posS = pPos+1;
	}
}
int getAns(){
	int ans = 1;
	for(int i=0 ; i < strlen(s1) ; ++i)
		ans *= C(m,cnt[i]);
	return ans;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	while( scanf("%d", &m) && m ){
		scanf("%s%s", s1, s2);
		CLR( cnt, 0 );
		dfs( 0, strlen(s1)-1, 0 );
		printf("%d\n", getAns());
	}
	return 0;
}