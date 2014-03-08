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
typedef long long LL;
const int N = 100010;
const int inf = 1000000000;

struct Node{
	int st,ed;
}a[N];
bool cmp(const Node a, const Node b){
	if( a.st == b.st ) return a.ed < b.ed;
	return a.st < b.st;
}
struct cmp1{
	bool operator()(const int &x,const int &y){
		return x > y;
	}
};
priority_queue<int,vector<int>,cmp1> qu;
int main(){
	int n;
	while( scanf("%d", &n) == 1 ){
		while( !qu.empty() ) qu.pop();
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d", &a[i].st, &a[i].ed);
		sort( a, a+n, cmp );
		int ans = 1;
		for(int i=0 ; i < n ; ++i){
			if( qu.empty() ) qu.push(a[i].ed);
			else {
				if( qu.top() <= a[i].st ) qu.pop();
				qu.push(a[i].ed);
			}
			if( qu.size() > ans ) ans = qu.size();
		}
		printf("%d\n", ans);
	}
	return 0;
}