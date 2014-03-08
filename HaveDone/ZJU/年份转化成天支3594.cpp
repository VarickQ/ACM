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
const int N = 200005;
const int M = 400005;

char ct[20][15]={"Gui","Jia","Yi","Bing","Ding","Wu","Ji","Geng","Xin","Ren"};
char cd[20][15]={"hai","zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu"};
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		if( n > 0 ){
			n = (n - 3 + 60) % 60;
			printf("%s%s\n", ct[n%10], cd[n%12]);
		}
		else {
			n = (n+1-3+60000)%60;
			printf("%s%s\n", ct[n%10], cd[n%12]);
		}
	}
	return 0;
}