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
const int N = 100005;
const int MOD = 1000000007;
typedef long long ll;

bool vis[N];
int main(){
	int T,n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		CLR( vis, 0 );
		printf("0\n");
		vis[0] = true;
		int pre = 0,M = (1<<n);
		for(int i=1 ; i < M ; ++i){
			int now = M-pre-1;
			for(int j=0 ; j < n ; ++j){
				int tmp,s = (1<<j);
				if( (now&s)==s ) tmp = now-s;
				else tmp = now+s;
				if( !vis[tmp] ){
					vis[tmp] = true;
					printf("%d\n", tmp);
					pre = tmp;
					break;
				}
			}
		}
	}
	return 0;
}