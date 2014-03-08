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
const int N = 30005;

struct line{
	int y1,y2,id;
}a[N];
int c[N],n;
bool cmp1(line a, line b){
	return a.y2 < b.y2;
}
bool cmp2(line a, line b){
	return a.y1 < b.y1;
}
int Lowbit(int t){
    return t & ( -t );
}
void Plus(int pos,int num){
	while(pos <= n){
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int end){
	int sum = 0;
	while(end > 0){
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}
int main(){
	int x1,x2;
	while( scanf("%d%d", &x1, &x2 ) != EOF ){
		memset( c, 0, sizeof( c ) );
		scanf("%d", &n);
		for(int i=1 ; i <= n ; ++i){
			int k,b;
			scanf("%d%d", &k, &b);
			a[i].y1 = k*x1+b;
			a[i].y2 = k*x2+b;
		}
		sort( a+1, a+n+1, cmp1 );
		for(int i=1 ; i <= n ; ++i)
			a[i].id = i;
		sort( a+1, a+n+1, cmp2 );
		int ans = 1;
		for(int i=1 ; i <= n ; ++i){
			Plus( a[i].id, 1 );
			ans += Sum(n)-Sum(a[i].id)+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}