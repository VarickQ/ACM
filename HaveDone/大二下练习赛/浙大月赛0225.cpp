//1003 C
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
const int N   = 15005;

int c[N],c2[N],n;
int main(){
	int a,b,d;
	while(scanf("%d", &n) == 1){
		memset( c, 0, sizeof( c ) );
		memset( c2, 0, sizeof( c2 ) );
		while( 1 ){
			scanf("%d%d%d",&a,&b,&d);
			if( a == -1 ) break;
			c[a] += d;
			if(a>0)c2[a-1] += -d;
			c[b+1] += -d;
			c2[b] += d;
		}
		int Max=0,temp=0,pos;
		for(int i=0 ; i <= n ; ++i){
			if( c[i] != 0 ){
				temp += c[i];
				if( temp > Max ){
					Max = temp; pos = i;
				}
			}
		}
		printf("%d ", pos);
		Max = temp = pos = 0;
		for(int i=n ; i >= 0 ; --i){
			if( c2[i] != 0 ){
				temp += c2[i];
				if( temp > Max ){
					Max = temp; pos = i;
				}
			}
		}
		printf("%d\n", pos);
	}
	return 0;
}
//1004 D
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
const int N = 30005;

struct line{
	int y1,y2,id;
}a[N];
int c[N],n;
bool cmp1(line a, line b){
	return a.y2 < b.y2;
}
bool cmp2(line a, line b){
	return a.y1 < b.y1;
}
int Lowbit(int t){
    return t & ( -t );
}
void Plus(int pos,int num){
	while(pos <= n){
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int end){
	int sum = 0;
	while(end > 0){
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}
int main(){
	int x1,x2;
	while( scanf("%d%d", &x1, &x2 ) != EOF ){
		memset( c, 0, sizeof( c ) );
		scanf("%d", &n);
		for(int i=1 ; i <= n ; ++i){
			int k,b;
			scanf("%d%d", &k, &b);
			a[i].y1 = k*x1+b;
			a[i].y2 = k*x2+b;
		}
		sort( a+1, a+n+1, cmp1 );
		for(int i=1 ; i <= n ; ++i)
			a[i].id = i;
		sort( a+1, a+n+1, cmp2 );
		int ans = 1;
		for(int i=1 ; i <= n ; ++i){
			Plus( a[i].id, 1 );
			ans += Sum(n)-Sum(a[i].id)+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
//H ฒน
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
const int N = 1005;

struct Matrix{
	int x1,y1,x2,y2,val;
}mat[N];
bool check( Matrix a, Matrix b ){
	if((a.x1<=b.x2&&a.x1>=b.x1||a.x2<=b.x2&&a.x2>=b.x1)
		&&(a.y1<=b.y2&&a.y1>=b.y1||a.y2<=b.y2&&a.y2>=b.y1))
		return true;
	if(a.x1<=b.x2&&a.x1>=b.x1 && a.x2<=b.x2&&a.x2>=b.x1
		&& a.y1<=b.y1&&a.y2>=b.y2)
		return true;
	if(a.y1<=b.y2&&a.y1>=b.y1 && a.y2<=b.y2&&a.y2>=b.y1
		&& a.x1>=b.x1&&a.x2<=b.x2)
		return true;
	if(a.x1>=b.x1&&a.x2<=b.x2&&a.y1>=b.y1&&a.y2<=b.y2)
		return true;
	return false;
}
int main(){
	int n,m,c,x,y,a,b,h;
	while( scanf("%d%d%d", &n, &m, &c) != EOF ){
		memset( mat, 0, sizeof( mat ) );
		int Max=0;
		for(int i=0 ; i < c ; ++i){
			scanf("%d%d%d%d%d",&a,&b,&h,&x,&y);
			mat[i].x1 = x; mat[i].x2 = x+a-1;
			mat[i].y1 = y; mat[i].y2 = y+b-1;
			mat[i].val = h;
			for(int j=0 ; j < i ; ++j)
				if(check(mat[j],mat[i])||check(mat[i],mat[j]))
					if( mat[j].val+h > mat[i].val )
						mat[i].val = mat[j].val+h;
			if(mat[i].val > Max)
				Max = mat[i].val;
		}
		printf("%d\n", Max);
	}
	return 0;
}
//F ฒน
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
const int N = 1005;

long long gcd( long long a,long long b ){
	if( b == 0 ) return a;
	else return gcd( b, a%b );
}
int main(){
	long long m,n;
	while( scanf("%lld%lld", &m, &n) == 2 ){
		long long g = gcd( m, n );
		n /= g;
		m /= g;
		double len = sqrt(1.0*n*n+m*m)*g;
		if( n%2==0 || m%2==0 )
			printf("%.3lf\n", len/2.0);
		else
			printf("%.3lf\n", len*(1.0/2+1.0/(2*n*m)));
	}
	return 0;
}