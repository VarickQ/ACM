#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll __int64
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1000010;

int main() {
	int a[7],left[3],ans;
	while(true){
		bool flag = true;
		for(int i=1 ; i <= 6 ; ++i){
			scanf("%d",&a[i]);
			if(a[i] != 0) flag = false;
		}
		if(flag) break;
		ans = a[6];
		ans += a[5];
		left[1] = a[5]*11;
		ans += a[4];
		left[2] = a[4]*5;
		ans += (a[3]%4==0)?(a[3]/4):(a[3]/4+1);
		if(a[3]%4 == 1){
			left[2] += 5;
			left[1] += 7;
		}
		else if(a[3]%4 == 2){
			left[2] += 3;
			left[1] += 6;
		}
		else if(a[3]%4 == 3){
			left[2] += 1;
			left[1] += 5;
		}
		if(a[2] <= left[2]){
			left[2] -= a[2];
			a[2] = 0;
		} else {
			a[2] -= left[2];
			left[2] = 0;
			ans += (a[2]%9==0)?(a[2]/9):(a[2]/9+1);
			if(a[2]%9 != 0)
				left[1] += (9-a[2]%9)*4;
		}
		a[1] -= left[2]*4+left[1];
		if(a[1] > 0)
			ans += (a[1]%36==0)?(a[1]/36):(a[1]/36+1);
		printf("%d\n",ans);
	}
	return 0;
}