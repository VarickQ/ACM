//##点集S内面积最大的三角形##
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<complex>
using namespace std;
const double inf=1e-8;
typedef complex<double> Point;
//求两点间的距离
double Distance(Point a,const Point b)
{
    return sqrt((a.real()-b.real())*(a.real()-b.real())+
        (a.imag()-b.imag())*(a.imag()-b.imag()));
}
int dbcmp(double tp)
{
    return tp<-inf?-1:tp>inf;
}
//求矢量叉积
double operator ^(Point a,Point b){return imag(conj(a)*b);}
Point base;
 bool compare2(Point a,Point b)
{
    double rea=a-base^b-base;
     if(dbcmp(rea)>0)return true;
     //如果在同一线上的点距base近的点在前,
     //在while循环中除距base最远的点外都将被踢除
     else if(dbcmp(rea)==0&&
         dbcmp(Distance(a,base)-Distance(b,base))<0)
         return true;
     else return false;
}
bool compare1(Point a, Point b)
{
    return a.imag()<b.imag()||(a.imag()==b.imag()&&a.real()<b.real());
}
//通过矢量叉积求极角关系（ac）(bc)
//k > 0 ,ac在bc顺时针方向上
//求凸包的顶点，不包括边上的点
 int create_convex(int vsize,Point * v,Point *result,Point &base)
 {
    //寻找base点
    base=v[0];
    int index=0;
    for(int i=1;i<vsize;i++)
    {
        if(compare1(v[i],base))
        {  base=v[i];index=i;}
    }
    swap(v[index],v[0]);
    sort(v+1,v+vsize,compare2);
    result[0]=v[0];
    int k=1;
    int pos=0;
    while(k<vsize)
    {
        while(pos>0&&dbcmp(v[k]-result[pos-1]^
            result[pos]-result[pos-1])>=0)pos--;//判断是不是入栈
        result[++pos]=v[k++];
    }
    return pos+1;
}
const int Max=1000010;
Point p[Max],re[Max];
int main()
{
    //freopen("1.txt","r",stdin);
    int m;
    double x,y;
    while(scanf("%d",&m)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%lf%lf",&x,&y);
            p[i]=Point(x,y);
        }
        int resz=create_convex(m,p,re,base);
        //求最远点对的距离
        double ans=0;
        int j,pos;
        re[resz]=re[0];
        for(int i=0;i<resz;i++)
        {
            j=(i+1)%resz;
            pos=(i+2)%resz;
            while(pos!=i&&(re[j]-re[i]^re[pos]-re[i])<(re[j]-re[i]^re[pos+1]-re[i]))
                pos=(pos+1)%resz;
            if(pos==i) continue;
            int pp=(pos+1)%resz;
            while(j!=pp&&pos!=i)
            {
                ans = max(ans,(re[j]-re[i]^re[pos]-re[i]));
                while(pos!=i&&(re[j]-re[i]^re[pos]-re[i])<(re[j]-re[i]^re[pos+1]-re[i]))
                    pos=(pos+1)%resz;
                j=(j+1)%resz;
            }
 
        }
        printf("%.2lf\n",ans/2.0);
    }
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
#define inf 1000000000
int a[1010],sum[1010],dp[1010][110];
int main()
{
	int n,la,lb,i,j,k,l,ans;
	memset(dp,0,sizeof(dp));
	while(scanf("%d",&n)&&n)
	{
		scanf("%d%d%d",&lb,&la,&k);
		for(i=1 ; i <= n ; ++i)
			scanf("%d",&a[i]);
		a[n+1] = 0;
		for(i=0 ; i <= n+1 ; ++i)
			for(j=0 ; j <= k ; ++j)
				dp[i][j] = inf;
		for(i=0 ; i <= k ; ++i)
			dp[0][i] = 0;
		for(i=1 ; i <= n+1 ; ++i)
		{
			for(j=0 ; j <= k/* && j*la <= i*/ ; ++j)
			{
				dp[i][j] = dp[i-1][j] + a[i];
				for(l=la ; l<=lb && i-l>=0 && j>0 ; ++l)
					dp[i][j] = min(dp[i][j],dp[i-l][j-1]);
			}
		}
		ans=inf;
		for(i=0 ; i <= k ; ++i)
			ans = min(ans,dp[n+1][i]);
		printf("%d\n",ans);
	}
	return 0;
}
//##开灯问题##
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
#define inf 1000000000
int a[110][16],temp[110][16];
int mark[16];
int main()
{
	int T,n,i,j,min,t,num,k,f,x,sum,m,M;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1 ; i <= n ; ++i)
			for(j=1 ; j <= m ; ++j)
				scanf("%d",&a[i][j]);
		M = 1<<m;
		min = inf;
		if(n==1)
		{
			memset(mark,0,sizeof(mark));		
			for(i=0;i<M;i++)
			{
				t=i;
				k=1;
				sum=0;
				while(t)
				{
					if(t&1) 
					{
						sum++;
						mark[k]=1;
					}
					t>>=1;
					++k;
				}
				for(j=1 ; j <= m ; ++j)
					if(!(mark[j]^mark[j-1]^mark[j+1]^a[1][j])) break;
				if(j==m+1 && min>sum) min=sum;
			}
			if(min != inf) printf("%d\n",min);
			else printf("no solution\n");
			continue;
		}
		for(i=0 ; i < M ; ++i)
		{
			memset(temp,0,sizeof(temp));
			t=i;
			k=m;
			while(t)
			{
				if(t&1) temp[1][k]=1;
				k--;
				t>>=1;
			}
			for(j=2 ; j <= n ; ++j)
				for(k=1 ; k <= m ; ++k)
					temp[j][k]=!(a[j-1][k]^temp[j-1][k]^temp[j-2][k]^temp[j-1][k-1]^temp[j-1][k+1]);
			for(f=0,j=1 ; j <= m ; ++j)
				if(!(a[n][j]^temp[n][j]^temp[n-1][j]^temp[n][j-1]^temp[n][j+1])) break;
			if(j <= m) continue;
			for(sum=0,j=1 ; j <= n ; ++j)
				for(k=1 ; k <= m ; ++k)
					if(temp[j][k]) sum++;
			if(sum<min) min=sum;
		}
		if(min==inf) printf("no solution\n");
		else printf("%d\n",min);
	}
	return 0;
}
//##求斐波那契数##
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
#define inf 1000000000
__int64 Fibonacci(__int64 n,__int64 &next)
{
    __int64 a=0,b=1,c=1;
    for(__int64 i=1; i<n; ++i)
        c=a+b,a=b,b=c;
    next = a+b;
    return c;
}
__int64 MyFibonacci(__int64 n, __int64 k)
{
    __int64 a=n,count=0;
    __int64 data[6400],Fib[6400];
	if(a<=16)
	{
		__int64 c=1,b=1;
		if(a==0) return 0;
		if(a==2||a==1) return 1%k;
		for(__int64 i=3;i<=n;i++)
		{
			a=(c+b)%k;
			c=b;
			b=a;
		}
		return a;
	}
    while(a>16)
    {
        a>>=1;
        data[count++] = a+1;
        data[count++] = a;
    }
    Fib[count-1] = Fibonacci(data[count-1],Fib[count-2]);
    for(count-=4;count>=0;count-=2)
    {
        if(data[count+1]&1)
        {
            Fib[count+1] = (Fib[count+2]*Fib[count+2] + Fib[count+3]*Fib[count+3])%k;
            Fib[count] = ((2*Fib[count+3] + Fib[count+2])*Fib[count+2])%k;
        }
        else
        {
            Fib[count+1] = ((2*Fib[count+2] - Fib[count+3]+2*k)%k*Fib[count+3])%k;
            Fib[count] = (Fib[count+2]*Fib[count+2] + Fib[count+3]*Fib[count+3])%k;
        }
    }
    if(n&1) return (Fib[0]*Fib[0] + Fib[1]*Fib[1])%k;
    else return ((2*Fib[0] - Fib[1]+2*k)*Fib[1])%k;
}
const __int64 M=1000000007;
int main()
{
	__int64 T,i;
	__int64 a,b;
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&a,&b);
		a--;
		__int64 c=MyFibonacci(b*2+1,M),d=MyFibonacci(b*2,M),
			e=MyFibonacci(a*2+1,M),f=MyFibonacci(a*2,M);

		printf("%I64d\n",((c*d)%M-(e*f)%M+M)%M);
	}
	return 0;
}
//##最小覆盖圆##
#include<stdio.h>
#include<math.h>
struct TPoint
{
	double x,y;   
}; 
TPoint a[1005],d; 
double r;

