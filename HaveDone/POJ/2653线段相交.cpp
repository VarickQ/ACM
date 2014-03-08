#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-10;
const int inf = 1000000000;
const int M = 6050000;
const int N = 100005;
typedef long long ll;
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};
struct line{point a,b;};

struct node{
	int id;
	line l;
};
queue<node> qu;
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int opposite_side(point p1,point p2,line l)
{
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
//判两线段相交,不包括端点和部分重合
int intersect_ex(line u,line v)
{
	return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int n,ans[1005];
	while( scanf("%d", &n) && n ){
		while(!qu.empty()) qu.pop();
		node t,x;
		for(int i=1 ; i <= n ; ++i){
			scanf("%lf%lf%lf%lf",&t.l.a.x,&t.l.a.y,&t.l.b.x,&t.l.b.y);
			t.id = i;
			int len = qu.size();
			for(int i=0 ; i < len ; ++i){
				x = qu.front(); qu.pop();
				if(!intersect_ex(x.l,t.l))
					qu.push(x);
			}
			qu.push(t);
		}
		printf("Top sticks: ");
		int k=0;
		while( !qu.empty() ){
			ans[k++] = qu.front().id;
			qu.pop();
		}
		for(int i=0 ; i < k-1 ; ++i)
			printf("%d, ",ans[i]);
		printf("%d.\n", ans[k-1]);
	}
	return 0;
}