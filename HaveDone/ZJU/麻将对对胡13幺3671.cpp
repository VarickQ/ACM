#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 50;
typedef long long LL;

char str[N];
set<pair<int,int> > ans;
int a[5][15];
int id( char ch ){
	if( ch == 'p' ) return 1;
	if( ch == 's' ) return 2;
	if( ch == 'm' ) return 3;
	return 4;
}
bool dui(){
	int k=0;
    for(int i=1 ; i <= 4 ; ++i)
		for(int j=1 ; j <= 9 ; ++j)
			if( a[i][j] == 2 ) k++;
    return k == 7;
}
bool thth(){
	int i,j;
    for( i=1 ; i <= 3 ; ++i )
        if( !a[i][1] || !a[i][9] )
			return false;
    for( i=1 ; i <= 7 ; ++i )
        if( !a[4][i] ) return false;
    for( i=1 ; i <= 3 ; ++i )
		for( j=1 ; j <= 9 ; ++j )
			if( a[i][j] && (j!=1&&j!=9) )
				return false;
    return true;
}
int main(){
	while( scanf("%s", str) != EOF ){
		memset( a, 0, sizeof( a ) );
		ans.clear();
		int len = strlen(str);
		int cnt = 0;
		for(int i=0 ; i+1 < len ; i+=2)
			a[id(str[i+1])][str[i]-'0']++;
		if( dui() ) puts("Seven Pairs");
		else if( thth() )
			puts("Thirteen Orphans");
		else puts("Neither!");
	}
	return 0;
}