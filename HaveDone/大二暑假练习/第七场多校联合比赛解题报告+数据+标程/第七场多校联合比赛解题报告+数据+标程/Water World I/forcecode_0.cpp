#include<stdio.h>
#include<math.h>
#include<memory.h>
#define EPS 1e-6
#define PI acos(-1)
int n,i,j,k,maxi,iszero;
double angle,h[10005],th[10005],unitL,currH,tmph,sum;
struct TPoint{
    double x,y;
}s,t,c;
double cross(const TPoint &a,const TPoint &b,const TPoint &c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
double dis_p2_seg(TPoint &c,TPoint &a,TPoint &b){
    double x,y,z;
    x = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
    y = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
    z = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    //if(x+z-y<0 || y+z-x<0)return sqrt(x<y?x:y);
    return fabs(cross(c,a,b)/sqrt(z));
}
int main(){
    freopen("data.in", "r", stdin);
    freopen("forcedata_0.out", "w", stdout);
    while(scanf("%d%lf",&n,&angle)!=EOF){
        s.x = 0;
        s.y=0;
        if(angle>=0)for(i=0;i<n;i++)scanf("%lf",&h[i]);
        else for(i=n-1;i>=0;i--)scanf("%lf",&h[i]);
        angle = fabs(angle);        
        if(angle ==0){//
            unitL=0;
            iszero = 1;
        }else{
            unitL = tan(angle/180.0*PI);
            iszero = 0;
        }        
        t.x = 10000*cos(angle/180.0*PI);
        t.y = -10000*sin(angle/180.0*PI);
        maxi = 0;
        for(i=0;i<n;i++){
            c.x = i+1;
            c.y=h[i];
            th[i] = dis_p2_seg(c,s,t);
            if(th[i]>=th[maxi])maxi = i;//
        }        
        i = 0;
        sum = 0;
        while(i<maxi){
            for(j=i+1;j<=maxi;j++)
                if(th[j]>=th[i]){//
                    currH = h[i];
                    for(k=i+1;k<=j;k++){
                        currH -= unitL;
                        if(currH>=h[k]){//
                            sum+=currH-h[k]+unitL*0.5;
                        }else if(currH+unitL>=h[k]){//
                            tmph = currH+unitL-h[k];
                            if(!iszero)sum+=tmph*tmph/unitL*0.5;
                        }
                    }
                    i = j;
                    break;
                }
        }
        i = n-1;
        while(i>maxi){
            for(j=i-1;j>=maxi;j--)
                if(th[j]>=th[i]){//
                    currH = h[i];
                    for(k=i;k>j;k--){
                        sum+=currH-h[k]+unitL*0.5;                        
                        currH += unitL;                  
                    }
                    i = j;
                    break;
                }
        }
        printf("%.2lf\n",sum);          
    }
} 
