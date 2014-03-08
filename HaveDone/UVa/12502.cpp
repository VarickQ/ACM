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
const int N   = 105;
typedef long long LL;

int main(){
	int T, a, b, c;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &a, &b, &c);
		int tot = (2 * a - b) * c / (a + b);
		if (tot < 0) tot = 0;
		printf("%d\n",  tot);
	}
	return 0;
}