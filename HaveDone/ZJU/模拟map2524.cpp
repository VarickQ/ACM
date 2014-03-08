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
const int inf = 1000000000;
const int M   = 100010;
const int N   = 20010;
typedef long long LL;

struct Node{
	char nm[30];
	int wins,draw,lost;
	int pt,gd;
}a[N];
map<string,int > ma;
bool cmp(const Node &a, const Node &b){
	if( a.pt == b.pt && a.gd == b.gd )
		return strcmp(a.nm,b.nm)<0;
	if( a.pt == b.pt ) return a.gd > b.gd;
	return a.pt > b.pt;
}
int main(){
	bool f = false;
	int n, c1, c2, cnt;
	char s1[30],s2[30];
	while( scanf("%d", &n) != EOF ){
		memset( a, 0, sizeof( a ) );
		ma.clear();
		cnt = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%s%d:%d%s",s1,&c1,&c2,s2);
			if( ma.find(s1) == ma.end() ){
				ma[s1] = cnt++;
				strcpy(a[ma[s1]].nm,s1);
			}
			if( ma.find(s2) == ma.end() ){
				ma[s2] = cnt++;
				strcpy(a[ma[s2]].nm,s2);
			}
			if( c1 > c2 ){
				a[ma[s1]].wins++;
				a[ma[s1]].pt += 3;
				a[ma[s1]].gd += (c1-c2);
				
				a[ma[s2]].lost++;
				a[ma[s2]].gd += (c2-c1);
			}
			else if( c1 < c2 ){
				a[ma[s2]].wins++;
				a[ma[s2]].pt += 3;
				a[ma[s2]].gd += (c2-c1);
				
				a[ma[s1]].lost++;
				a[ma[s1]].gd += (c1-c2);
			}
			else if( c1 == c2 ){
				a[ma[s1]].draw++;
				a[ma[s1]].pt ++;
				
				a[ma[s2]].draw++;
				a[ma[s2]].pt ++;
			}
		}
		if( f ) puts("");
		else f = true;
		sort( a, a+cnt, cmp );
		for(int i=0 ; i < cnt ; ++i)
			printf("%d %s %d %d %d %d %d\n",i+1,a[i].nm,a[i].wins,a[i].draw,a[i].lost,a[i].pt,a[i].gd);
	}
	return 0;
}