#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const ll inf = (1LL<<63-1);
const ll M = 1000000007;
const int N = 3030000;

ll f1(ll n){
	return n*(n+1)*(n+2);
}
ll f2(ll n){
	return n*(n+1);
}
int main(){
	int T;
	ll s,i,n,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&s);
		n = (__int64)pow(6.0*s,1.0/3.0);
		while(f1(n) < 6*s)//n*(n+1)*(n+2)/6
			n++;
		
		s -= f1(n-1)/6;
		printf("%I64d ",n);

		n = (__int64)pow(2.0*s,1.0/2.0);
		while(f2(n) < 2*s)
			n++;
		s -= f2(n-1)/2;
		printf("%I64d %I64d\n",n,s);
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
#define ll __int64
const ll inf = (1LL<<63-1);
const ll M = 1000000007;
const int N = 1005;

int a[N];
bool cmp(const int &a,const int &b){
	return a > b;
}
int main(){
	int T,n,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0 ; i < n ; ++i)
			scanf("%d",&a[i]);
		t = n;
		while(t){
			sort(a,a+n,cmp);
			for(int i=1 ; i < n ; ++i){
				if(a[i] > 0 && a[0] > 0){
					a[0]--; a[i]--;
				}
				else break;
			}
			if(a[0]!=0) break;
			t--;
		}
		if(t==0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

//ฒน
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64

int a[12],b[12];
int main(){
	int i,len;
	ll n,ans;
	a[1] = 3;
	for(i=2 ; i <= 10 ; ++i)
		a[i] = a[i-1]*4;
	while(scanf("%I64d",&n)!= EOF){
		if(n < 10){
			if(n <= 3) printf("%I64d\n",n);
			else printf("3\n");
			continue;
		}
		len = 0;
		while(n > 9){
			b[len++] = n%10;
			n /= 10;
		}
		b[len] = n;
		ans = a[len];
		for(i=len ; i >= 0 ; --i){
			if(i == len){
				if(b[i] <= 3) ans += (n-1)*a[i];
				else{
					ans += 3*a[i];
					break;
				}
			}
			else if(i != 0){
				if(b[i] <= 3) ans += b[i]*a[i];
				else{
					ans += 4*a[i];
					break;
				}
			}
			else if(i == 0){
				if(b[i] <= 3) ans += b[i];
				else ans += 3;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}