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
#define PI acos(-1.0)
#define abs(x) ((x)>0?(x):-(x))
typedef long long LL;
const int N = 1010;
const int inf = 1000000000;
const double eps = 1e-6;

struct Node{
	char str[85];
	int len;
}a[N];
bool cmp(const Node &a,const Node &b){
	return a.len < b.len;
}
int mat[N][N], n, ans, vis[N];
void bfs(){
	int Max = 0;
	queue<pair<int,int> > qu;
	qu.push(make_pair(0,0));
	while( !qu.empty() ){
		pair<int,int> v,u = qu.front(); qu.pop();
		if( Max < u.second ){
			Max = u.second;
			ans = u.first;
		}
		for(int i=0 ; i < n ; ++i){
			if( mat[u.first][i] && !vis[i] ){
				vis[i] = 1;
				v.first = i;
				v.second = u.second+1;
				qu.push(v);
			}
		}
	}
}
int main(){
	while( scanf("%d", &n) != EOF ){
		memset( mat, 0, sizeof( mat ) );
		memset( vis, 0, sizeof( vis ) );
		n++;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", a[i].str);
			a[i].len = strlen(a[i].str);
		}
		sort( a, a+n, cmp );
		for(int i=0 ; i < n ; ++i){
			for(int j=i+1 ; j < n ; ++j){
				if( a[j].len > a[i].len+1 ) break;
				int k,p=0;
				for( k=0 ; k < a[i].len ; ++k){
					while(p<=1 && a[i].str[k] != a[j].str[k+p] )
						p++;
					if( p >= 2 ) break;
				}
				if( p < 2 )	mat[i][j] = 1;
			}
		}
		ans = 0;
		vis[0] = 1;
		bfs();
		printf("%s\n", a[ans].str);
	}
	return 0;
}