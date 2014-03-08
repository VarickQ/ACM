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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 55;

int mat1[5][5],mat2[5][5],an1[5][5],an2[5][5];
int main(){
	char ch;
	int ans = inf;
	for(int i=1 ; i <= 4; ++i){
		for(int j=1 ; j <= 4 ; ++j){
			scanf(" %c", &ch);
			if( ch == 'b' ){
				mat1[i][j] = 1;	mat2[i][j] = 0;
			} else {
				mat1[i][j] = 0; mat2[i][j] = 1;
			}
		}
	}
	for(int i=0 ; i < 16 ; ++i){
		memset( an1, 0, sizeof( an1 ) );
		memset( an2, 0, sizeof( an2 ) );
		int s = i;
		for(int j=1 ; j <= 4 ; ++j){
			an1[1][j] = an2[1][j] = s&1;
			s >>= 1;
		}
		for(int j=2 ; j <= 4 ; ++j)
			for(int p=1 ; p <= 4 ; ++p){
				an1[j][p]=!(mat1[j-1][p]^an1[j-1][p]^an1[j-2][p]^an1[j-1][p-1]^an1[j-1][p+1]);
				an2[j][p]=!(mat2[j-1][p]^an2[j-1][p]^an2[j-2][p]^an2[j-1][p-1]^an2[j-1][p+1]);
			}
		bool f1 = false;
		for(int j=1 ; j <= 4 ; ++j)
			if(!(mat1[4][j]^an1[4][j]^an1[3][j]^an1[4][j-1]^an1[4][j+1])){
				f1 = true; break;
			}
		bool f2 = false;
		for(int j=1 ; j <= 4 ; ++j)
			if(!(mat2[4][j]^an2[4][j]^an2[3][j]^an2[4][j-1]^an2[4][j+1])){
				f2 = true; break;
			}
		if( f1 && f2 ) continue;
		if( !f1 ){
			int num = 0;
			for(int j=1 ; j <= 4 ; ++j)
				for(int k=1 ; k <= 4 ; ++k)
					if( an1[j][k] ) num++;
			if(ans > num) ans = num;
		}
		if( !f2 ){
			int num = 0;
			for(int j=1 ; j <= 4 ; ++j)
				for(int k=1 ; k <= 4 ; ++k)
					if( an2[j][k] ) num++;
			if(ans > num) ans = num;
		}
	}
	if( ans != inf ) printf("%d\n", ans);
	else printf("Impossible\n");
	return 0;
}