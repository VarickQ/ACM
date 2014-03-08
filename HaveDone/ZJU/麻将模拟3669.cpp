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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 150;
typedef long long LL;

char str[N];
int a[20][20];
set< pair<int,int> > ans;
set< pair<int,int> >::iterator it;
int id( char ch ){
	if( ch == 'm' ) return 1;
	if( ch == 'p' ) return 2;
	if( ch == 's' ) return 3;
	return 4;
}
char fid( int i ){
	if( i == 1 ) return 'm';
	if( i == 2 ) return 'p';
	if( i == 3 ) return 's';
	return 'z';
}
bool dfs(int s,int x){
	bool f = false;
	if( s <= 3 ){
		for(int i=x ; i <= 9 ; ++i){
			if( a[s][i] >= 3 ){
				f = true;
				a[s][i] -= 3;
				if( dfs(s,i) ){
					a[s][i] += 3;
					return true;
				}
				a[s][i] += 3;
			}
			if( a[s][i]&&a[s][i+1]&&a[s][i+2] ){
				f = true;
				a[s][i]--;
				a[s][i+1]--;
				a[s][i+2]--;
				if( dfs(s,i) ){
					a[s][i]++;
					a[s][i+1]++;
					a[s][i+2]++;
					return true;
				}
				a[s][i]++;
				a[s][i+1]++;
				a[s][i+2]++;
			}
		}
		if(!f){
			for(int i=1 ; i <= 9 ; ++i)
				if( a[s][i] ) return false;
			return dfs(s+1,1);
		}
	} else {
		for(int i=1 ; i <= 7 ; ++i){
			if( a[4][i] >= 3 ){
				f = true;
				a[4][i] -= 3;
				if( dfs(s+1,i) ){
					a[4][i] += 3;
					return true;
				}
				a[4][i] += 3;
			}
		}
		if(!f){
			for(int i=1 ; i <= 7 ; ++i)
				if( a[4][i] ) return false;
			return true;
		}
	}
	return false;
}
bool check(){
	for(int i=1 ; i <= 3 ; ++i){
		for(int j=1 ; j <= 9 ; ++j){
			if( a[i][j] >= 2 ){
				a[i][j] -= 2;
				if( dfs(1,1) ){
					a[i][j] += 2;
					return true;
				}
				a[i][j] += 2;
			}
		}
	}
	for(int i=1 ; i <= 7 ; ++i){
		if( a[4][i] >= 2 ){
			a[4][i] -= 2;
			if( dfs(1,1) ){
				a[4][i] += 2;
				return true;
			}
			a[4][i] += 2;
		}
	}
	return false;
}
int main(){
	while( scanf("%s", str) != EOF ){
		memset( a, 0, sizeof( a ) );
		ans.clear();
		int len = strlen(str);
		for(int i=0 ; i < 26 ; i+=2)
			a[id(str[i+1])][str[i]-'0']++;
		for(int i=1 ; i <= 3 ; ++i){
			for(int j=1 ; j <= 9 ; ++j){
				if( a[i][j] <= 3 ){
					a[i][j]++;
					if( check() )
						ans.insert(make_pair(i,j));
					a[i][j]--;
				}
			}
		}
		for(int i=1 ; i <= 7 ; ++i){
			if( a[4][i] < 3 ){
				a[4][i]++;
				if( check() )
					ans.insert(make_pair(4,i));
				a[4][i]--;
			}
		}
		if( ans.size() == 0 ) puts("0");
		else {
			printf("%d ", ans.size());
			for(it=ans.begin() ; it!=ans.end() ; ++it)
				cout << it->second << fid(it->first);
			puts("");
		}
	}
	return 0;
}