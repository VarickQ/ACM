//打表程序
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 1005;
typedef long long ll;

int x,y,d,ans;
struct node{
	int now,c,step;
}s;
queue<node> qu;
int bfs(){
	s.now = x+1;
	s.c = 1;
	s.step = 1;
	qu.push(s);
	while( !qu.empty() ){
		node f,ff = qu.front(); qu.pop();
		f.c = ff.c+1;

		f.step = ff.step;
		f.now = ff.now+f.step;
		if( f.now == y && f.step==1 ) return f.c;
		else if( f.now < y ) qu.push(f);

		
		f.step = ff.step+1;
		f.now = ff.now+f.step;
		if( f.now == y && f.step==1 ) return f.c;
		else if( f.now < y ) qu.push(f);

		
		if(ff.step>1)f.step = ff.step-1;
		f.now = ff.now+f.step;
		if( f.now == y && f.step==1 ) return f.c;
		else if( f.now < y ) qu.push(f);
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	//freopen("in.txt","r",stdin);
	freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	int T;
	/*scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &x, &y);*/
		for(int i=2 ; i <= 55 ; ++i){
			while(!qu.empty())qu.pop();
			x = 1; y = i;
			printf("%d\t%d\n",y-x,bfs());
		}
	//}
	return 0;
}

//AC程序
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 1005;
typedef long long ll;

int x,y,d;
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &x, &y);
		d = y-x;
		if( d == 0 ){
			printf("0\n");
			continue;
		}
		int num = 2,ans=1;
		while( d-num >= 0 ){
			d -= num;
			num += 2;
			ans++;
		}
		if( d == 0 ) printf("%d\n",(ans-1)*2);
		else if( d <= ans ) printf("%d\n", ans*2-1);
		else printf("%d\n", ans*2);
	}
	return 0;
}