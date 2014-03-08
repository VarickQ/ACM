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
#define N 50010
#define M 10010
#define inf 2000000000
char str[N];
int sum[N],n;
int low(int x)
{
	return x&(-x);
}
void lowbit(int x,int c)
{
	while(x<=n)
	{
		sum[x]+=c;
		x+=low(x);
	}
}
int give(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=sum[x];
		x-=low(x);
	}
	return ans;
}
int main(){
	char d[2];
	int T,m,a,b,c,cs=0;
	scanf("%d",&T);
	while(T--){
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&m);
		scanf("%s",str+1);
		for(int i=3;i<=n;++i)
			if(str[i]=='w'){
				if(str[i-1]=='b'&&str[i-2]=='w') lowbit(i,1);
			}
		printf("Case %d:\n",++cs);
		while(m--){
			scanf("%d",&a);
			if(a){
				int t=0;
				scanf("%d%s",&b,d);
				b++;
				for(int i=b;i<=n&&i<=b+2;++i)
					if(str[i]=='w')
						if(i>=3&&str[i-1]=='b'&&str[i-2]=='w') lowbit(i,-1);
				str[b]=d[0];
				for(int i=b;i<=n&&i<=b+2;++i)
					if(str[i]=='w')
						if(i>=3&&str[i-1]=='b'&&str[i-2]=='w') lowbit(i,1);
			}
			else {
				scanf("%d%d",&b,&c);
				b++;c++;
				b+=2;
				if(b>c) printf("0\n");
				else printf("%d\n",give(c)-give(b-1));
			}
		}
	}
	return 0;
}