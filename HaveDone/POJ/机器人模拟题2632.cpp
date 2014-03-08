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

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 102;

int r,c,n,m;
struct Robot{
	int x,y,dir;
}a[N];
int di(char ch){
	if( ch == 'N' ) return 0;
	if( ch == 'E' ) return 1;
	if( ch == 'S' ) return 2;
	if( ch == 'W' ) return 3;
}
int v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dead( int i ){
	if( !(a[i].x>=1&&a[i].x<=c && a[i].y>=1&&a[i].y<=r) )
		return 0;
	for(int j=1 ; j <= n ; ++j)
		if( i!=j && a[i].x==a[j].x && a[i].y==a[j].y )
			return j;
	return -1;
}
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int T, x, y;
	char s[5];
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d%d", &c, &r, &n, &m);
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d%s", &x, &y, s);
			a[i].x = x;
			a[i].y = y;
			a[i].dir = di(s[0]);
		}
		bool f = false;
		int ans1,ans2;
		while( m-- ){
			scanf("%d%s%d", &x, s, &y);
			if( !f ){
				int flag = -1;
				if( s[0] == 'F' ){
					for(int i=0 ; i < y ; ++i){
						a[x].x += v[a[x].dir][1];
						a[x].y += v[a[x].dir][0];
						flag = dead(x);
						if( flag >= 0 ){
							f = true;
							ans1 = x;
							ans2 = flag;
							break;
						}
					}
				}
				else if( s[0] == 'L' ){
					y = 4-y%4;
					a[x].dir = (a[x].dir+y)%4;
				}
				else if( s[0] == 'R' ){
					y %= 4;
					a[x].dir = (a[x].dir+y)%4;
				}
				if( flag < 0 ) flag = dead(x);
				else {
					f = true;
					ans1 = x;
					ans2 = flag;
				}
			}
		}
		if( !f ) printf("OK\n");
		else {
			if( ans2 == 0 )
				printf("Robot %d crashes into the wall\n",ans1);
			else printf("Robot %d crashes into robot %d\n",ans1,ans2);
		}
	}
    return 0;
}