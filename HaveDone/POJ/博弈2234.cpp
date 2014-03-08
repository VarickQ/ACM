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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 10100;
const int M = 100005;
typedef long long LL;

int main(){
	int n;
	while( scanf("%d", &n) != EOF ){
		int x, ans=0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &x);
			ans ^= x;
		}
		if( ans ) puts("Yes");
		else puts("No");
	}
	return 0;
}
