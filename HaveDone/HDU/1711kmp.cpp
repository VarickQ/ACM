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
const int N   = 1000005;

int a[N],b[10005],next[10005],n,m;
void Next(){
	int i = 0, j = -1;
	next[0] = -1;
	while( i < m ){
		if( j == -1 || b[i] == b[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int KMP(){
	int i = 0, j = 0;
	while( i < n && j < m ){
		if( j == -1 || a[i] == b[j] )
			++i, ++j;
		else j = next[j];
	}
	if( j >= m )
		return i - m + 1;
	else return -1;
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &a[i]);
		for(int i=0 ; i < m ; ++i)
			scanf("%d", &b[i]);
		Next();
		printf("%d\n", KMP());
	}
	return 0;
}