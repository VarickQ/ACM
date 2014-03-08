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
const int M   = 10005;
const int N   = 1005;
typedef long long ll;

struct Node{
	int w,s,id;
}a[N];
bool cmp( const Node &a, const Node &b ){
	return a.w < b.w;
}
int p[N],pre[N],ans[N];

int main(){
	int i,j,n=0;
	while(scanf("%d%d", &a[n].w, &a[n].s)!=EOF){
		p[n] = 1;
		pre[n] = 0;
		a[n].id = n;
		n++;
	}
	sort( a, a+n, cmp );

	int pos = 1,len = 1;
	for( i=0 ; i < n ; ++i ){
		for( j=0 ; j < i ; ++j ){
			if(a[i].s<a[j].s && a[i].w>a[j].w && p[i]<=p[j]){
				p[i] = p[j]+1;
				pre[i] = j;
			}
		}
		if( p[i] >= len ){
			pos = i;
			len = p[i];
		}
	}
	printf("%d\n", len);
	j = 0;
	for( i=pos ; i ; i=pre[i] )
		ans[j++] = a[i].id+1;
	for( i=j-1 ; i >= 0 ; --i )
		printf("%d\n", ans[i]);

	return 0;
}