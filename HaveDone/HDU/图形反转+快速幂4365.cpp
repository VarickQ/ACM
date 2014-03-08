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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 1005;
const int M   = 100000007;
const int inf = 1000000000;
typedef __int64 LL;

set<pair<int,int> > st;
LL sPow(LL x,int n, int M){
	LL sum = 1;
	while( n ){
		if( n&1 ) sum = sum*x%M;
		x = x*x%M;
		n >>= 1;
	}
	return sum%M;
}
int main(){
	int n, m, k, len;
	while( scanf("%d%d%d", &n, &m, &k) != EOF ){
		st.clear();
		if(n&1) len = n+1>>1;
		else len = n>>1;
		int sum = len*(len+1)>>1;
		while( m-- ){
			pair<int,int> p;
			scanf("%d%d", &p.first, &p.second);
			p.first++;p.second++;
			for(int i=0 ; i < 4 ; ++i){
				if(p.first<=len && p.second<=len && p.first<=p.second)
					st.insert(p);
				p = make_pair(p.second,n-p.first+1);
			}
			swap(p.first,p.second);
			for(int i=0 ; i < 4 ; ++i){
				if(p.first<=len && p.second<=len && p.first<=p.second)
					st.insert(p);
				p = make_pair(p.second,n-p.first+1);
			}
		}
		printf("%I64d\n", sPow((LL)k,sum-st.size(),M));
	}
	return 0;
}