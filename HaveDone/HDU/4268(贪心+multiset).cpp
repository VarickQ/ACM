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
const int N = 100010;
const int M = 5010;
const int inf = 1000000000;

struct Node{
	int h,w;
}a[N],b[N];
multiset<int> st;
multiset<int>::iterator it;
bool cmp( Node a, Node b ){
	if( a.h == b.h ) return a.w < b.w;
	return a.h < b.h;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &a[i].h, &a[i].w);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &b[i].h, &b[i].w);
		sort( a, a+n, cmp );
		sort( b, b+n, cmp );
		st.clear();
		int ans = 0;
		for(int i=0,j=0 ; i < n ; ++i){
			while( j < n && a[i].h >= b[j].h ){
				st.insert(b[j].w);
				j++;
			}
			it = st.upper_bound(a[i].w);
			if( it != st.begin() && !st.empty() ){
				--it;
				st.erase(it);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}