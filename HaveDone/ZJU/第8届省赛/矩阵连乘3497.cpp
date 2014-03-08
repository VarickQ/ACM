#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int maxn = 33;

//´Ó(0,0)¿ªÊ¼
class Matrix {
public:
	int n, m;
	int a[maxn][maxn];
	//ret = a * b
	Matrix operator* (const Matrix& b) const {
		if (m != b.n) {
			while (1) {
				puts ("Error size *");
			}
		}
		Matrix ret;
		ret.n = n, ret.m = b.m;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < b.m; ++ j) {
				ret.a[i][j] = 0;
				// m = b.n
				for (int k = 0; k < m; ++ k) {
					ret.a[i][j] += a[i][k] * b.a[k][j];
				}
			}
		}
		return ret;
	}
	Matrix operator% (const int& mod) const {
		Matrix ret;
		ret.n = n, ret.m = m;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				ret.a[i][j] = a[i][j] % mod;
			}
		}
		return ret;
	}
	void print () {
		for (int i = 0; i < n; ++ i) {
			if (i) {
				putchar (10);
			}
			for (int j = 0; j < m; ++ j) {
				if (j) {
					putchar (' ');
				}
				printf ("%d", a[i][j]);
			}
		}
		putchar (10);
	}
}A, E, O, tmp;

Matrix fastpow (Matrix a, int x) {
	Matrix ret = E;
	while (x) {
		if (x & 1) {
			ret = ret * a;
		}
		x >>= 1;
		a = a * a;
	}
	return ret;
}
int n, m;
int id (int x, int y) {
	return x * m + y;
}
int main () {
	for (int i = 0; i < maxn; ++ i) E.a[i][i] = 1;
	int t, x, y;
	char u;
	scanf ("%d", &t);
	while (t --) {
		scanf ("%d%d", &n, &m);
		E.n = E.m = n * m;
		A.n = A.m = n * m;
		memset (A.a, 0, sizeof (A.a));
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				for (int k = 0; k < 4; ++ k) {
					while (1) {
						u = getchar ();
						if (u == '(' || u == ',') break;
					}
					if (k == 0) scanf ("(%d,%d)", &x, &y);
					else if (k == m-1) scanf ("(%d,%d))", &x, &y);
					else scanf ("(%d,%d)", &x, &y);
					x--, y--;
					A.a[id (x, y)][id (i, j)] = 1;
				}
			}
		}
		//for (int i = 0; i < n * m; ++ i) A.a[i][i] = 0;
		O.n = n * m, O.m = 1;
		for (int i = 0; i < n * m; ++ i){
			O.a[i][0] = 0;
			A.a[i][n*m-1] = 0;
		}
		O.a[0][0] = 1;
		while (1) {
			u = getchar ();
			if (u == '\n') break;
		}
		int q;
		scanf ("%d", &q);
		//A.print ();
		while (q --) {
			int p;
			scanf ("%d", &p);
			tmp = fastpow (A, p) * O;
			//tmp.print ();
			if (tmp.a[n*m-1][0] == 0) puts ("False");
			else {
				int flag = 0;
				for (int i = 0; i < n * m - 1; ++ i) {
					if (tmp.a[i][0] != 0) {
						flag = 1;
						break;
					}
				}
				if (flag) puts ("Maybe");
				else puts ("True");
			}
		}
		puts ("");
	}
	return 0;
}