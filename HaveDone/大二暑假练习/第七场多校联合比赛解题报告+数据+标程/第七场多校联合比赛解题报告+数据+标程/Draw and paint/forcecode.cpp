#include<stdio.h>
#include<string.h>
#include<time.h>
int dp[50][50][5][5][5][5];
bool flag[50][50][5][5][5][5];
bool f[5];
int cnt[5][5][5][5];
int dfs(int i, int j, int c1, int c2, int c3, int c4) {
	int k, p;
	if (flag[i][j][c1][c2][c3][c4]) {
		return dp[i][j][c1][c2][c3][c4];
	}
	flag[i][j][c1][c2][c3][c4] = true;
	dp[i][j][c1][c2][c3][c4] = cnt[c1][c2][c3][c4];

	for (k = 1; k < i; ++k) {
		for (p = 0; p < 4; ++p) {
			if (p == c2 || p == c4)
				continue;
			if (p != c1) {
				dp[i][j][c1][c2][c3][c4] += dfs(j, k, c2, c3, c4, p);
				if (dp[i][j][c1][c2][c3][c4] >= 1000000007)
					dp[i][j][c1][c2][c3][c4] -= 1000000007;
			}
			if (p != c3) {
				dp[i][j][c1][c2][c3][c4] += dfs(j, i - k, c2, p, c4, c1)
						- cnt[c2][p][c4][c1];
				if (dp[i][j][c1][c2][c3][c4] >= 1000000007)
					dp[i][j][c1][c2][c3][c4] -= 1000000007;
			}
		}
	}
	if (dp[i][j][c1][c2][c3][c4] < 0)
		dp[i][j][c1][c2][c3][c4] += 1000000007;
	flag[i][j][c3][c2][c1][c4] = true;
	dp[i][j][c3][c2][c1][c4] = dp[i][j][c1][c2][c3][c4];
	flag[i][j][c3][c4][c1][c2] = true;
	dp[i][j][c3][c4][c1][c2] = dp[i][j][c1][c2][c3][c4];
	flag[i][j][c1][c4][c3][c2] = true;
	dp[i][j][c1][c4][c3][c2] = dp[i][j][c1][c2][c3][c4];
	return dp[i][j][c1][c2][c3][c4];
}
void pre() {
	int c1, c2, c3, c4, k;
	for (c1 = 0; c1 < 5; ++c1) {
		for (c2 = 0; c2 < 5; ++c2) {
			for (c3 = 0; c3 < 5; ++c3) {
				for (c4 = 0; c4 < 5; ++c4) {
					cnt[c1][c2][c3][c4] = 0;
					for (k = 0; k < 4; ++k) {
						if (k != c1 && k != c2 && k != c3 && k != c4)
							cnt[c1][c2][c3][c4]++;
					}
				}
			}
		}
	}
}
int main() {
	int t;
	int i, j;
//	int t1 = clock();
	freopen("data.in", "r", stdin);
	freopen("forcedata.out", "w", stdout);
	pre();
	memset(dp, 0, sizeof(dp));
	memset(flag, false, sizeof(flag));
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &i, &j);
		printf("%d\n", dfs(i, j, 4, 4, 4, 4));
	}
//	printf("%dms\n", clock() - t1);
	return 0;
}
