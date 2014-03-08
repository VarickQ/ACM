#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 50010;

int n,m;
int c[N];
char str[N];
int lowbit(int t){
	return t&(-t);
}
void update(int i,int num){
	while(i <= n){
		c[i] += num;
		i += lowbit(i);
	}
}
int Getsum(int i){
	int sum = 0;
	while(i > 0){
		sum += c[i];
		i -= lowbit(i);
	}
	return sum;
}
int main(){
	int T,t,l,r,cs=0;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		scanf("%s",str+1);
		for(int i=3 ; i <= n ; ++i)
			if(str[i-2]=='w'&&str[i-1]=='b'&&str[i]=='w')
				update(i,1);
		printf("Case %d:\n",++cs);
		while(m--){
			scanf("%d",&t);
			if(t){
				char ch[2];
				scanf("%d%s",&l,ch);
				l++;
				for(int i=l ; i<=n && i<=l+2 ; ++i)
					if(i>=3&&str[i-2]=='w'&&str[i-1]=='b'&&str[i]=='w')
						update(i,-1);
				str[l] = ch[0];
				for(int i=l ; i<=n && i<=l+2 ; ++i)
					if(i>=3&&str[i-2]=='w'&&str[i-1]=='b'&&str[i]=='w')
						update(i,1);
			} else {
				scanf("%d%d",&l,&r);
				++l;++r;
				if(l+2 > r)printf("0\n");
				else printf("%d\n",Getsum(r)-Getsum(l+1));
			}
		}
	}
	return 0;
}