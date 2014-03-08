#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int64;

const int N = 200;

int n, t;
int64 S[5][N];
int64 M[2][N*N];

inline int64 sum(int i, int j, int k) {
	return M[0][j] + M[1][k-1] + S[4][i];
}

int main() {
	for(cin >> t; t--; ) {
		cin >> n;
		int n2 = n * n;
		for(int i = 0; i < 5; i ++)
			for(int j = 0; j < n; j ++)
				cin >> S[i][j];
		for(int i = 0; i < 2; i ++) {
			for(int j = 0; j < n; j ++)
				for(int k = 0; k < n; k ++)
					M[i][j * n + k] = S[i * 2][j] + S[i * 2 + 1][k];
			sort(M[i], M[i] + n2);
		}
		bool result = false;
		for(int i = 0; i < n && !result; i ++) {
			int k = n2 - 1;
			for(int j = 0; j < n2 && !result; j ++) {
				while(k > 0 && sum(i, j, k-1) >= 0) {
					k --;
				}
				if(sum(i, j, k) == 0) result = true;
			}
		}
		if( result ) {
			cerr << n << " Yes" << endl;
			cout << "Yes" << endl;
		} else {
			cerr << n << " No" << endl;
			cout << "No" << endl;
		}
	}
	return 0;
}
