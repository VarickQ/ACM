http://zh.wikipedia.org/wiki/%E5%8E%9F%E6%A0%B9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int inf = 1000000000;
const int N = 100005;
typedef long long ll;

int eular(int n){
	int ret=1,i;
	for (i=2;i*i<=n;i++)
		if (n%i==0){
			n/=i,ret*=i-1;
			while (n%i==0)
				n/=i,ret*=i;
		}
	if (n>1) ret*=n-1;
	return ret;
}
int main(){
	int n;
	//因此当模m有原根时，它有φ(φ(m))个原根。
	while( scanf("%d", &n) != EOF ){
		printf("%d\n", eular(eular(n)));
	}
	return 0;
}