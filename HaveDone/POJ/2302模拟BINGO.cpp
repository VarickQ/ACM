#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define N 510
#define M 10010

int mat[6][6],m;
bool mark[6][6],f;
void Mark(int n){
	for(int i=1 ; i <= 5 ; ++i)
		for(int j=1 ; j <= 5 ; ++j)
			if(mat[i][j] == m)
				mark[i][j] = true;
}
bool checkRow(){
	int cnt;
	for(int i=1 ; i <= 5 ; ++i){
		cnt = 0;
		for(int j=1 ; j <= 5 ; ++j)
			if(mark[i][j]) cnt++;
		if(cnt==5) return true;
	}
	return false;
}
bool checkCol(){
	int cnt;
	for(int i=1 ; i <= 5 ; ++i){
		cnt = 0;
		for(int j=1 ; j <= 5 ; ++j)
			if(mark[j][i]) cnt++;
		if(cnt==5) return true;
	}
	return false;
}
bool checkDia(){
	if(mark[1][1] && mark[2][2] && mark[4][4] && mark[5][5])
		return true;
	if(mark[1][5] && mark[2][4] && mark[4][2] && mark[5][1])
		return true;
	return false;
}
int main(){
	int n,i,j,t;
	scanf("%d",&n);
	while(n--)
	{
		memset(mark,0,sizeof(mark));
		for(i=1 ; i <= 5 ; ++i){
			for(j=1 ; j <= 5 ; ++j){
				if(i==3 && j==3)continue;
				scanf("%d",&mat[i][j]);
			}
		}
		mark[3][3] = true;
		for(t=1,f=false ; t <= 75 ; ++t){
			scanf("%d",&m);
			if(f) continue;
			Mark(m);
			if(checkRow() || checkCol() || checkDia()){
				f = true;
				printf("BINGO after %d numbers announced\n",t);
			}
		}
	}
	return 0;
}