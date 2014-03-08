#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <set>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int N   = 100010;
const int inf = 1000000000;
typedef long long LL;

LL ans;
int num[N],now,dir;
set<int> st;
set<int>::iterator p1,p2;
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int T, l, n, q, cs=1, x, tmp;
	scanf("%d", &T);
	while( T-- ){
		dir = 1;
		now = 0;
		ans = 0;
		st.clear();
		st.insert(0);
		CLR( num, 0 );
		scanf("%d%d", &l, &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &q);
			if( q == 0 ){
				scanf("%d", &x);
				st.insert(x);
				num[x]++;
			} else {
				if( num[now] ){
					num[now]--; continue;
				}
				p1 = p2 = st.find(now);
				int nl=-1,nr=-1;
				if( p1 != st.begin() )
					nl = *(--p1);
				if( ++p2 != st.end() )//RE
					nr = *p2;
				if( nl == -1 && nr == -1 ) continue;
				if( nl == -1 ){
					ans += nr - now;
					tmp = nr;
					dir = 1;
					num[nr]--;
				}
				else if( nr == -1 ){
					ans += now - nl;
					tmp = nl;
					dir = 0;
					num[nl]--;
				} else {
					if( now-nl == nr-now ){
						ans += nr-now;
						if( dir == 1 ){
							tmp = nr;
							num[nr]--;
						} else {
							tmp = nl;
							num[nl]--;
						}
					} else if( now-nl < nr-now ){
						ans += now-nl;
						tmp = nl;
						dir = 0;
						num[nl]--;
					} else if( now-nl > nr-now ){
						ans += nr-now;
						tmp = nr;
						dir = 1;
						num[nr]--;
					}
				}
				st.erase(now);
				now = tmp;
				st.insert(tmp);
			}
		}
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}