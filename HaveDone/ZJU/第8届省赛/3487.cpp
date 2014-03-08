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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 20010;
const int N   = 255;
typedef long long LL;


int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		printf("%d", n);
		if( n >= 10 ){
			if( (n/10)%10 == 1 ) puts("th");
			else {
				if( n%10 == 1 ) puts("st");
				else if( n%10 == 2 ) puts("nd");
				else if( n%10 == 3 ) puts("rd");
				else puts("th");
			}
		} else {
			if( n%10 == 1 ) puts("st");
			else if( n%10 == 2 ) puts("nd");
			else if( n%10 == 3 ) puts("rd");
			else puts("th");
		}
	}
	return 0;
}