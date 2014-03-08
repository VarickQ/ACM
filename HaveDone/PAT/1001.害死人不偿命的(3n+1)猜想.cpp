/*1001. 害死人不偿命的(3n+1)猜想 (15)*/
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
const int M   = 50005;
const int N   = 205;
typedef long long LL;

int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int ans = 0;
		while (n != 1){
			if (n&1)
				n = (3 * n + 1) / 2;
			else
				n = n / 2;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}