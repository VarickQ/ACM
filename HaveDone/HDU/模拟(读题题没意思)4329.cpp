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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef __int64 LL;
const int N = 10010;
const int M = 1000100;
const int inf = 1000000000;

char str[N], s[N];
map<string,int> ma;
set<string> st[N];
int main()
{
	int T, n, cs = 1;
	scanf("%d", &T);
	while( T-- ){
		ma.clear();
		scanf("%d", &n);
		getchar();
		for(int i=0 ; i <= n ; ++i)
			st[i].clear();

		int id = 0;
		for(int i=0 ; i < n ; ++i){
			gets(str);
			int len = strlen(str);
			bool f = false;
			for(int j=0 ; j < len ; ++j){
				if( str[j] != ' ' ){
					sscanf( str+j, "%s", s );
					if( !f ){
						f = true;
						ma[s] = ++id;
					} else st[id].insert(s);
					int l = strlen(s);
					j += l;
				}
			}
		}

		double ans = 0;
		for(int i=0 ; i < n ; ++i){
			id = -1;
			gets(str);
			int len = strlen(str);
			double tmp = 0;
			int cnt = 0, now = 0, tot = 0;
			for(int j=0 ; j < len ; ++j){
				if( str[j] != ' ' ){
					sscanf( str+j, "%s", s );
					if( id == -1 ){
						id = ma[s];
					} else {
						tot++;
						if( st[id].find(s) != st[id].end() ){
							now++;
							tmp += 1.0*now/tot;
						}
					}
					int l = strlen(s);
					j += l;
				}
			}
			tmp *= 1.0/st[id].size();
			ans += tmp;
		}
		printf("Case #%d: %.6lf\n", cs++, ans/n);
	}
	return 0;
}