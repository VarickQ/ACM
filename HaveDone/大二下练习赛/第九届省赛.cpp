/*
The 9th Zhejiang Provincial Collegiate Programming Contest
2012 04 14
5 AC
*/

//3600
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
//typedef long long ll;

int main(){
	int T,d,t;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &d, &t);
		double old = 0;
		if( d > 3 ){
			if( d > 10 )
				old += 7*2.0+(d-10)*3.0;
			else
				old += (d-3)*2.0;
		}
		old += 2*t/5.0;

		double ans = 0;
		if( d > 3 ){
			if( d > 10 )
				ans += 7*2.5+(d-10)*3.75;
			else
				ans += (d-3)*2.5;
		}
		ans += 2.5*t/4.0;

		printf("%d\n", (int)floor(ans+0.5)-(int)floor(old+0.5));
	}
	return 0;
}
//3603
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 105;
//typedef long long ll;

int main(){
	int T,n,cnt[30][30];
	char str[20];
	scanf("%d", &T);
	while( T-- ){
		CLR( cnt, 0 );
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str);
			for(int j=0 ; str[j] ; ++j)
				cnt[i][str[j]-'A']++;
		}

		for(int i=0 ; i < 26 ; ++i){
			int Min = 1000;
			for(int j=0 ; j < n ; ++j)
				if( cnt[j][i] < Min )
					Min = cnt[j][i];
			for(int j=0 ; j < Min ; ++j)
				printf("%c",i+'A');
		}
		printf("\n");
	}
	return 0;
}
//3610
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//typedef long long ll;

int main(){
	int T;
	char b[25],g[25],x[25];
	scanf("%d", &T);
	while( T-- ){
		scanf("%s%s%s",b,g,x);
		printf("%s will survive\n", g);
	}
	return 0;
}
//3609
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//typedef long long ll;

int a,m;
//扩展欧几里得 a*x+b*y=k 得到x,y的解 (((x*k)%M)+M)%M
int exGcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=exGcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-(a/b)*y;
    return d;
}
int main(){
	int T,x,y,d;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &a, &m);
		d = exGcd(a,m,x,y);
		if( d != 1 ){
			printf("Not Exist\n");
			continue;
		}
		int k = (int)ceil((1.0-x)/m);
		printf("%d\n", x+k*m);
	}
	return 0;
}
//3607
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 1000+10;
//typedef long long ll;

struct A{
	int p,t;
}a[N];
int main(){
	int T,n,i,num;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &n);
		for( i=0 ; i < n ; ++i )
			scanf("%d", &a[i].p);
		for( i=0 ; i < n ; ++i )
			scanf("%d", &a[i].t);

		int limt = a[0].t;
		int ans_w = a[0].t;
		double ans_val = a[0].p;
		double val = a[0].p;

		i = 1,num = 1;
		while( i<n && a[i].t-a[i-1].t <= limt ){
			val += a[i].p;
			num++;
			i++;
		}
		ans_val = val/num;
		ans_w = limt;

		for( ; i < n ; ){
			int dis = a[i].t - a[i-1].t;
			if( dis > limt )
				limt = dis;
			while( i<n && a[i].t-a[i-1].t <= limt ){
				val += a[i].p;
				num++;
				i++;
			}
			double temp = val/num;
			if( temp > ans_val ){
				ans_val = temp;
				ans_w = limt;
			}
		}

		printf("%d.000000 %.6lf\n", ans_w, ans_val);
	}
	return 0;
}
//3605
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
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 55;
typedef long long ll;

int a[N],b[N];
double c[N][N];//c[i][j] = i个里面取j个的取法
double dp[N][N][N];//dp[i][j][l] 前i次操作看了j次在l位瓶子里面的概率
int main(){
	for(int i=0 ; i <= 50 ; ++i){
		c[i][0] = 1;
		for(int j=1 ; j <= i ; ++j)
			c[i][j] = c[i-1][j-1]+c[i-1][j];
	}
	int T,n,m,k,s;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d%d",&n,&m,&k,&s);
		for(int i=1 ; i <= m ; ++i)
			scanf("%d%d", &a[i], &b[i]);
		CLR( dp, 0 );
		dp[0][0][s] = 1;
		for(int i=0 ; i < m ; ++i)
			for(int j=0 ; j <= i ; ++j)
				for(int l=1 ; l <= n ; ++l){
					dp[i+1][j][l]+=dp[i][j][l]*c[m-i-1][k-j]/c[m-i][k-j];
					int t;
					if(a[i+1]==l) t = b[i+1];
					else if(b[i+1]==l) t = a[i+1];
					else t = l;
					dp[i+1][j+1][t]+=dp[i][j][l]*c[m-i-1][k-j-1]/c[m-i][k-j];
				}
		int ans = 1;
		for(int i=2 ; i <= n ; ++i)
			if( dp[m][k][i] > dp[m][k][ans] )
				ans = i;
		printf("%d\n", ans);
	}
	return 0;
}