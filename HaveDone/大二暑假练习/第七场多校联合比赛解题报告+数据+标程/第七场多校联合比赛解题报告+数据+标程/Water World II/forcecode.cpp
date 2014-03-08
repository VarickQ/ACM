#include<stdio.h>
#define LL long long
LL h[200005];
long long ans;
long long cal(LL *a,int n){
	long long cnt=0;
	long long tmp;
	LL mx,mxp;
	mx=-1;
	int i;
	for(i=0;i<n;i++){
		if(a[i]>mx){
			mx=a[i];
			mxp=i;
		}
	}
	int md=mxp;
	mx=0;
	mxp=-1;
	for(i=0;i<md;){
		while(a[i]>=mx && i<=md){
			mx=a[i];
			i++;
		}
		mxp=i;
		while(a[i]<mx && i<=md){
			cnt+=mx-a[i];
			i++;
		}
	}
	mx=0;
	mxp=-1;
	for(i=n-1;i>md;){
		while(a[i]>=mx && i>=md){
			mx=a[i];
			i--;
		}
		mxp=i;
		while(a[i]<mx && i>=md){
			cnt+=mx-a[i];
			i--;
		}
	}
	return cnt;
}
int n,m;
LL lmt;
long long tmp;
void dfs(LL *a){		
	tmp=cal(a,n);
	if(ans<tmp)ans=tmp;
	if(m==0){
		return ;
	}
	int i;
	for(i=0;i<n;i++){
		if(a[i]>=lmt)continue;
		m--;
		a[i]++;
		dfs(a);
		a[i]--;
		m++;
	}
}
int main(){
	int i,j;
    freopen("forcedata.in", "r", stdin);
    freopen("forcedata.out", "w", stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		lmt=0;
		for(i=0;i<n;i++){
			scanf("%I64d",h+i);
			if(lmt<h[i])
				lmt=h[i];
		}
		for(;i<2*n;i++)
			h[i]=h[i-n];
		ans=0;
		for(i=0;i<n;i++){
			dfs(h+i);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
