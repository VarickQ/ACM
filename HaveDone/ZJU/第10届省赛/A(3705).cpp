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
const int N   = 505;
const double eps = 1e-8;
typedef long long LL;

int n, m, r, s, q;
int mms[N], osc[N];
struct Team{
	char name[50];
	double val;
}t[N];
struct Node{
	char tname[50], app[50], sex[5];
	vector<int> jjp;
	double val;
}a[N];
bool isP(int n){
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i)
		if (n%i == 0) return false;
	return true;
}
bool cmp(const int &a, const int &b){
	return a > b;
}
bool cmp2(const Node &a,const Node &b){
	//比赛的时候错在这里了！尼玛排序了居然不对！不排序倒AC了！！！
	//if (fabs(a.val-b.val) < eps)
	//	return strcmp(a.app, b.app);
	return a.val > b.val;
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset( t, 0, sizeof( t ) );
		for (int i = 0; i < n; ++i) {
			a[i].jjp.clear();
			a[i].val = 0;
		}
		scanf("%d", &r);
		for (int i = 0; i < r; ++i)
			scanf("%d", &mms[i]);
		scanf("%d", &s);
		for (int i = 0; i < s; ++i)
			scanf("%d", &osc[i]);
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int tmp;
			scanf("%s%d", t[i].name, &tmp);
			if (tmp == 1) t[i].val = 36.0;
			else if (tmp == 2) t[i].val = 27.0;
			else if (tmp == 3) t[i].val = 18.0;
		}
		for (int i = 0; i < n; ++i) {
			int p, jj, tmp;
			scanf("%s%s%s%d%d",a[i].app, a[i].tname, a[i].sex, &p, &jj);
			if (!strcmp(a[i].sex,"F")) a[i].val += 33.0;
			for (int j = 0; j < q; ++j) {
				if (!strcmp(a[i].tname, t[j].name))
					a[i].val += t[j].val;
			}
			for (int j = 0; j < p; ++j) {
				scanf("%d", &tmp);
				bool oo = false;
				for (int k = 0; k < r; ++k) {
					if (tmp == mms[k]) {
						a[i].val += 2.5;
						oo = true;
						break;
					}
				}
				if (!oo) {
					for (int k = 0; k < s; ++k) {
						if (tmp == osc[k]) {
							a[i].val += 1.5;
							oo = true;
							break;
						}
					}
				}
				if (!oo && isP(tmp)){
					a[i].val += 1.0; oo = true;
				}
				if (!oo) a[i].val += 0.3;
			}
			for (int j = 0; j < jj; ++j) {
				scanf("%d", &tmp);
				a[i].jjp.push_back(tmp);
			}
			if (a[i].jjp.size() >= 3) {
				sort( a[i].jjp.begin(), a[i].jjp.end(), cmp );
				a[i].val += max(0, (a[i].jjp[2] - 1200) / 100.0) * 1.5;
			}
		}
		sort(a, a+n, cmp2 );
		for (int i = 0; i < m; ++i)
			printf("%s %.3lf\n", a[i].app, a[i].val);
	}
	return 0;
}