#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 15;

char mat[N][N];
int n,m;
int check(char ch){
	if(ch == '-') return 1;
	if(ch == '|') return 2;
	if(ch == '/') return 3;
	if(ch == '\\')return 4;
	return -1;
}
int fun1(int x,int y){
	int num = 0;
	for( ; y < m ; ++y)
		if(mat[x][y] == '-')
			num++;
		else break;
	return num;
}
int fun2(int x,int y){
	int num = 0;
	for( ; x < n ; ++x)
		if(mat[x][y] == '|')
			num++;
		else break;
	return num;
}
int fun3(int x,int y){
	int num = 0;
	for( ; x<n && y<m ; ++x,--y)
		if(mat[x][y] == '/')
			num++;
		else break;
	return num;
}
int fun4(int x,int y){
	int num = 0;
	for( ; x<n && y<m ; ++x,++y)
		if(mat[x][y] == '\\')
			num++;
		else break;
	return num;
}
int main(){
	int T,i,j,tot,s,x,y;
	scanf("%d",&T);
	while(T--){
		tot = 0;
		s = -1;
		scanf("%d%d",&n,&m);
		for(i=0 ; i < n ; ++i){
			scanf("%s",mat[i]);
			for(j=0 ; mat[i][j] ; ++j){
				if(mat[i][j] != '.'){
					tot++;
					if(s == -1){
						s = check(mat[i][j]);
						x = i; y = j;
					}
				}
			}
		}
		if(s==1)s = fun1(x,y);
		else if(s==2)s = fun2(x,y);
		else if(s==3)s = fun3(x,y);
		else if(s==4)s = fun4(x,y);
		if(s == tot)printf("CORRECT\n");
		else printf("INCORRECT\n");
	}
	return 0;
}