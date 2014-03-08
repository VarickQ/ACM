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
const int N   = 10005;

char str[15][65],s[65],res[65],temp[65];
int next[65],n;
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
void KMP( int s2 ){
	NEXT( s );
	Max = 65;
	for(int k=0 ; k < n ; ++k){
		int i = 0, j = 0, m = 0;
		while(i < 60 && j < s2){
			if(j == -1 || str[k][i] == s[j])
				i ++,j ++;
			else j = next[j];
			if(j > m) m = j;
		}
		if( Max > m ) Max = m;
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i)
			scanf("%s", str[i]);
		ans = 0;
		for(int i=0 ; i < 60 ; ++i){
			strcpy( s, str[0]+i );
			s[60-i] = '\0';
			memset( next, 0, sizeof( next ) );
			KMP( strlen(s) );
			if( ans < Max ){
				ans = Max;
				strncpy( res, str[0]+i, ans );
				res[ans] = '\0';
			}
			else if( ans == Max ){
				strncpy( temp, str[0]+i, ans );
				temp[ans] = '\0';
				if( strcmp( res, temp ) > 0)
					strcpy( res, temp );
			}
		}
		if( ans < 3 ) printf("no significant commonalities\n");
		else printf("%s\n", res);
	}
	return 0;
}