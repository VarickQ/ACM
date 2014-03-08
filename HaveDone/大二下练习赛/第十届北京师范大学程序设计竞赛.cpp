//B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 105555;
const int N = 600;

int ans[N];
bool check(int n){
	int t=0,num[10]={0};
	while(n){
		num[t++] = n%10;
		n /= 10;
	}
	for(int i=t-1 ; i >= 0 ; --i)
		num[i] = num[i+1]*10+num[i];
	for(int i=t-1,j=1 ; i >= 0 ; --i,++j)
		if( num[i]%j != 0 )
			return false;
	return true;
}
int main(){
	int k=1;
	ans[1] = 0;
	for(int i=0 ; k <= 580 ; ++i)
		if( check(i) ) ans[k++] = i;
	while( scanf("%d", &k) && k ){
		printf("%d\n", ans[k]);
	}
	return 0;
}

//A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
const int E = 30100;
const int N = 1005;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))

bool vis[N],mat[N][N];
int n,du[N],cnt;
void dfs(int u){
	for(int i=1 ; i <= n ; ++i)
		if( mat[u][i] && !vis[i] ){
			vis[i] = true;
			if( du[i]==1 ) cnt++;
			else dfs(i);
		}
}
int main(){
	int a,b;
	while( scanf("%d", &n) != EOF ){
		CLR( mat, false );
		CLR( vis, false );
		CLR( du, 0 );
		for(int i=0 ; i < n-1 ; ++i){
			scanf("%d%d", &a, &b);
			du[a]++; du[b]++;
			mat[a][b] = mat[b][a] = true;
		}
		int ans = 0;
		cnt = 1;
		for(int i=1 ; i <= n ; ++i){
			if( du[i] == 1 ){
				vis[i] = true;
				dfs(i);
			}
		}
		printf("%d\n", (cnt+1)/2);
	}
	return 0;
}

//I
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 10005;

int main(){
	double a,b,c,d1,d2;
	while( scanf("%lf%lf%lf",&a,&b,&c) != EOF ){
		if(a<=0||b<=0||c<=0||(b*b-a*c)<=0)
			printf("-1\n");
		else {
			d2 = (a*c*c+a*b*c)/(b*b-a*c);
			d1 = (d2*a+a*c)/b;
			printf("%.7lf\n", d1+d2);
		}
	}
	return 0;
}