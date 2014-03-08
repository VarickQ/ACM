#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int MAXSIZE = 1<<8;
#define FF(i , j) for (int i = 0 ; i < n ; i ++)

class Matrix{
private:
	int ret[MAXSIZE][MAXSIZE];
	int factor[MAXSIZE][MAXSIZE];
	long long buf[MAXSIZE][MAXSIZE];

	int n;
	int unit[MAXSIZE][MAXSIZE];

	void MatrixMul(int ret[][MAXSIZE],int factor[][MAXSIZE],int n) {
		memset(buf , 0 , sizeof(buf));
		FF(i , n) FF(k , n) if (ret[i][k]) {
			FF(j , n) if (factor[k][j]) {
				buf[i][j] += (long long)ret[i][k] * factor[k][j];
				if (buf[i][j] >= mod) buf[i][j] %= mod;
			//	if (buf[i][j] <= -mod) bud[i][j] %= mod;
			}
		}
		FF(i , n) FF(j , n) ret[i][j] = buf[i][j];
	}
	void dfs(int pre,int now,int id) {
		if (id == 8) {
			unit[255^pre][now] ++;
			return ;
		}
		dfs(pre , now , id + 1);
		if ((pre & (1<<id)) == 0) {
			dfs(pre | (1<<id) , now | (1<<id) , id + 1);
			if (id < 7) {
				dfs(pre | (1<<id) | (1<<(id+1)) , now , id + 1);
			} else if ((pre & 1) == 0) {
				dfs(pre | (1<<id) | 1 , now , id + 1);
			}
		}
	}
public:
	void init() {
		n = MAXSIZE;
		memset(unit , 0 , sizeof(unit));
		dfs(0 , 0 , 0);
	}
	/**
	 * @unit ： 单位矩阵
	 * @n : 矩阵的阶数
	 * @m : 变化次数
	 */
	void MatrixMul(int unit[][MAXSIZE] , int n ,int m) {
		FF(i , n) FF(j , n) {
			ret[i][j] = (i == j);
			factor[i][j] = unit[i][j];
		}
		for ( ; m ; m >>= 1) {
			if (m & 1) MatrixMul(ret , factor , n);
			MatrixMul(factor,factor , n);
		}
	}
	int solve(int m) {
		MatrixMul(unit , n , m);	
		return ret[0][0];
	}
}matrix;

int main() {
	freopen("1002.in","r",stdin);
//	freopen("data.out","w",stdout);
	matrix.init();
	int T;
	scanf("%d" , &T);
	for (int cas = 1 ; cas <= T ; cas ++) {
		int m;
		scanf("%d" , &m);
		printf("Case %d: %d\n" , cas , matrix.solve(m));
	}
	return 0;
}