#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 100010;

long long a[N];
int main()
{
	int n,i;
	a[1] = 0;
	a[2] = 1;
	a[3] = 2;
	for(i=4 ; i <= 100000 ; ++i)
		a[i] = a[i-1]+i/2;
	while(scanf("%d",&n) != EOF)
	{
		printf("%lld\n",a[n]);
	}
	return 0;
}
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<csetjmp>
#include<bitset>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
#define PI 3.1415926535897932384626433832795028
#define N 10010
#define M 10010
#define inf 2000000000

struct B{
	char str[55];
	int id;
}w[N];
bool cmp(const B &x,const B &y){
	if(strcmp(x.str,y.str)==0) return x.id<y.id;
	return strcmp(x.str,y.str)<0;
}
int n;

int mark[55],p[55];
int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		getchar();
		int ans=0;
		while(n--){
			for(int i=1;i<=m;++i){
				gets(w[i].str);
				w[i].id=i;
			}
			sort(w+1,w+m+1,cmp);

			int l,r,len = 1;
			p[1] = w[1].id;
			for(int i=2 ; i <= m ; i++)
			{
				if(w[i].id >= p[len])
					p[++len] = w[i].id;
				else {
					l = 1,r = len;
					while(l <= r){
						int mid = (l+r)/2;
						if(w[i].id >= p[mid]) l = mid+1;
						else r = mid-1;
					}
					p[l] = w[i].id;
				}
			}
			ans += m-len;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define N 510
#define M 10010
#define inf 2000000000

int v[N][N];
int n,m;
int id[N],num[N],mark[N];
struct B{
	int x1,x2,y1,y2;
}w[M];
bool cmp(const B &a,const B &b){
	if(a.x1!=b.x1) return a.x1<b.x1;
	return a.y1<b.y1;
}
int main(){
	int q,a,b,c,d,k,nn;
	while(scanf("%d%d",&n,&m)!=EOF){
		nn = (int)ceil((double)min(n,m)/2);
		for(int i=0 ; i < nn ; ++i)
			scanf("%d",&id[i]);
		for(int i=0 ; i < n ; ++i)
			for(int j=0 ; j < m ; ++j)
				v[i][j] = id[min(min(i,n-1-i),min(j,m-1-j))];
		/*for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				printf("%d ",v[i][j]);
			printf("\n");
		}*/
		scanf("%d",&q);
		while(q--){
			memset(mark,0,sizeof(mark));
			memset(num,0,sizeof(num));
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(a>c) swap(a,c);
			if(b>d) swap(b,d);
			for(int i=a ; i <= c ; ++i)
				for(int j=b ; j <= d ; ++j)
					num[v[i][j]]++;
			k=0;
			int ans=0;
			for(int i=0 ; i < nn ; ++i){
				if(!mark[id[i]]) mark[id[i]]=1;
				else continue;
				if(num[id[i]] > num[id[k]]) k=i;
				else if(num[id[i]]==num[id[k]] && id[i]<id[k]) k=i;
				if(num[id[i]])
					ans++;
			}
			printf("%d %d %d\n",ans,id[k],num[id[k]]);
		}
	}
	return 0;
}