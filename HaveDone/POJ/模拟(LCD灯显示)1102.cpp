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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 150;
typedef long long ll;

char ans[N][N];
bool mark[10][8];
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int s,n,t;
	char str[10];
	mark[0][0]=mark[0][1]=mark[0][2]=mark[0][4]=mark[0][5]=mark[0][6]=true;
	mark[1][5]=mark[1][6]=true;
	mark[2][0]=mark[2][2]=mark[2][3]=mark[2][4]=mark[2][6]=true;
	mark[3][2]=mark[3][3]=mark[3][4]=mark[3][5]=mark[3][6]=true;
	mark[4][1]=mark[4][3]=mark[4][5]=mark[4][6]=true;
	mark[5][1]=mark[5][2]=mark[5][3]=mark[5][4]=mark[5][5]=true;
	mark[6][0]=mark[6][1]=mark[6][2]=mark[6][3]=mark[6][4]=mark[6][5]=true;
	mark[7][4]=mark[7][5]=mark[7][6]=true;
	mark[8][0]=mark[8][1]=mark[8][2]=mark[8][3]=mark[8][4]=mark[8][5]=mark[8][6]=true;
	mark[9][1]=mark[9][2]=mark[9][3]=mark[9][4]=mark[9][5]=mark[9][6]=true;
	while( scanf("%d%d", &s, &t) && (s+t)){
		sprintf(str,"%d",t);
		n = strlen(str);
		for(int i=0 ; i < 2*s+3 ; ++i)
			for(int j=0 ; j < (s+2)*n+(n-1) ; ++j)
				ans[i][j] = ' ';
		int col = 0;
		int row = 0;
		for(int i=0 ; str[i] ; ++i){
			if( mark[str[i]-'0'][1] )
				for(int j=1 ; j < s+1 ; ++j)
					ans[j][col] = '|';
			if( mark[str[i]-'0'][0] )
				for(int j=s+2 ; j < 2*s+2 ; ++j)
					ans[j][col] = '|';
			col = col+s+1;
			if( mark[str[i]-'0'][6] )
				for(int j=1 ; j < s+1 ; ++j)
					ans[j][col] = '|';
			if( mark[str[i]-'0'][5] )
				for(int j=s+2 ; j < 2*s+2 ; ++j)
					ans[j][col] = '|';
			col += 2;

			if( mark[str[i]-'0'][4] )
				for(int j=i*(s+3)+1 ; j < i*(s+3)+s+1 ; ++j)
					ans[row][j] = '-';
			row = row+s+1;
			if( mark[str[i]-'0'][3] )
				for(int j=i*(s+3)+1 ; j < i*(s+3)+s+1 ; ++j)
					ans[row][j] = '-';
			row = row+s+1;
			if( mark[str[i]-'0'][2] )
				for(int j=i*(s+3)+1 ; j < i*(s+3)+s+1 ; ++j)
					ans[row][j] = '-';
			row = 0;
		}

		for(int i=0 ; i < 2*s+3 ; ++i){
			for(int j=0 ; j < (s+2)*n+(n-1) ; ++j)
				printf("%c", ans[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}