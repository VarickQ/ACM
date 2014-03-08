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
const int M   = 105;
const int N   = 5;
typedef long long ll;

int mark[5][5];
struct Ans{
	int x,y;
}res[20];
int main(){
	char ch[5];
	while( scanf("%s", ch) != EOF ){
		memset( mark, 0, sizeof( mark ) );
		for(int i=0 ; i < 4 ; ++i){
			if( ch[i] == '+' ){
				for(int j=0 ; j < 4 ; ++j){
					mark[0][j] = (mark[0][j]+1)%2;
					mark[j][i] = (mark[j][i]+1)%2;
				}
				mark[0][i] = (mark[0][i]+1)%2;
			}
		}
		for(int i=1 ; i < 4 ; ++i ){
			scanf("%s", ch);
			for(int j=0 ; j < 4 ; ++j){
				if( ch[j] == '+' ){
					for(int k=0 ; k < 4 ; ++k){
						mark[i][k] = (mark[i][k]+1)%2;
						mark[k][j] = (mark[k][j]+1)%2;
					}
					mark[i][j] = (mark[i][j]+1)%2;
				}
			}
		}
		//// check
		//for(int i=0 ; i < 4 ; ++i){
		//	for(int j=0 ; j < 4 ; ++j)
		//		printf("%d",mark[i][j]);
		//	printf("\n");
		//}

		int ans = 0,k = 0;
		for(int i=0 ; i < 4 ; ++i){
			for(int j=0 ; j < 4 ; ++j)
				if( mark[i][j] ){
					ans++;
					res[k].x = i+1;
					res[k++].y = j+1;
				}
		}
		printf("%d\n", ans);
		for(int i=0 ; i < k ; ++i)
			printf("%d %d\n", res[i].x, res[i].y);
	}
	return 0;
}