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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 3005;
const int M   = 35100;
typedef long long LL;

int in[5][5]={{2,3,1,1},{1,2,3,1},{1,1,2,3},{3,1,1,2}};
int ma[5][5],ans[5][5];
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		memset( ans, 0, sizeof( ans ) );
		for(int i=0 ; i < 4 ; ++i)
			for(int j=0 ; j < 4 ; ++j)
				scanf("%X", &ma[i][j]);
		for(int i=0 ; i < 4 ; ++i){
			for(int j=0 ; j < 4 ; ++j){
				int tmp = 0;
				for(int k=0 ; k < 4 ; ++k){
					if( in[i][k] == 1 ) tmp ^= ma[k][j];
					else if( in[i][k] == 2 ){
						int t = (ma[k][j]<<1);
						if( t&(1<<8) ){
							t^=(1<<8); t^=(0x1B);
						}
						tmp ^= t;
					}
					else if( in[i][k] == 3 ){
						int t = (ma[k][j]<<1);
						if( t&(1<<8) ){
							t^=(1<<8); t^=(0x1B);
						}
						tmp ^= (t^ma[k][j]);
					}
				}
				ans[i][j] = tmp;
			}
		}
		for(int i=0 ; i < 4 ; ++i){
			for(int j=0 ; j < 3 ; ++j)
				printf("%02X ", ans[i][j]);
			printf("%02X\n", ans[i][3]);
		}
		if( T ) printf("\n");
	}
	return 0;
}