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
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 10100;
const int N = 15;

bool su[M],vis[M];
void primelist(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
}
struct node{
	int num,step;
}cu;
queue<node> q;
int base[4]={1,10,100,1000};
int bfs(int a,int tar){
	int b[4];
	while(!q.empty()) q.pop();
	cu.num = a; cu.step = 0;
	vis[a] = true;
	q.push(cu);
	while(!q.empty()){
		node ff = q.front(); q.pop();
		if(ff.num==tar) return ff.step;
		b[3]=ff.num%10;
		b[2]=ff.num%100/10;
		b[1]=ff.num%1000/100;
		b[0]=ff.num/1000;
		node f;
		for(int i=0 ; i <= 9 ; ++i){
			f.num = ff.num-b[0]*1000+i*1000;
			if(f.num != ff.num && i!=0 && !su[f.num] && !vis[f.num]){
				f.step = ff.step+1;
				vis[f.num] = true;
				q.push(f);
			}
			for(int k=1 ; k < 4 ; ++k){
				f.num = ff.num-ff.num%base[k]+ff.num%base[k-1]+i*base[k-1];
				if(!su[f.num] && f.num!=ff.num && !vis[f.num]){
					f.step = ff.step+1;
					vis[f.num] = true;
					q.push(f);
				}
			}
		}
	}
	return 0;
}
int main(){
	primelist();
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		if(n == m) printf("0\n");
		else printf("%d\n",bfs(n,m));
	}
	return 0;
}