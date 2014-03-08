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
const int N   = 4005;

char str[N][202],s[202],res[202],temp[202];
int next[202],n;
void NEXT( char *str ){
    int i = 0,j = -1;
    next[0] = -1;
    int len = strlen(str);
	while(i < len){
        if(j == -1 || str[i] == str[j])
            ++i,++j,next[i] = j;
		else j = next[j];
    }
}
int Max,ans;
void KMP( int len, int s2 ){
	NEXT( s );
	Max = 202;
	for(int k=0 ; k < n ; ++k){
		int i = 0, j = 0, m = 0;
		while(i < len && j < s2){
			if(j == -1 || str[k][i] == s[j])
				i ++,j ++;
			else j = next[j];
			if(j > m) m = j;
		}
		if( Max > m ) Max = m;
	}
}
int main(){
	int len,pos;
	while( scanf("%d", &n) && n ){
		memset( res, 0, sizeof( res ) );
		len = inf;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str[i]);
			if( len > strlen( str[i] ) ){
				len = strlen( str[i] );
				pos = i;
			}
		}
		ans = 0;
		for(int i=0 ; i < len ; ++i){
			strcpy( s, str[pos]+i );
			s[len-i] = '\0';
			memset( next, 0, sizeof( next ) );
			KMP( len, strlen(s) );
			if( ans < Max ){
				ans = Max;
				strncpy( res, str[pos]+i, ans );
				res[ans] = '\0';
			}
			else if( ans == Max ){
				strncpy( temp, str[pos]+i, ans );
				temp[ans] = '\0';
				if( strcmp( res, temp ) > 0)
					strcpy( res, temp );
			}
		}
		if( ans == 0 ) printf("IDENTITY LOST\n");
		else printf("%s\n", res);
	}
	return 0;
}