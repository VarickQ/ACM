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
const int M = 100000;
const int N = 100005;

struct node{
	int x,step;
}s;
int n,k,mark[N];
int v[2]={1,-1};
bool check(node a){
	if(a.x>=0 && a.x<=100000)
		return true;
	return false;
}
int bfs(){
	queue<node> q;
	s.x=n; s.step=0;
	q.push(s);
	while(!q.empty()){
		node ff=q.front(); q.pop();
		node f;
		for(int i=0 ; i < 3 ; ++i){
			if(i==2){
				f.x = ff.x+ff.x;
				f.step = ff.step+1;
				if(check(f) && mark[f.x]==2)
					return f.step;
				if(check(f) && mark[f.x]==0){
					mark[f.x] = 1;
					q.push(f);
				}
			} else {
				f.x = ff.x+v[i];
				f.step = ff.step+1;
				if(check(f) && mark[f.x]==2)
					return f.step;
				if(check(f) && mark[f.x]==0){
					mark[f.x] = 1;
					q.push(f);
				}
			}
		}
	}
	return -1;
}
int main(){
	while(scanf("%d%d",&n,&k) != EOF){
		memset(mark,0,sizeof(mark));
		mark[n] = 1;
		mark[k] = 2;
		if(n==k) printf("0\n");
		else printf("%d\n",bfs());
		//cout << bfs() << endl;
	}
	return 0;
}
