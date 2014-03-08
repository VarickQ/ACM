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
const int inf = 1000000000;
const int N = 1005;

struct Matrix{
	int x1,y1,x2,y2,val;
}mat[N];
bool check( Matrix a, Matrix b ){
	if((a.x1<=b.x2&&a.x1>=b.x1||a.x2<=b.x2&&a.x2>=b.x1)
		&&(a.y1<=b.y2&&a.y1>=b.y1||a.y2<=b.y2&&a.y2>=b.y1))
		return true;
	if(a.x1<=b.x2&&a.x1>=b.x1 && a.x2<=b.x2&&a.x2>=b.x1
		&& a.y1<=b.y1&&a.y2>=b.y2)
		return true;
	if(a.y1<=b.y2&&a.y1>=b.y1 && a.y2<=b.y2&&a.y2>=b.y1
		&& a.x1>=b.x1&&a.x2<=b.x2)
		return true;
	if(a.x1>=b.x1&&a.x2<=b.x2&&a.y1>=b.y1&&a.y2<=b.y2)
		return true;
	return false;
}
int main(){
	int n,m,c,x,y,a,b,h;
	while( scanf("%d%d%d", &n, &m, &c) != EOF ){
		memset( mat, 0, sizeof( mat ) );
		int Max=0;
		for(int i=0 ; i < c ; ++i){
			scanf("%d%d%d%d%d",&a,&b,&h,&x,&y);
			mat[i].x1 = x; mat[i].x2 = x+a-1;
			mat[i].y1 = y; mat[i].y2 = y+b-1;
			mat[i].val = h;
			for(int j=0 ; j < i ; ++j)
				if(check(mat[j],mat[i])||check(mat[i],mat[j]))
					if( mat[j].val+h > mat[i].val )
						mat[i].val = mat[j].val+h;
			if(mat[i].val > Max)
				Max = mat[i].val;
		}
		printf("%d\n", Max);
	}
	return 0;
}