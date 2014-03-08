#include<stdio.h>
#include<vector>
using namespace std;
struct Node{
	int z;
	int n;
};
Node nd[50000];
vector<int>g[50000];
int n;
int mn,mx,mxp;
void dfs(int r){
	if(nd[r].n>mn ){
		if(mx<nd[r].z)
		{
			mx=nd[r].z;
			mxp=r;
		}
	}
	int i;
	for(i=0;i<g[r].size();i++){
		dfs(g[r][i]);
	}
}
int main(){
	int t,m,i,a,b,c;
    freopen("data.in", "r", stdin);
    freopen("forcedata_1.out", "w", stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			g[i].clear();
		}
		for(i=1;i<n;i++){
			scanf("%d%d%d",&a,&b,&c);
			nd[i].n=c;
			nd[i].z=b;
			g[a].push_back(i);
		}
		while(m--){
			scanf("%d",&a);
			mn=nd[a].n;
			mx=-1;
			mxp=-1;
			dfs(a);
			printf("%d\n",mxp);
		}
	}
	return 0;
}
