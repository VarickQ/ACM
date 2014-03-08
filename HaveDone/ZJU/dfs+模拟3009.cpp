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
const int M   = 100100;
const int N   = 1001;
typedef long long LL;

int n, m, mat[N][N], ID[15000][2];
char s[M], tmp[N];
vector<int> v[150000];
inline int gID(int x,int y){
	return (x - 1) * m + y;
}
int getID(char *s){
	int l = strlen(s);
	if (l == 1) return (s[0] - 'A' + 1);
	if (l == 2) return (s[0] - 'A' + 1) * 26 + s[1] - 'A' + 1;
}
void gao(int row,char *s){
	int num, len = strlen(s), col = 1;
	for (int i = 0; i < len; ++i) {
		if (s[i] == ' ') continue;
		if (s[i]>='0' && s[i] <= '9'){
			sscanf(s+i, "%d", &num);
			mat[row][col] = num;
			col++;
			while(num){
				num /= 10; ++i;
			}
		}
		else if(s[i] == '=') {
			sscanf(s+i, "%s", tmp);
			i += strlen(tmp) - 1;
			char ss[5], sd[5];
			int x, y, c1 = 0, c2 = 0;
			for (int j = 1; tmp[j]; ++j) {
				if (tmp[j]>='A' && tmp[j]<='Z')
					ss[c1++] = tmp[j];
				if (tmp[j]>='0' && tmp[j]<='9')
					sd[c2++] = tmp[j];
				if (tmp[j] == '+') {
					ss[c1] = sd[c2] = '\0';
					sscanf(sd, "%d", &x);
					y = getID(ss);
					v[gID(row,col)].push_back(gID(x,y));
					c1 = c2 = 0;
				}
			}
			ss[c1] = sd[c2] = '\0';
			sscanf(sd, "%d", &x);
			y = getID(ss);
			v[gID(row,col)].push_back(gID(x,y));
			col++;
		}
	}
}
int dfs(int x, int y){
	if (mat[x][y] != -1) return mat[x][y];
	int id = gID(x,y), sum = 0;
	for (int i = 0; i < v[id].size(); ++i) {
		sum += dfs(ID[v[id][i]][0],ID[v[id][i]][1]);
	}
	return mat[x][y] = sum;
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		memset( mat, -1, sizeof( mat ) );
		scanf("%d%d\n", &m, &n);
		int cnt = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				ID[cnt][0] = i, ID[cnt][1] = j, cnt++;
		for (int i = 1; i <= n*m; ++i) v[i].clear();
		for (int i = 1; i <= n; ++i) {
			gets(s);
			gao(i, s);
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				dfs(i, j);
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j < m; ++j)
				printf("%d ", mat[i][j]);
			printf("%d\n", mat[i][m]);
		}
		printf("\n");
	}
	return 0;
}