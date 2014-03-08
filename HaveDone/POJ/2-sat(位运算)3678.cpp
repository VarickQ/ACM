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
	int v,next;
}e[M];
int heade[N],k;
int belong[N],bcnt,dfn[N],low[N],index;
int stack[N],top;
bool instack[N];

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
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
	k = top = index = bcnt = 0;
}
//(1)A and B = 0 A->!B , B->!A
//(2)A and B = 1 !A->A , !B->B
//(3)A or B = 0 A->!A , B->!B
//(4)A or B = 1 !A->B , !B->A
//(5)A xor B = 0 A->B , B->A , !A->!B ,!B->!A
//(6)A xor B = 1 A->!B, B->!A , !B->A , !A->B
int main()
{
	int n,m,i,a,b,c;
	char s[5];
	while(scanf("%d%d",&n,&m) == 2)
	{
		init();
		for(i=0 ; i < m ; ++i){
			scanf("%d%d%d%s",&a,&b,&c,s);
			a++; b++;
			if(!strcmp(s,"AND")){
				if(c==0){
					add(a,b+n);
					add(b,a+n);
				} else {
					add(a+n,a);
					add(b+n,b);
				}
			}
			else if(!strcmp(s,"OR")){
				if(c==0){
					add(a,a+n);
					add(b,b+n);
				} else {
					add(a+n,b);
					add(b+n,a);
				}
			}
			else if(!strcmp(s,"XOR")){
				if(c==0){
					add(a,b);
					add(a+n,b+n);
					add(b,a);
					add(b+n,a+n);
				} else {
					add(a,b+n);
					add(b,a+n);
					add(a+n,b);
					add(b+n,a);
				}
			}
		}
		for(i=1 ; i <= 2*n ; ++i)
			if(!dfn[i]) tarjan(i);
		for(i=1 ; i <= n ; ++i)
			if(belong[i]==belong[i+n])break;
		if(i<=n)puts("NO");
		else puts("YES");
	}
	return 0;
}