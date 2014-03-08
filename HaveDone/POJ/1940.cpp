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
const int M = 10100;
const int N = 10000;

struct point{
	double x,y;
}a[N],ans;
int n;
void fun(int i,int t){
	ans.x = a[i].x; ans.y = a[i].y;
	int j=(i+1)%n;
	bool f = true;
	while(t--){
		if(f){
			ans.x -= a[j].x;
			ans.y -= a[j].y;
			f = false;
		} else {
			ans.x += a[j].x;
			ans.y += a[j].y;
			f = true;
		}
		j = (j+1)%n;
	}
}
int main(){
	while(scanf("%d",&n) != EOF){
		printf("%d ",n);
		for(int i=0 ; i < n ; ++i)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		for(int i=0 ; i < n-1 ; ++i){
			fun(i,n-1);
			printf("%lf %lf ",ans.x,ans.y);
		}
		fun(n-1,n-1);
		printf("%lf %lf\n",ans.x,ans.y);
	}
	return 0;
}