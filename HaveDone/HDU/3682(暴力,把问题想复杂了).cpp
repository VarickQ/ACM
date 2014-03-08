#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int N = 2010;
const int inf = 1000000000;

bool mark[3][1010][1010];
int main(){
	int T, n, m, a, b, x, y, z;
	char str[20],c1,c2;
	scanf("%d", &T);
	while( T-- ){
		memset( mark, 0, sizeof( mark ) );
		int ans = 0;
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < m ; ++i){
			scanf("%s", str );
			sscanf(str," %c=%d, %c=%d",&c1,&a,&c2,&b);
			if( c1 > c2 ){
				swap(a,b); swap(c1,c2);
			}
			if( c1=='X' && c2=='Y' ) x=a,y=b,z=-1;
			else if( c1=='X' && c2=='Z' ) x=a,z=b,y=-1;
			else if( c1=='Y' && c2=='Z' ) y=a,z=b,x=-1;
			int tmp = c1+c2-'X'-'X', t;
			for(int j=1 ; j <= n ; ++j){
				if( x == -1 ) x = j, t=0;
				else if( y == -1 ) y = j, t=1;
				else if( z == -1 ) z = j, t=2;
				if( !mark[0][x][y] && !mark[1][x][z] && !mark[2][y][z] )
					ans++;
				if(t==0)x=-1;
				else if(t==1)y=-1;
				else if(t==2)z=-1;
			}
			mark[tmp-1][a][b] = true;
		}
		printf("%d\n", ans);
	}
	return 0;
}