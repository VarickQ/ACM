#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 50010;

struct Edge{
	int v,next;
}e[N*10];
int heade[N],k,work[N];
void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
void fun(int x,int y){
	for(int j=heade[x] ; j!=-1 ; j=e[j].next){
		work[e[j].v] = y;
		fun(e[j].v,y);
	}
}
int main()
{
	int T,n,m,i,cs=1,u,v,x,y;
	scanf("%d",&T);
	while(T--)
	{
		memset(work,-1,sizeof(work));
		memset(heade,-1,sizeof(heade));
		scanf("%d",&n);
		k = 0;
		for(i=0 ; i < n-1 ; ++i){
			scanf("%d%d",&v,&u);
			add(u,v);
		}
		char ch;
		scanf("%d",&m);
		printf("Case #%d:\n",cs++);
		for(i=0 ; i < m ; ++i){
			scanf(" %c",&ch);
			if(ch=='C'){
				scanf("%d",&x);
				printf("%d\n",work[x]);
			}
			else if(ch=='T'){
				scanf("%d%d",&x,&y);
				work[x] = y;
				fun(x,y);
			}
		}
	}
	return 0;
}
//ฒน
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 10010;

struct Node{
	int atk,hp,t;
}a[N];
bool cmp(Node a,Node b){
	return a.t*b.atk < b.t*a.atk;
}
int main()
{
	int T,n,m,i,cs=1;
	__int64 sum,ans;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		sum = 0;
		for(i=0 ; i < n ; ++i){
			scanf("%d%d",&a[i].hp,&a[i].atk);
			a[i].t = (int)ceil(1.0*a[i].hp/m);
			sum += a[i].atk;
		}
		sort(a,a+n,cmp);
		ans = 0;
		for(i=0 ; i < n ; ++i){
			ans += sum*a[i].t;
			sum -= a[i].atk;
		}
		printf("Case #%d: %I64d\n",cs++,ans);
	}
	return 0;
}
//ฒน
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const double eps = 1e-8;
const int N = 1010;
const double g = 10.0;

int main()
{
	int T,cs=1;
	double x1,x2,x3,v1,v2,v3,a,b,c;
	double vx1,vx2,vx3,vy1,vy2,vy3;
	double t1,t2,t3,lim;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&x1,&x2,&x3);
		scanf("%lf%lf%lf",&v1,&v2,&v3);
		scanf("%lf%lf%lf",&a,&b,&c);

		vx1 = v1*cos(a);//Vx = v * cos(alpha)
		vy1 = v1*sin(a);//Vy = v * sin(alpha)
		vx2 = v2*cos(b);
		vy2 = v2*sin(b);
		vx3 = v3*cos(c);
		vy3 = v3*sin(c);

		t1 = vy1*2/g;//y=1/2*g*t;
		t2 = vy2*2/g;
		t3 = vy3*2/g;
		lim = min(t1,t2);
		lim = min(lim,t3);

		printf("Case #%d: ",cs++);
		if(fabs(vy1)<=eps || fabs(vy2)<=eps || fabs(vy3)<=eps) printf("-1\n");
		else if(vy1==vy2 && vy2==vy3) printf("Multiply answer\n");
		else {
			double k31 = vy3-vy1;
			double k21 = vy2-vy1;
			a = (vx2*k31-vx1*k31)-(vx3*k21-vx1*k21);
			b = (x2*k31-x1*k31)-(x3*k21-x1*k21);
			double t = -b/a;
			if(fabs(a)<=eps && fabs(b)<=eps) printf("Multiply answer\n");
			else if(fabs(a)<=eps || t<0 || t>lim) printf("-1\n");
			else printf("%.4lf\n",t);
		}

	}
	return 0;
}
//ฒน
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const double eps = 1e-8;
const double g = 10.0;
const int N = 1010;

int a[100];
__int64 Pow(int a,int n){
	__int64 m=1;
	for(int i=0 ; i < n ; ++i)
		m *= a;
	return m;
}
int main()
{
	int T,cs=1,i,j,k;
	__int64 n,m,p,temp;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%I64d",&n);
		for(i=0 ; i < n ; ++i){
			scanf("%I64d",&m);
			p = m*m;
			j = 0;
			while(m){
				a[j++] += m%2;
				m /= 2;
			}
			k = 32;
			while(p){
				a[k++] += p%2;
				p /= 2;
			}
		}
		for(i=0 ; i < 96 ; ++i)
			a[i] %= 3;
		n = 0;
		for(i=0 ; i < 32 ; ++i)
			n += a[i]*Pow(2,i);
		m = 0;
		for(i=32 ; i < 96 ; ++i)
			m += a[i]*Pow(2,i-32);
		temp = (__int64)(sqrt(double(2*m-n*n))+0.5);//a-b
		printf("%I64d %I64d\n",(n-temp)/2,(n+temp)/2);
	}
	return 0;
}