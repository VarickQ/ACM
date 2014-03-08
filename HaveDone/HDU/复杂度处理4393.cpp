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
const int N   = 50010;
const int M   = 110;
typedef __int64 LL;

struct Node{
	int fi,si,id;
	bool operator < (const Node &a) const{
		if( fi == a.fi ) return id > a.id;
		return fi < a.fi;
	}
}a;
priority_queue<Node> qu[M];
int main(){
	int T,n,cs=1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i <= 100 ; ++i)
			while( !qu[i].empty() ) qu[i].pop();
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d", &a.fi, &a.si);
			a.id = i;
			qu[a.si].push(a);
		}
		printf("Case #%d:\n", cs++);
		for(int i=0 ; i < n ; ++i){
			int Max = -1,pos = n+1,s = 0;
			for(int j=1 ; j <= 100 ; ++j){
				if( !qu[j].empty() ){
					Node t = qu[j].top();
					if( i*t.si+t.fi >= Max ){
						if( i*t.si+t.fi == Max ){
							if( t.id < pos ){
								pos = t.id;
								s = t.si;
							}
						} else {
							Max = i*t.si+t.fi;
							pos = t.id;
							s = t.si;
						}
					}
				}
			}
			if(i==n-1) printf("%d\n", pos);
			else printf("%d ", pos);
			qu[s].pop();
		}
	}
	return 0;
}