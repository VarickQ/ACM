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
const int N = 5010;
const int M = 1000000;

char c[11][5]={{'a','b','c','.'},{'d','e','f','.'},
{'g','h','i','.'},{'j','k','l','.'},{'m','n','o','.'},
{'p','q','r','s'},{'t','u','v','.'},{'w','x','y','z'}};
bool mark[M];
int res[M],a[N];
int main(){
	int T, n, m;
	scanf("%d", &T);
	while( T-- ){
		memset( mark, 0, sizeof( mark ) );
		memset( res, 0, sizeof( res ) );
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &a[i]);
			mark[a[i]] = true;
		}
		char s[10];
		int num;
		for(int i=0 ; i < m ; ++i){
			num = 0;
			scanf("%s", s);
			for(int j=0 ; s[j] ; ++j){
				for(int k=0 ; k < 8 ; ++k){
					bool f = false;
					for(int p=0 ; p < 4 ; ++p){
						if( s[j] == c[k][p] ){
							f = true; break;
						}
					}
					if( f ){
						num = num*10+k+2;
						break;
					}
				}
			}
			if( mark[num] ) res[num]++;
		}
		for(int i=0 ; i < n ; ++i)
			printf("%d\n", res[a[i]]);
	}
	return 0;
}