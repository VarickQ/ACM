#include <iostream>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define inf 10000000
#define N 1010
const double G = 20.0;

struct A{
    double x,v,h;
}a[N],b[N];

int main()
{
    int T,n,m,i,j,cs=0;
    double ans,temp,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%lf",&n,&m,&w);
        ans = 0;
        for(i=1 ; i <= n ; ++i){
            scanf("%lf%lf",&b[i].x,&b[i].h);
			temp = b[i].h-b[1].h;
			if(ans < sqrt(2.0*G*temp))
				ans = sqrt(2.0*G*temp);
        }
        
        for(i=1 ; i <= m ; ++i){
            scanf("%lf%lf%lf",&a[i].x,&a[i].v,&w);
			a[i].x += b[1].x;
            for(j=1 ; j < n ; ++j){
				if(a[i].x>=b[j].x && a[i].x<=b[j+1].x){
					a[i].h = (b[j+1].h-b[j].h)*(a[i].x-b[j].x)/(b[j+1].x-b[j].x)+b[j].h;
					break;
				}
            }
			temp = sqrt(a[i].v*a[i].v+2.0*G*(a[i].h-b[1].h));
			if(ans < temp) ans = temp;
        }
        printf("Case %d: %.2lf\n",++cs,ans);
    }
    return 0;
}