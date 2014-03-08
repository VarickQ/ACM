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
const int N   = 1024010;
typedef long long LL;

struct Node{
	int k,p;
	bool operator < (const Node &a) const{
		return p > a.p;
	}
}tmp;
set<Node> st;
set<Node>::iterator it;
int main(){
	int n;
	while( scanf("%d", &n) && n ){
		if( n == 1 ){
			scanf("%d%d", &tmp.k, &tmp.p);
			st.insert(tmp);
		}
		else if( n == 2 ){
			if( st.empty() ) puts("0");
			else{
				it = st.begin();
				printf("%d\n", (*it).k);
				st.erase(it);
			}
		}
		else if( n == 3 ){
			if( st.empty() ) puts("0");
			else{
				it = st.end();
				it--;
				printf("%d\n", (*it).k);
				st.erase(it);
			}
		}
	}
	return 0;
}