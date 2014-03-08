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
const int inf = 2000000000;
const int N   = 105;

int n,p,s;
int Dull[25],mark[25];
struct P{
	int cost;
	char name[15];
}a[15];
int main(){
	int x,Max,now;
	while( scanf("%d", &n) && n ){
		scanf("%d%d", &p, &s);
		for(int i=0 ; i < n ; ++i)
			scanf("%d", &Dull[i]);
		for(int i=0 ; i < p ; ++i)
			scanf("%d%s", &a[i].cost, a[i].name);
		memset( mark, 0, sizeof( mark ) );
		Max = now = 0;
		for(int i=0 ; i < s ; ++i){
			scanf("%d", &x);
			if( x > 0 ){
				x--;
				now += a[x].cost;
				for(int j=0 ; a[x].name[j] ; ++j){
					if( mark[a[x].name[j]-'A']==0 )
						now += Dull[a[x].name[j]-'A'];
					mark[a[x].name[j]-'A']++;
				}
			} else {
				x = -x;
				x--;
				now -= a[x].cost;
				for(int j=0 ; a[x].name[j] ; ++j){
					mark[a[x].name[j]-'A']--;
					if(mark[a[x].name[j]-'A']==0)
						now -= Dull[a[x].name[j]-'A'];
				}
			}
			if( Max < now ) Max = now;
		}
		printf("%d\n", Max);
	}
	return 0;
}