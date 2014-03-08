/*��m����, ����ǰһ�����ܿ���һ��, ÿ������������, 
��һ�Ѿ��ܿ���, ��Щ����������ȫ��ͬ. ��2n�Ѳ�ͬ��Կ��, 
ÿ�Ѷ�Ӧһ����, ��ЩԿ�ױ��ֳ�n��, ÿ��Կ��ֻ��ȡ���е�һ��,
ȡ����һ��, ��һ�Ѿͻ���ʧ, ������ܿ�������.*/ 

//Կ�׶Բ���ͬʱȡ��ȡ��һ����һ����ʧ���� x&y==0;
//����ֻ��һ��Կ�ף���x|y==1;

	2723	Accepted	404K	32MS	C++	1959B	2011-08-14 10:13:15
//����
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int N = 5010;
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
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else if(instack[v] && dfn[v] < low[u])
			low[u] = dfn[v];
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
int a[N][2],b[N][2],n,m;
bool check(int mid){
	int i;
	init();
	for(i=0 ; i < n ; ++i){
		add(a[i][0],a[i][1]+2*n);
		add(a[i][1],a[i][0]+2*n);
	}
	for(i=0 ; i < mid ; ++i){
		add(b[i][0]+2*n,b[i][1]);
		add(b[i][1]+2*n,b[i][0]);
	}
	for(i=0 ; i < n*4 ; ++i)
		if(!dfn[i]) tarjan(i);
	for(i=0 ; i < n*2 ; ++i)
		if(belong[i] == belong[i+2*n])
			return false;
	return true;
}
int main()
{
	int i;
	while(scanf("%d%d",&n,&m) &&(n+m))
	{
		for(i=0 ; i < n ; ++i)
			scanf("%d%d",&a[i][0],&a[i][1]);
		for(i=0 ; i < m ; ++i)
			scanf("%d%d",&b[i][0],&b[i][1]);
		int mid,l=1,r=m,ans=0;
		while(l <= r){
			mid = (l+r)>>1;
			if(check(mid)){
				ans = mid;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
	2723	Accepted	364K	1125MS	C++	1693B	2011-08-14 10:12:07
//û�ж���
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int N = 5010;
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
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else if(instack[v] && dfn[v] < low[u])
			low[u] = dfn[v];
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
int n,m;
int main()
{
	int i,a,b,ans;
	while(scanf("%d%d",&n,&m) &&(n+m))
	{
		memset(heade,-1,sizeof(heade));
		k = 0;
		for(i=0 ; i < n ; ++i){
			scanf("%d%d",&a,&b);
			add(a,b+2*n);
			add(b,a+2*n);
		}
		bool flag = true;
		ans = 0;
		for(int j=0 ; j < m ; ++j){
			scanf("%d%d",&a,&b);
			if(flag){
				add(a+2*n,b);
				add(b+2*n,a);
				memset(dfn,0,sizeof(dfn));
				memset(low,0,sizeof(low));
				top = index = bcnt = 0;
				for(i=0 ; i < 4*n ; ++i)
					if(!dfn[i]) tarjan(i);
				for(i=0 ; i < 2*n ; ++i)
					if(belong[i]==belong[i+2*n]){
						flag = false;
						break;
					}
				ans += flag;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}