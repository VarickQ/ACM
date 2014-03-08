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
const int N   = 500010;

int a[N];
map<int,int> ma;
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	int n,m,l,r;
	while( scanf("%d", &n) != EOF ){
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		while( m-- ){
			ma.clear();
			bool f = false;
			scanf("%d%d", &l, &r);
			for(int i=r ; i >= l ; --i){
				ma[a[i]]++;
				if( ma[a[i]] >= 2 ){
					f = true;
					printf("%d\n", a[i]);
					break;
				}
			}
			if(!f) printf("OK\n");
		}
		printf("\n");
	}
	return 0;
}