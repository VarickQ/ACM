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
const int N = 510;
typedef long long LL;

char s[N],s1[N],s2[N];
int c[]={0,10,8,6,5,4,3,2,1};
struct Player{
	char fir[N],las[N];
	int sco,tt[10];
	Player(){
		sco = 0;
		memset(tt,0,sizeof(tt));
	}
}a[N];
struct T{
	char tem[N];
	int sco;
}tm[N];
int cmp( const void *a , const void *b ){
    struct Player *c = (Player *)a;
	struct Player *d = (Player *)b;
	if(c->sco != d->sco) return d->sco - c->sco;
	else {
		for(int i=1 ; i <= 8 ; ++i)
			if( d->tt[i] != c->tt[i] )
				return d->tt[i] - c->tt[i];
		if( !strcmp(d->las,c->las) )
			return strcmp(c->fir,d->fir);
		return strcmp(c->las,d->las);
	}
}
int cmpp( const void *a , const void *b ){
    struct T *c = (T *)a;
	struct T *d = (T *)b;
	if( c->sco != d->sco ) return d->sco-c->sco;
	return strcmp(c->tem,d->tem);
}
int main(){
	int n, cs = 1;
	while( scanf("%d\n", &n) && n ){
		memset( a, 0, sizeof( a ) );
		memset( tm, 0, sizeof( tm ) );
		int cnt = 0, ct = 0;
		for(int cc=0 ; cc < n ; ++cc){
			gets(s);
			gets(s);
			while( 1 ){
				scanf("%s", s);
				if( !strcmp(s,"---") ) break;
				int id,pos;
				sscanf(s,"%d",&id);
				scanf("%s%s", s1, s2);
				bool f = false;
				for(int j=0 ; j < cnt ; ++j){
					if( !strcmp(a[j].fir,s1) && !strcmp(a[j].las,s2) ){
						pos = j; f = true; break;
					}
				}
				if( f ){
					a[pos].sco += c[id];
					a[pos].tt[id]++;
				} else {
					strcpy(a[cnt].fir,s1);
					strcpy(a[cnt].las,s2);
					a[cnt].tt[id] = 1;
					a[cnt++].sco += c[id];
				}
				gets(s);
				int j,len = 0;
				for(  j=0 ; s[j] ; ++j )
					if( s[j] != ' ' ) break;
				for( ; s[j]!='.' ; ++j )
					s1[len++] = s[j];
				s1[len] = '\0';
				f = false;
				for( j=0 ; j < ct ; ++j )
					if( !strcmp(tm[j].tem,s1) ){
						f = true; break;
					}
				if( f )	tm[j].sco += c[id];
				else{
					strcpy(tm[j].tem,s1);
					tm[ct++].sco = c[id];
				}
			}
			getchar();
		}
		printf("Season %d:\nDrivers Standing:\n", cs++);
		qsort(a,cnt,sizeof(a[0]),cmp);
		qsort(tm,ct,sizeof(tm[0]),cmpp);
		for(int i=0 ; i < cnt ; ++i){
			printf("%s %s ", a[i].fir, a[i].las, a[i].sco);
			int l = strlen(a[i].fir)+strlen(a[i].las);
			for(int j=l+1 ; j < 25 ; ++j)printf(" ");
			printf("%d\n", a[i].sco);
		}
		printf("\nTeams Standing:\n");
		for(int i=0 ; i < ct ; ++i){
			printf("%s ", tm[i].tem);
			int l = strlen(tm[i].tem);
			for(int j=l ; j < 25 ; ++j)printf(" ");
			printf("%d\n", tm[i].sco);
		}
		printf("\n");
	}
	return 0;
}