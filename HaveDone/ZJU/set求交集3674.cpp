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
#include <iterator>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
typedef long long LL;

char str[50], s[300], tmp[50];
map<string,int> ma;
set<string> st[N], c, p[N];
set<string>::iterator it;
int a[N];
int main(){
	int n, m;
	while( scanf("%d", &n) != EOF ){
		ma.clear();
		for(int i=0 ; i <= 100 ; ++i){
			st[i].clear(); p[i].clear();
		}
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str);
			getchar();
			ma[str] = i;
			gets( s );
			int len = strlen(s);
			for(int j=0 ; j < len ; ){
				sscanf(s+j,"%s",tmp);
				j += strlen(tmp)+1;
				st[ma[str]].insert(tmp);
			}
		}
		for(int i=0 ; i < n ; ++i)
			p[i] = st[i];
		scanf("%d\n", &m);
		while( m-- ){
			for(int i=0 ; i < n ; ++i)
				st[i] = p[i];
			memset( a, 0, sizeof( a ) );
			int cnt = 0;
			gets( s );
			int len = strlen(s);
			for(int i=0 ; i < len ; ){
				sscanf(s+i,"%s",tmp);
				i += strlen(tmp)+1;
				a[cnt++] = ma[tmp];
			}
			if( cnt == 1 ){
				bool f = false;
				for(it=st[a[0]].begin() ; it!=st[a[0]].end() ; it++){
					if( !f ){
						cout << *it; f = true;
					} else cout <<' '<< *it ;
				}
				puts("");
			} else {
				for(int i=1 ; i < cnt ; ++i){
					c.clear();
					set_intersection(st[a[i-1]].begin(),st[a[i-1]].end(),st[a[i]].begin(),st[a[i]].end(),insert_iterator<set<string> >(c,c.begin()));
					st[a[i]] = c;
				}
				if( st[a[cnt-1]].size() == 0 ){
					puts("NO"); continue;
				} else {
					bool f = false;
					for(it=st[a[cnt-1]].begin() ; it!=st[a[cnt-1]].end() ; it++){
						if( !f ){
							cout << *it; f = true;
						} else cout <<' '<< *it ;
					}
					puts("");
				}
			}
		}
	}
	return 0;
}