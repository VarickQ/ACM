#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 35000;
const int N   = 25;
typedef long long ll;

char s[10],size[25][5];
int mat[N][N],match[N],a[N],sta[N],sum;
bool vis[N];
int search( char ch ){
	switch( ch ){
		case 'S': return 1;
		case 'M': return 2;
		case 'L': return 3;
		case 'X': return 4;
		case 'T': return 5;
	}
	return 0;
}
bool find(int i){
	for(int j=1 ; j <= sum ; ++j){
		if( mat[i][j] && !vis[j] ){
			vis[j] = true;
			if( match[j]==0 || find(match[j]) ){
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n;
	while( scanf("%s", s) != EOF ){
		if( strcmp(s,"ENDOFINPUT") == 0 ) break;
		memset( mat, 0, sizeof( mat ) );
		if( strcmp(s,"START") == 0 ){
			scanf("%d", &n);
			for(int i=1 ; i <= n ; ++i)
				scanf("%s", size[i]);
			sum = 0;
			for(int i=1 ; i <= 5 ; ++i){
				scanf("%d", &a[i]);
				sta[i] = sum+1;//把库存都拆成1
				sum += a[i];
			}
			for(int i=1 ; i <= n ; ++i){
				int st = search(size[i][0]);
				int ed = search(size[i][1]);
				for(int j=sta[st] ; j <= sta[ed]+a[ed] ; ++j)
					mat[i][j] = 1;//每件库存都连边
			}
			int ans = 0;
			memset( match, 0, sizeof( match ) );
			for(int i=1 ; i <= n ; ++i){
				memset( vis, 0, sizeof( vis ) );
				if( find(i) ) ans++;
			}
			if( ans == n ) printf("T-shirts rock!\n");
			else printf("I'd rather not wear a shirt anyway...\n");
			scanf("%s", s);
		}
	}
	return 0;
}