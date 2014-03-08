#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll __int64
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1010;

int l[N],w[N],a[N];
bool mark[N];
int main() {
	int n,k,p,tot;
	char ch;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		memset(mark,0,sizeof(mark));
		memset(l,0,sizeof(l));
		memset(w,0,sizeof(w));
		tot = 0;
		for(int i=0 ; i < k ; ++i){
			scanf("%d",&p);
			for(int j=0 ; j < 2*p ; ++j)
				scanf("%d",&a[j]);
			scanf(" %c",&ch);
			if(ch == '='){
				for(int j=0 ; j < 2*p ; ++j)
					mark[a[j]] = true;
			}
			else if(ch == '<'){
				tot++;
				for(int j=0 ; j < p ; ++j)
					l[a[j]]++;
				for(int j=p ; j < 2*p ; ++j)
					w[a[j]]++;
			}
			else if(ch == '>'){
				tot++;
				for(int j=0 ; j < p ; ++j)
					w[a[j]]++;
				for(int j=p ; j < 2*p ; ++j)
					l[a[j]]++;
			}
		}
		int cnt=0,ans=0;
		for(int i=1 ; i <= n ; ++i)
			if((l[i]==tot||w[i]==tot) && !mark[i]){
				cnt++;
				ans = i;
				if(cnt > 1){
					ans = 0; break;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}