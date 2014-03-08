#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 2000;

char str[55];
int Is(char a[]){
	if(a[0]=='\\'||a[0]=='/') return 3;//unix path
	int i;
	for(i=0 ; a[i] ; ++i)
		if(a[i]==':') break;
	i++;
	if(a[i]=='\\'&&a[i+1]=='/'||a[i]=='/'&&a[i+1]=='\\'||a[i]=='/'&&a[i+1]=='/'||a[i]=='\\'&&a[i+1]=='\\')
		return 1;//url
	return 2;//windows path
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		if(Is(str) == 1){
			printf("It's a URL!\n");
			for(int i=0 ; str[i] ; ++i){
				if(str[i]=='\\')printf("/");
				else printf("%c",str[i]);
			}
		}
		else if(Is(str) == 2){
			printf("It's a path in Windows system!\n");
			for(int i=0 ; str[i] ; ++i){
				if(str[i]=='/')printf("\\");
				else printf("%c",str[i]);
			}
		}
		else if(Is(str) == 3){
			printf("It's a path in Unix-like systems!\n");
			for(int i=0 ; str[i] ; ++i){
				if(str[i]=='\\')printf("/");
				else printf("%c",str[i]);
			}
		}
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
const int inf = 2000000000;
const int N = 1000000;

char str[120];
__int64 a[N];
int main(){
	int T,l;
	__int64 n,m,temp;
	scanf("%d",&T);
	while(T--){
		scanf("%s%I64d",str,&m);
		int len = strlen(str);
		l = 0;
		temp = m;
		while(temp){
			temp /= 10;
			l++;
		}
		if(l >= len){
			sscanf(str,"%I64d",&n);
			if(n >= m) n = m-1;
		} else n = m-1;
		__int64 ans = 0;
		a[0] = 1;
		for(__int64 i=1 ; i <= n ; ++i){
			a[i] = (a[i-1]*i)%m;
			ans = (ans+a[i])%m;
		}
		printf("%I64d\n",(ans+1)%m);
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
const int inf = 2000000000;
const int N = 310;

struct A{
	int u,v;
}e[N];
int n,m;
int heade[N],k;
int c[17],ans;
void add(int u,int v){
	e[k].u = u;
	e[k].v = v;
	k++;
}
void dfs(int star,int s){
	c[star] = s;
	if(star == n){//全部染色
		int cnt = 0;
		for(int i=0 ; i < k ; ++i)
			if(c[e[i].u] == c[e[i].v])
				cnt++;
		if(ans > cnt) ans = cnt;
	}
	else if(star < n){
		if(c[star+1]==0 || c[star+1]==2)
			dfs(star+1,1);//染色1
		if(c[star+1]==0 || c[star+1]==1)
			dfs(star+1,2);//染色2
	}
}
int main(){
	int T,u,v;
	scanf("%d",&T);
	while(T--){
		memset(heade,-1,sizeof(heade));
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		ans = inf;
		k = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d",&u,&v);
			u++; v++;
			add(u,v);
		}
		if(n == 0){
			printf("0\n");
		} else {
			dfs(1,1);
			dfs(1,2);
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
6
3 3
0 1
1 2
2 0

4 5
0 1
1 2
2 0
0 3
1 3

5 6
0 1
1 2
2 0
0 3
1 3
3 4
*/
//补
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 12;

int x[N],y[N],c[N],dp[1001][1001];
int main(){
	int T,n,X,Y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&X,&Y);
		for(int i=0 ; i < n ; ++i)
			scanf("%d%d%d",&x[i],&y[i],&c[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1 ; i <= X ; ++i)
			for(int j=1 ; j <= Y ; ++j)
				for(int k=0 ; k < n ; ++k){
					if(i>=x[k] && j>=y[k]){
						dp[i][j]=max(dp[i][j],dp[i-x[k]][j]+dp[x[k]][j-y[k]]+c[k]);
						dp[i][j]=max(dp[i][j],dp[i][j-y[k]]+dp[i-x[k]][y[k]]+c[k]);
					}
					if(i>=y[k] && j>=x[k]){
						dp[i][j]=max(dp[i][j],dp[i][j-x[k]]+dp[i-y[k]][x[k]]+c[k]);
						dp[i][j]=max(dp[i][j],dp[i-y[k]][j]+dp[y[k]][j-x[k]]+c[k]);
					}
				}
		printf("%d\n",dp[X][Y]);
	}
	return 0;
}