double distance(TPoint p1,TPoint p2)   
{
	return(sqrt((p1.x-p2.x)*(p1.x -p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));       
}
double multiply(TPoint p1,TPoint p2,TPoint p0)
{
	return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));           
}   
void MiniDiscWith2Point(TPoint   p,TPoint   q,int   n)
{
	d.x = (p.x+q.x)/2.0;
	d.y = (p.y+q.y)/2.0;
	r = distance(p,q)/2;
	int k;
	double c1,c2,t1,t2,t3;
	for(k=1;k<=n;k++)
	{
		if(distance(d,a[k])<=r) continue;
		if(multiply(p,q,a[k]) != 0.0)
		{
			c1 = (p.x*p.x+p.y*p.y-q.x*q.x-q.y*q.y)/2.0;
			c2 = (p.x*p.x+p.y*p.y-a[k].x*a[k].x-a[k].y*a[k].y)/2.0;

			d.x = (c1*(p.y-a[k].y)-c2*(p.y-q.y))/((p.x-q.x)*(p.y-a[k].y)-(p.x-a[k].x)*(p.y-q.y));
			d.y = (c1*(p.x-a[k].x)-c2*(p.x-q.x))/((p.y-q.y)*(p.x-a[k].x)-(p.y-a[k].y)*(p.x-q.x));
			r = distance(d,a[k]);
		}
		else
		{
			t1=distance(p,q);
			t2=distance(q,a[k]);
			t3=distance(p,a[k]);
			if(t1>=t2&&t1>=t3)
			{d.x=(p.x+q.x)/2.0;d.y=(p.y+q.y)/2.0;r=distance(p,q)/2.0;}
			else if(t2>=t1&&t2>=t3)
			{d.x=(a[k].x+q.x)/2.0;d.y=(a[k].y+q.y)/2.0;r=distance(a[k],q)/2.0;}
			else 
			{d.x=(a[k].x+p.x)/2.0;d.y=(a[k].y+p.y)/2.0;r=distance(a[k],p)/2.0;}
		}
	}

}
void MiniDiscWithPoint(TPoint   pi,int   n)
{
	d.x = (pi.x+a[1].x)/2.0;
	d.y = (pi.y+a[1].y)/2.0;
	r = distance(pi,a[1])/2.0;
	int j;
	for(j=2 ; j <= n ; ++j)
	{
		if(distance(d,a[j])<=r) continue;
		else
		{
			MiniDiscWith2Point(pi,a[j],j-1);
		}
	}
}

int main()
{
	int i,n,xxx,yyy;
	while(scanf("%d%d%d",&xxx,&yyy,&n) != EOF)
	{
		for(i=1;i<=n;i++)
		{
		   scanf("%lf %lf",&a[i].x,&a[i].y);
		}
		if(n==1)
		{
			printf("(%.1lf,%.1lf).\n0.0\n",a[1].x,a[1].y); continue;
		}
		r = distance(a[1],a[2])/2.0;
		d.x = (a[1].x+a[2].x)/2.0;
		d.y = (a[1].y+a[2].y)/2.0;
		for(i=3;i<=n;i++)
		{
			if(distance(d,a[i])<=r) continue;
			else
				MiniDiscWithPoint(a[i],i-1);
		}
		printf("(%.1lf,%.1lf).\n%.1lf\n",d.x,d.y,r);
	}
	return 0;
}