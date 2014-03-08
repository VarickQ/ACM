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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Lowbit(x) ((x)&(-x))
const int N = 1005;
typedef long long LL;

int c[N][N];
void update(int x,int y,int num){
	while( x <= N-2 ){
		int j = y;
		while( j <= N-2 ){
			c[x][j] += num;
			j += Lowbit(j);
		}
		x += Lowbit(x);
	}
}
int getSum(int x,int y){
	int sum = 0;
	while( x > 0 ){
		int j = y;
		while( j > 0 ){
			sum += c[x][j];
			j -= Lowbit(j);
		}
		x -= Lowbit(x);
	}
	return sum;
}
int main(){
	int T,n,m,x1,x2,y1,y2;
	char s[2];
	scanf("%d", &T);
	while( T-- ){
		CLR( c, 0 );
		scanf("%d%d", &n, &m);
		while( m-- ){
			scanf("%s", s);
			if( s[0] == 'C' ){
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++,x2++,y1++,y2++;
				update( x2, y2, 1 );

				update( x1-1, y2, -1 );
				update( x2, y1-1, -1 );

				update( x1-1, y1-1, 1 );
			}
			else if( s[0] == 'Q' ){
				scanf("%d%d", &x1, &y1);
				int ans = getSum( x1, y1 );
				printf("%d\n", ans%2);
			}
		}
		if( T ) printf("\n");
	}
	return 0;
}