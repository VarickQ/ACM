#include<stdio.h>
typedef __int64 in64;
struct Edge{
	int to;
	int cost;
	int next;
};
Edge e[30000];
int e_end;
struct Node{
	in64 dis;
	int cnt;
	int pre;
	bool vis;
};
Node nd[6000];
int head[6000];
#include<queue>
using namespace std;
in64 INF=1;
queue<int>q;
bool SPFA(int s,int t,int n){
	while(q.empty()==false)q.pop();
	int u,i,v;
	for(i=0;i<=n;i++){
		nd[i].dis=INF;
		nd[i].cnt=-1;
		nd[i].pre=-1;
		nd[i].vis=false;
	}
	nd[s].dis=0;
	nd[s].cnt=0;
	nd[s].pre=-1;
	q.push(s);
	while(q.empty()==false){
		u=q.front();
		q.pop();
		nd[u].vis=false;
		for(i=head[u];i!=-1;i=e[i].next){
			v=e[i].to;
			if(	(nd[v].dis>nd[u].dis+e[i].cost)
				|| ( nd[v].dis==nd[u].dis+e[i].cost && nd[v].cnt<nd[u].cnt+1)
					|| ( s==v && nd[v].cnt==0)
				){
				nd[v].dis=nd[u].dis+e[i].cost;
				nd[v].pre=u;
				nd[v].cnt=nd[u].cnt+1;
				if(nd[v].vis==false){
					nd[v].vis=true;
					q.push(v);
				}
			}
		}
	}
	return true;
}
int get_type(char c){
	if(c=='L')return 0;
	if(c=='O')return 1;
	if(c=='V')return 2;
	return 3;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	INF<<=62;
	int t,n,m,i;
	int a,b,c,d;
	int u,v;
	char s[20];
	int ca=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=0;i<=n*4;i++)
			head[i]=-1;
		e_end=0;
		while(m--){
			scanf("%d%d%d%s",&a,&b,&c,s);
			a--;b--;
			d=get_type(s[0]);
			u=a*4+d;
			v=b*4+(d+1)%4;
			e[e_end].cost=c;
			e[e_end].to=v;
			e[e_end].next=head[u];
			head[u]=e_end++;
			u=b*4+d;
			v=a*4+(d+1)%4;
			e[e_end].cost=c;
			e[e_end].to=v;
			e[e_end].next=head[u];
			head[u]=e_end++;
		}
		a=4*n-4;
		SPFA(0,a,4*n);
		if(a==0 && nd[a].cnt==0)
			nd[a].dis=INF;
		if(nd[a].dis>=INF )
			printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",ca++);
		else
			printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",ca++,nd[a].dis,nd[a].cnt/4);
	}
	return 0;
}
