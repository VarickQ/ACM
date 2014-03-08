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
const int N   = 2000000;
const int M   = 1100000;
const int inf = 2000000000;
typedef long long LL;

struct Node{
	char a[15];
	int step;
	bool operator < (const Node &c) const{
		return step > c.step;
	}
}s;
priority_queue<Node> qu;
map<int,bool> ma;
int x, y;
int bfs(){
	char tmp;
	while( !qu.empty() ) qu.pop();
	qu.push(s);
	while( !qu.empty() ){
		Node ff,f = qu.top(); qu.pop();
		if( !strcmp( f.a+1, "123456789" ) ) return f.step;
		ff.step = f.step+1;
		
		if( ff.step > y ) continue;

		strcpy( ff.a , f.a );//A
		tmp = ff.a[1];
		ff.a[1] = ff.a[4];
		ff.a[4] = ff.a[5];
		ff.a[5] = ff.a[2];
		ff.a[2] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
		strcpy( ff.a , f.a );//A
		tmp = ff.a[1];
		ff.a[1] = ff.a[2];
		ff.a[2] = ff.a[5];
		ff.a[5] = ff.a[4];
		ff.a[4] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}

		strcpy( ff.a , f.a );//B
		tmp = ff.a[2];
		ff.a[2] = ff.a[5];
		ff.a[5] = ff.a[6];
		ff.a[6] = ff.a[3];
		ff.a[3] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
		strcpy( ff.a , f.a );//B
		tmp = ff.a[2];
		ff.a[2] = ff.a[3];
		ff.a[3] = ff.a[6];
		ff.a[6] = ff.a[5];
		ff.a[5] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
		
		strcpy( ff.a , f.a );//C
		tmp = ff.a[4];
		ff.a[4] = ff.a[7];
		ff.a[7] = ff.a[8];
		ff.a[8] = ff.a[5];
		ff.a[5] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
		strcpy( ff.a , f.a );//C
		tmp = ff.a[4];
		ff.a[4] = ff.a[5];
		ff.a[5] = ff.a[8];
		ff.a[8] = ff.a[7];
		ff.a[7] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
		
		strcpy( ff.a , f.a );//D
		tmp = ff.a[5];
		ff.a[5] = ff.a[8];
		ff.a[8] = ff.a[9];
		ff.a[9] = ff.a[6];
		ff.a[6] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
		strcpy( ff.a , f.a );//D
		tmp = ff.a[5];
		ff.a[5] = ff.a[6];
		ff.a[6] = ff.a[9];
		ff.a[9] = ff.a[8];
		ff.a[8] = tmp;
		sscanf( ff.a+1,"%d",&x);
		if( ma.find(x)==ma.end() ){
			ma[x] = true; qu.push(ff);
		}
	}
	return -1;
}
int main(){
	int cs = 1;
	while( scanf("%s", s.a) != EOF ){
		if( !strcmp(s.a,"0000000000") ) break;
		ma.clear();
		sscanf( s.a+1,"%d",&x);
		ma[x] = true;

		y = s.a[0]-'0';
		s.step = 0;
		int ans = bfs();
		printf("%d. %d\n", cs++, ans);
	}
	return 0;
}