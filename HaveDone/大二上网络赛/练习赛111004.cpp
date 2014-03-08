#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 2005
#define N 1005

struct A{
	int v,next;
}e[M];
int heade[M],k;
int belong[N],bcnt;
int stack[M*10],top;
bool instack[M*10];
int dfn[N],low[N],indx;

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++indx;	//为节点u设定次序编号和Low初值
	instack[u] = true;		//标记进入栈
	stack[top++] = u;		//将节点u压入栈中
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){//枚举每一条边
		if(!dfn[e[i].v]){	//如果节点v未被访问过
			tarjan(e[i].v);	//继续向下找
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		} else if(instack[e[i].v] && dfn[e[i].v] < low[u])
			//如果节点u还在栈内
			low[u] = dfn[e[i].v];
	}
	
	if(dfn[u]==low[u]){		//如果节点u是强连通分量的根
		bcnt++;
		int temp;
		do{
			temp = stack[--top];	//将v退栈，为该强连通分量中一个顶点
			instack[temp] = false;
			belong[temp] = bcnt;	//缩点，bcnt就是强连通分量的个数
		}while(u != temp);
	}
}
int main(){
	int T,n,m,u,v,i;
	scanf("%d",&T);
	while(T--){
		memset(heade,-1,sizeof(heade));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		bcnt = indx = top = k = 0;

		scanf("%d%d",&n,&m);
		for(i=0 ; i < m ; ++i){
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		printf("%d\n",bcnt);
		scanf("%d",&n);
		if(n == -1) break;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;

struct A{
	char cod[12][12];
	char c[5];
}a[105];
char mat[12][12],out[105];
int num[105],n;
int check(int n){
	int res = inf;
	int i,j,k,p,cnt = 0;
	for(i=0 ; i < 10 ; ++i)//0
		for(j=0 ; j < 10 ; ++j)
			if(a[n].cod[i][j] != mat[i][j])
				cnt++;
	if(cnt < res) res = cnt;
	cnt = 0;
	for(i=0 ; i < 10 ; ++i)//90
		for(k=0,j=9 ; j>=0 && k<10; --j,++k)
			if(a[n].cod[i][k] != mat[j][i])
				cnt++;
	if(cnt < res) res = cnt;
	cnt = 0;
	for(p=0,i=9 ; i>=0 && p<10 ; --i,++p)//180
		for(k=0,j=9 ; j>=0 && k<10; --j,++k)
			if(a[n].cod[p][k] != mat[i][j])
				cnt++;
	if(cnt < res) res = cnt;
	cnt = 0;
	for(p=0,i=9 ; i>=0 && p<10 ; --i,++p)//270
		for(j=0 ; j < 10 ; ++j)
			if(a[n].cod[p][j] != mat[j][i])
				cnt++;
	if(cnt < res) res = cnt;
	return res;
}
char fun(){
	memset(num,0,sizeof(num));
	int i,temp,pos=0,ans=inf;
	for(i=0 ; i < n ; ++i){
		temp = check(i);
		if(temp > 20) continue;
		if(temp < ans){
			ans = temp;
			pos = i;
		}
	}
	return a[pos].c[0];
}
int main(){
	int m,i,j,k;
	while(scanf("%d",&n) == 1){
		memset(out,0,sizeof(out));
		for(i=0 ; i < n ; ++i){
			scanf("%s",a[i].c);
			for(j=0 ; j < 10 ; ++j)
				scanf("%s",a[i].cod[j]);
		}
		scanf("%d",&m);
		for(i=0,k=0 ; i < m ; ++i){
			for(j=0 ; j < 10 ; ++j)
				scanf("%s",mat[j]);
			out[k++] = fun();
			//printf("%c",fun());
		}
		for(i=0 ; i < k ; ++i)
			printf("%c",out[i]);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int inf = 1000000000;

int w[1005],pre[1005],ans[1005];
ll a[1005],dp[1005];
int main(){
	int n,cs=0;
	while(scanf("%d",&n) == 1){
		if(n==0) break;
		if(cs==0) cs++;
		else printf("\n");
		memset(w,0,sizeof(w));
		memset(a,0,sizeof(a));
		pre[0] = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%lld",&a[i]);
			if(i>1) a[i]+=a[i-1];
			pre[i] = i;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1 ; i <= n ; ++i){
			dp[i] = (a[i]-100)*(a[i]-100);
			pre[i] = 0;	w[i] = 1;
			for(int j=0 ; j < i ; ++j){
				if(dp[i]>dp[j]+(a[i]-a[j]-100)*(a[i]-a[j]-100)){
					dp[i]=dp[j]+(a[i]-a[j]-100)*(a[i]-a[j]-100);
					pre[i] = j;
					w[i] = w[j]+1;
				}
				else if(dp[i]==dp[j]+(a[i]-a[j]-100)*(a[i]-a[j]-100)){
					if(w[pre[i]] > w[j]){
						pre[i] = j;
						w[i] = w[j]+1;
					}
				}
			}
		}
		ans[0] = n;
		int k = 1,i = n;
		while(i!=pre[i]){
			ans[k++] = pre[i];
			i = pre[i];
		}
		printf("p=%lld\n",dp[n]);
		int cnt = 1;
		for(int i=k-1 ; i >= 0 ; --i,++cnt){
			printf(" %d",ans[i]);
			if(cnt%30==0)
				printf("\n");
		}
		if(cnt%30) printf("\n");
	}
	return 0;
}