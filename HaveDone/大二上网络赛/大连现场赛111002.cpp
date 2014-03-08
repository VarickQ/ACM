#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 5000;

char str[N];
int main(){
	int t,len,i,j,k,p;
	while(gets(str)){
		len = strlen(str);
		t = len/16;
		if(len%16 == 0)t--;
		for(i=0,k=0,p=0 ; i <= t ; ++i){
			printf("%03x0: ",i);
			for(j=k ; j < 16+k ; j+=2){
				if(str[j])
					printf("%2x",str[j]);
				else printf("  ");
				if(str[j+1])
					printf("%2x ",str[j+1]);
				else printf("   ");
			}
			k = j;
			for(j=p ; j < 16+p && str[j] ; ++j){
				if(str[j]<='Z' && str[j]>='A')
					printf("%c",str[j]-'A'+'a');
				else if(str[j]<='z' && str[j]>='a')
					printf("%c",str[j]-'a'+'A');
				else printf("%c",str[j]);
			}
			p = j;
			printf("\n");
		}
		memset(str,'\0',sizeof(str));
	}
	return 0;
}

//补
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll inf = 2000000000;
const ll M = 1000000007;
const int N = 10005;

int a[12],prime[N],cnt;
bool su[N];
ll re;
ll sPow(int x,int n,ll M){
	ll sum=1;
	while(n){
		if(n&1)sum = (sum%M)*(x%M)%M;
		x = (x%M)*(x%M)%M;
		n >>= 1;
	}
	return sum%M;
}
void PrimeList(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= N-2 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= N-2 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= N-2 ; ++i)
		if(!su[i]) prime[cnt++] = i;
	re = sPow(30,M-2,M);//??求逆元
}

ll gs(ll n)//四次方求和
{
	//return (((n*(n+1))%M)*((((((((6*n)%M)*n)%M)*n)%M+(((9*n)%M)*n)%M+n-1))%M)*re)%M;
	ll a,b,c,d,e,f,g,h,i,j;
	a = (n*(n+1))%M;
	b = 6*n%M;
	b = b*n%M;
	b = b*n%M;
	c = 9*n%M;
	c = c*n%M;
	d = (b+c+n-1)%M;
	e = a*d%M;
    return e*re%M;
}
int main(){
	int T,k;
	PrimeList();
	ll ans,i,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);//n*(n+1)*(6*n*n*n+9*n*n+n-1)/30;
		/*if(n==1){
			printf("0\n");
			continue;
		}
		if(n==2){
			printf("1\n");
			continue;
		}*/
		m = n;
		n--;
		ans = gs(n);
		n++;
		bool f = false;
		k = 0;
		for(i=0 ; i < cnt && prime[i] < n ; ++i)
			if(n%prime[i] == 0){
				f = true;
				a[k++] = prime[i];
				while(m%prime[i]==0)
					m /= prime[i];
			}
		if(m!=1 && f) a[k++] = m;
		if(k==0){
			printf("%lld\n",ans);
			continue;
		}
		for(i=1 ; i < (1<<k) ; ++i){
			int temp = 0,val = 1;
			for(int j=0 ; j < k ; ++j){
				if((1<<j)&i){
					temp++;
					val *= a[j];
				}
			}
			if(temp&1)
				ans = (ans-((((gs(n/val-1)*val)%M*val)%M*val)%M*val)%M)%M;
			else
				ans = (ans+((((gs(n/val-1)*val)%M*val)%M*val)%M*val)%M)%M;
			if(ans < 0) ans=(ans+M)%M;
		}
		printf("%lld\n",ans);
	}
	return 0;
}