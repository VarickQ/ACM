//E by hhf
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 2000100;
const int N   = 100005;
typedef long long ll;

struct node{
	double x,y;
};
int r1,r2;
int n,m;
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(b.y-a.y)*(b.y-a.y));
}
int duj(node a,node b){
	if(2*r1>n || 2*r1>m || 2*r2 >m || 2*r2 >n)
		return 0;
	if(a.x<0 ||a.y<0 || b.x<0 || b.y<0)
		return 0;
	if(dis(a,b)<r1+r2)
		return 0;
	return 1;
}
node p1,p2;
int main(){
	
	while(scanf("%d%d%d%d",&n,&m,&r1,&r2)!=EOF){
		if(n+m+r1+r2==0)
			break;
		p1.x=r1;
		p1.y=m-r1;
		p2.x=n-r2;
		p2.y=r2;
		if(duj(p1,p2))
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}