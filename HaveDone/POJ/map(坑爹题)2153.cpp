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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Lowbit(x) ((x)&(-x))
const int N = 10005;
typedef long long LL;

char str[105];
int cnt[5005];
map<string,int> ma;
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int n, m;
	while( scanf("%d\n", &n) == 1 ){
		ma.clear();
		for(int i=0 ; i < n ; ++i){
			gets( str );
			ma[str] = 0;
		}
		scanf("%d", &m);
		int num;
		for(int i=0 ; i < m ; ++i){
			CLR( cnt, 0 );
			for(int j=0 ; j < n ; ++j){
				scanf("%d ", &num);
				gets( str );
				ma[str] += num;
				cnt[ma[str]]++;
			}
			int ans = 1;
			for(int i=m*100 ; i > ma["Li Ming"] ; --i)
				ans += cnt[i];
			printf("%d\n", ans);
		}
	}
	return 0;
}