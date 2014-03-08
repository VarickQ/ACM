#include <stdio.h>
#include <math.h>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 10000000;
const int N = 35;

double mat[N][N];
char str[N][N];
map<string,int> ma;
int main(){
	int n,m,cs=1;
	double l;
	char s1[N],s2[N];
	while( scanf("%d", &n) && n ){
		ma.clear();
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str[i]);
			ma[str[i]] = i;
		}
		memset( mat, 0, sizeof( mat ) );
		scanf("%d", &m);
		for(int i=0 ; i < m ; ++i){
			scanf("%s %lf %s", s1, &l, s2);
			int a = ma[s1];
			int b = ma[s2];
			if( mat[a][b] < l )
				mat[a][b] = l;
		}
		for(int k=0 ; k < n ; ++k)
			for(int i=0 ; i < n ; ++i)
				for(int j=0 ; j < n ; ++j)
					if( mat[i][j] < mat[i][k]*mat[k][j] )
						mat[i][j] = mat[i][k]*mat[k][j];
		bool f = false;
		for(int i=0 ; i < n ; ++i)
			if( mat[i][i] > 1.0 ){
				f = true; break;
			}
		printf("Case %d: ",cs++);
		if( f ) printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}