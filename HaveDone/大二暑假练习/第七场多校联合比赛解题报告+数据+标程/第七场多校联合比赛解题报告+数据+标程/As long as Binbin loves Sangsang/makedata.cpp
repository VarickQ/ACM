#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef __int64 LL;
typedef pair<int, int> pii;

const char *key = "LOVE";

void special() {
	puts("1 4");
	puts("1 1 1 L");
	puts("1 1 1 O");
	puts("1 1 1 V");
	puts("1 1 1 E");
}

void large() {
	int n = 1313;
	int m = n/2*4;
	printf("%d %d\n", n, m);
	for(int i=1; i<n; i+=2) {
		printf("%d %d 1314520 L\n", i, i+1);
		printf("%d %d 1314520 O\n", i, i+1);
		printf("%d %d 1314520 V\n", i, i+1);
		printf("%d %d 1314520 E\n", i+1, i+2);
	}
}
#define  min(x,y) ( (x)<(y)?(x):(y) )
#define  max(x,y) ( (x)>(y)?(x):(y) )
int main() {
	freopen("in", "w", stdout);

	srand((unsigned)time(NULL));

	int dataset = 520;
	printf("%d\n", dataset);
	special(), dataset--;
	large(),dataset--;
	while(dataset -- ) {
		int n = (rand()*rand()%1314) + 1;
		if(dataset > 10) {
			n = min(n, rand()%77 + 1);
		}
		int m = max((rand()*rand()%13520) + 1, n*2);
		m = min(m, n*8);
		printf("%d %d\n", n, m);
		while(m--) {
			int u = (rand()%n) + 1;
			int v = (rand()%n) + 1;
			if(rand()%100 < 95) {
				printf("%d %d %d %c\n", u, v,1+ rand()%520, key[rand()%4]);
			} else {
				printf("%d %d %d %c\n", u, v,1+ rand()*rand()%1314520, key[rand()%4]);
			}
		}
	}

	return 0;
}
