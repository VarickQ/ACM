#include<stdio.h>
#include<math.h>
#define EPS 1e-6
#define PI 3.14159265359
double angle,h[10005],th[10005],unitS,unitL,sum,currH,tmp;;
int n,i,j,stack[10005],top,maxi,prev[10005],next[10005],now;
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
int push(int vi){
    while(top && th[stack[top-1]]<th[vi])top--;
    stack[top++] = vi;
    return stack[top-2];
}
int main(){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    while(scanf("%d%lf",&n,&angle)!=EOF){      
        if(angle>=0)for(i=0;i<n;i++)scanf("%lf",&h[i]);
        else for(i=n-1;i>=0;i--)scanf("%lf",&h[i]);
        angle = fabs(angle);

        t.x =  10000 * cos(angle/180.0*PI);
        t.y = -10000 * sin(angle/180.0*PI); 
        s.x = 0;
        s.y = 0;
        //s.x = -t.x;
        //s.y = -t.y;
        unitL = 0;   
        if(angle>0)unitL = tan(angle/180.0*PI);
        maxi = 0;
        
        //printf("%lf %lf  %lf %lf\n",s.x,s.y,t.x,t.y);
        for(i=0;i<n;i++){
            c.y = h[i];
            c.x = i+1;
            th[i] = dis_p2_seg(c,s,t);
            
            //printf("%lf %lf %lf\n",c.x,c.y,th[i]);
            if(th[maxi]<th[i])maxi = i;
        }
        stack[0] = maxi;
        for(i=maxi+1,top=1;i<n;i++)prev[i] = push(i);            
        for(i=maxi-1,top=1;i>=0;i--)next[i] = push(i);    
        sum = 0;  
        now = 0;    
        //for(i=0;i<n;i++)printf("%lf %lf\n",h[i],th[i]);    
        while(now!=maxi){
            currH = h[now];         
            for(i=now+1;i<=next[now];i++){
                currH-= unitL;     
                if(currH>=h[i]-EPS){
                    sum+=currH-h[i]+unitL*0.5;  
                }else if(currH+unitL>h[i]-EPS){
                    tmp=currH+unitL-h[i];
                    if(unitL>EPS)sum+=tmp*tmp*0.5/unitL;
                }   
            }            
            now = next[now];
        }
        now = n-1;
        while(now!=maxi){
            currH = h[now];
            for(i=now;i>prev[now];i--){
                //printf("%lf:%lf\n",h[i],currH);
                sum+=currH-h[i]+unitL*0.5;                  
                currH+= unitL;
            }
            now = prev[now];
            //break;
        }              
        printf("%.2lf\n",sum);
    }
}
