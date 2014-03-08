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
const int inf = 1000000000;
const int M   = 400010;
const int N   = 4000;
typedef long long LL;
const double g = 9.8;
set<string> st;
set<string>::iterator it;
int main(){
	int n;
	double l, w, h, m, v;
	char nm[120];
	while( scanf("%d", &n) != EOF ){
		scanf("%lf%lf%lf", &l, &w, &h);
		st.clear();
		for(int i=0 ; i < n ; ++i){
			scanf("%s%lf%lf",nm, &m, &v);
			double w2 = sqrt(l*l-(l-h)*(l-h));
			double v2 = sqrt(v*v-2*g*h);
			double vx = v2*(l-h)/l;
			double vy = v2*w2/l;
			double tot = 2*vy/g;
			double dis = tot*vx;
			if( dis+w2 >= w )
				st.insert(nm);
		}
		if( l*l-(l-h)*(l-h) > w*w ){
			puts("0"); continue;
		}
		cout << st.size() << endl;
		for( it=st.begin() ; it!=st.end() ; it++)
			cout << *it << endl;
	}
	return 0;
}