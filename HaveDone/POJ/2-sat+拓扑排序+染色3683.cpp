#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int N = 2010;
const int M = 2000010;

struct E{
	int u,v,next;
}e[M],e1[M];
int heade[N],k,heade1[N],k1;
int belong[N],bcnt,dfn[N],low[N],index;
int stack[N],top,in[N],opp[N],col[N];
bool instack[N];

void add(int u,int v){
	e[k].u = u;
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void add1(int u,int v){
	e1[k1].u = u;
	e1[k1].v = v;
	e1[k1].next = heade1[u];
	heade1[u] = k1++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++index;
	instack[u] = true;
	stack[top++] = u;
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){
		if(!dfn[e[i].v]){
			tarjan(e[i].v);
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		}else if(instack[e[i].v] && dfn[e[i].v] < low[u])
			low[u] = dfn[e[i].v];
	}
	if(low[u] == dfn[u]){
		bcnt++;
		int temp;
		do{
			temp = stack[--top];
			instack[temp] = false;
			belong[temp] = bcnt;
		}while(u != temp);
	}
}
void init(){
	memset(heade,-1,sizeof(heade));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	k = top = index = 0;
}
//给定N个区间(A,B),和长度len,
//让你对于每一组区间在(A,A+len)和(B-len,B)这两个区间中选一个,
//使得选取的区间交集为空集
int d[N],s[N],t[N];
bool check(int s1,int ed1,int s2,int ed2){
	if(ed1<=s2 || ed2<=s1)return false;//没有交集
	return true;//有交集
}
void topsort(){
	memset(stack,0,sizeof(stack));
	memset(col,0,sizeof(col));
	top = 0;
	for(int i=1 ; i <= bcnt ; ++i)
		if(in[i]==0) stack[top++] = i;
	while(top){
		int u = stack[--top];
		if(col[u] == 0){
			col[u] = 1;
			col[opp[u]] = -1;
		}
		for(int i=heade1[u] ; i!=-1 ; i=e1[i].next)
			if(--in[e1[i].v] == 0)
				stack[top++] = e1[i].v;
	}
}
int main()
{
	int n,i,sh,sm,th,tm;
	while(scanf("%d",&n) == 1)
	{
		init();
		bcnt = 0;
		for(i=1 ; i <= n ; ++i){
			scanf("%d:%d %d:%d %d",&sh,&sm,&th,&tm,&d[i]);
			s[i] = sh*60+sm;
			t[i] = th*60+tm;
		}
		for(i=1 ; i <= n ; ++i)
			for(int j=i+1 ; j <= n ; j++){
				if(check(s[i],s[i]+d[i],s[j],s[j]+d[j])){
					add(i,j+n);
					add(j,i+n);
				}
				if(check(s[i],s[i]+d[i],t[j]-d[j],t[j])){
					add(i,j);
					add(j+n,i+n);
				}
				if(check(t[i]-d[i],t[i],s[j],s[j]+d[j])){
					add(i+n,j+n);
					add(j,i);
				}
				if(check(t[i]-d[i],t[i],t[j]-d[j],t[j])){
					add(i+n,j);
					add(j+n,i);
				}
			}
		for(i=1 ; i <= n*2 ; ++i)
			if(!dfn[i]) tarjan(i);
		for(i=1 ; i <= n ; ++i){
			if(belong[i]==belong[i+n]) break;
			opp[belong[i]] = belong[i+n];
			opp[belong[i+n]] = belong[i];
		}
		if(i<=n) printf("NO\n");
		else {
			printf("YES\n");
			memset(in,0,sizeof(in));
			memset(heade1,-1,sizeof(heade1));
			k1 = 0;
			for(i=0 ; i < k ; ++i)
			{
				if(belong[e[i].u] != belong[e[i].v]){
					add1(belong[e[i].v],belong[e[i].u]);
					in[belong[e[i].u]]++;
				}
			}
			topsort();
			for(i=1 ; i <= n ; i++)
				if(col[belong[i]] == 1){
					printf("%02d:%02d %02d:%02d\n",s[i]/60,s[i]%60,(s[i]+d[i])/60,(s[i]+d[i])%60);
				} else {
					printf("%02d:%02d %02d:%02d\n",(t[i]-d[i])/60,(t[i]-d[i])%60,t[i]/60,t[i]%60);
				}
		}
	}
	return 0;
}