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
const double EPS = 1e-9;
#define zero(x) (((x)>0?(x):-(x))<eps)
const int inf = 1000000000;
const int M   = 1100;
const int N   = 25;
typedef long long LL;

int n, m, k, p;
char mat[N][N];
int tmp[N][N], vis[N][N][5];
struct Node{
	int x, y, dir, t;
};
void print(){
	puts("------------------------");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d", tmp[i][j]);
		puts("");
	}
	puts("------------------------");
}
bool check(int x, int y){
	if (x>=0 && x < n && y>=0 && y < n)
		return true;
	return false;
}
int v[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool cmp(const Node a,const Node b){
	if (a.t == b.t) return a.dir < b.dir;
	return a.t < b.t;
}
void gao(int x, int y){
	vector<Node> va;
	Node s;
	for (int i = 0; i < 4; ++i) {
		s.x = x + v[i][0];
		s.y = y + v[i][1];
		s.dir = i;
		s.t = 1;
		if (check(s.x, s.y))
			va.push_back(s);
	}
	while (!va.empty()) {
		sort(va.begin(), va.end(), cmp );
		Node f = va[0];
		va.erase(va.begin());
		if (tmp[f.x][f.y] > 0) {
			tmp[f.x][f.y]++;
			if (tmp[f.x][f.y] == k) {
				tmp[f.x][f.y] = 0;
				for (int i = 0; i < 4; ++i) {
					s.x = f.x + v[i][0];
					s.y = f.y + v[i][1];
					s.dir = i;
					s.t = f.t + 1;
					if (check(s.x, s.y))
						va.push_back(s);
				}
			}
		} else {
			f.x = f.x + v[f.dir][0];
			f.y = f.y + v[f.dir][1];
			f.t++;
			if (check(f.x, f.y))
				va.push_back(f);
		}
	}
}
int main(){
	bool ok = false;
	while (scanf("%d%d%d%d", &n, &m, &k, &p) != EOF) {
		memset( tmp, 0, sizeof( tmp ) );
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
			for (int j = 0; j < n; ++j)
				tmp[i][j] = mat[i][j] - '0';
		}
		for (int i = 0; i < p; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (tmp[x][y] == 0) continue;
			if (m > 0) {
				m--;
				tmp[x][y]++;
				if (tmp[x][y] == k) {
					tmp[x][y] = 0;
					gao(x, y);
				}
			}
		}
		if (ok) printf("\n");
		printf("%d\n", m);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				printf("%d", tmp[i][j]);
			printf("\n");
		}
		ok = true;
	}
    return 0; 
}