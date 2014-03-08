#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int N = 50005;
vector<int>E[N];
int b[N],c[N],ret[N],L[N],R[N],k;
void get(int x)
{
	int i,j;
	L[x]=R[x]=++k;
	for(i=E[x].size()-1;i>=0;i--)
	{
		j=E[x][i];
		get(j);
		if(R[x]<R[j])R[x]=R[j];
	}
}
struct P
{
	int l,r,mid,key,pos;
}arr[4*N];
void build(int le,int ri,int c)
{
	arr[c].l=le;
	arr[c].r=ri;
	arr[c].mid=(le+ri)/2;
	arr[c].key=arr[c].pos=-1;
	if(le==ri)return ;
	build(le,arr[c].mid,c+c);
	build(arr[c].mid+1,ri,c+c+1);
}
void insert(int x,int v,int c)
{
	if(v>arr[c].key)
	{
		arr[c].key=v;
		arr[c].pos=x;
	}
	if(arr[c].l==arr[c].r)return ;
	if(L[x]<=arr[c].mid)insert(x,v,c+c);
	else insert(x,v,c+c+1);
}
int res,id;
void find(int le,int ri,int c)
{
	if(res>=arr[c].key)return ;
	if(le<=arr[c].l&&ri>=arr[c].r)
	{
		id=arr[c].pos;
		res=arr[c].key;
		return ;
	}
	if(le<=arr[c].mid)find(le,ri,c+c);
	if(ri>arr[c].mid)find(le,ri,c+c+1);
}
int f[N];
bool cmp(int x,int y)
{
	if(c[x]==c[y])return x<y;
	return c[x]>c[y];
}
bool use[1000001];
int main()
{
	int n,m,i,T,a;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	scanf("%d",&T);
	while(T--)
	{
        int flag=0;
		//for(i=0;i<n;i++)E[i].clear();
		scanf("%d%d",&n,&m);
		memset(use,false,sizeof(use));
		for(i=0;i<n;i++)E[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,b+i,c+i);
			if(b[i]<0||b[i]>1000000)flag=1;
			if(use[b[i]])flag=1;
			use[b[i]]=true;
			E[a].push_back(i);
		}
		k=0;
		get(0);
		//if(k!=n)puts("error");
		//for(i=0;i<n;i++)printf("i:%d L:%d R:%d \n",i,L[i],R[i]);
		build(1,k,1);
		for(i=0;i<n;i++)f[i]=i;
		sort(f,f+n,cmp);
		for(i=0;i<n;i++)
		{
			res=id=-1;
			find(L[f[i]],R[f[i]],1);
			ret[f[i]]=id;
			insert(f[i],b[f[i]],1);
		}
		while(m--)
		{
			scanf("%d",&a);
			if(!a)flag=1;
			printf("%d\n",ret[a]);
		}
        if(flag)puts("error");
		
		
	}
	//puts("ook");
	return 0;
}
