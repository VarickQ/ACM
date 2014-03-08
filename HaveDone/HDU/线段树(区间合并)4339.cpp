#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
const int N = 1000100;
typedef __int64 LL;

char s1[N], s2[N];
struct Node{
	int left,right,lmax;
}tr[N*10];
void up(int id){
	tr[id].lmax = tr[id<<1].lmax;
	if( tr[id].lmax == tr[id<<1].right-tr[id<<1].left+1)
		tr[id].lmax += tr[id<<1|1].lmax;
}
void CreatT(int l,int r, int id){
	tr[id].left = l;
	tr[id].right = r;
	if( l == r ){
		tr[id].lmax = s1[l-1]==s2[l-1]?1:0;
		return ;
	}
	int mid = l+r>>1;
	CreatT( l, mid, id<<1 );
	CreatT( mid+1, r, id<<1|1 );
	up( id );
}
void update(int x,int id){
	if( tr[id].left == tr[id].right ){
		tr[id].lmax = s1[x-1]==s2[x-1]?1:0;
		return ;
	}
	int mid = tr[id].left+tr[id].right>>1;
	if( mid >= x ) update( x, id<<1 );
	else update( x, id<<1|1 );
	up( id );
}
int find(int x,int id){
	if( tr[id].left == x ) return tr[id].lmax;
	int mid = tr[id].left+tr[id].right>>1;
	if( mid >= x ){
		int tmp = find( x, id<<1 );
		if( tmp == mid - x + 1 )
			tmp += tr[id<<1|1].lmax;
		return tmp;
	}
	else return find( x, id<<1|1 );
}
int main(){
	int T, q, cs = 1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s%s", s1, s2);
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		CreatT( 1, min(l1,l2), 1 );
		printf("Case %d:\n", cs++);
		scanf("%d", &q);
		int a, b, c;
		char s[2];
		while( q-- ){
			scanf("%d", &a);
			if( a == 1 ){
				scanf("%d%d%s", &c, &b, s);
				if( b >= min(l1,l2) ) continue;
				if( c == 1 ) s1[b] = s[0];
				else s2[b] = s[0];
				update( b+1, 1 );
			} else {
				scanf("%d", &b);
				if( b >= min(l1,l2) ) printf("0\n");
				else printf("%d\n", find(b+1,1));
			}
		}
	}
	return 0;
}