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
const int M   = 25000001;
const int N   = 105;
typedef long long LL;

map<string,bool> ma;
char str[N];
int main(){
	int n, k, a;
	while( scanf("%d", &n) != EOF ){
		ma.clear();
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str);
			ma[str] = true;
		}
		scanf("%d", &k);
		while( k-- ){
			scanf("%d", &a);
			int cnt = 0;
			for(int i=0 ; i < a ; ++i){
				scanf("%s", str);
				if( ma[str] ) cnt++;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}