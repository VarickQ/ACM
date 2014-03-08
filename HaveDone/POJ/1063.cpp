#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 2000000000;
const int M   = 1000000000;
const int N   = 100001;

int main()
{
	int T,n,j,r,a;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		j = r = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%d",&a);
			if(i&1) j+=a;
			else r+=a;
		}
		if(n&1)	printf("YES\n");
		else {
			if(abs(j-r) <= 1) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
