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
const int N   = 1001000;

bool f(int a,int b,int c,int d){
	if(a+b+c>d&&a+b+d>c&&a+c+d>b&&b+c+d>a)
		return true;
	return false;
}
int main(){
	int a,b,c,d,T,cs=1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("Case %d: ", cs++);
		if( f(a,b,c,d) ){
			double p = (a+b+c+d)/2.0;
			printf("%.6lf\n", sqrt((p-a)*(p-b)*(p-c)*(p-d)));
		} else printf("-1\n");
	}
	return 0;
}