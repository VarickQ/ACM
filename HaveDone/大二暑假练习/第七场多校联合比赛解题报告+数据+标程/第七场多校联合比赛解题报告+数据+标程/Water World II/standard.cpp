#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<time.h>
#define LL long long
using namespace std;
int stack[30005];
int top,maxi,i,j,now,k,prev,tprev;
int h[30005],n;
LL sum[30005],addh,f[30005][10],result;
LL min(LL a,LL b){return a<b?a:b;}
LL max(LL a,LL b){return a>b?a:b;}
int push(int vi){
    while(top && h[stack[top-1]]<h[vi])top--;
    stack[top++] = vi;
    return stack[top-2];
}
int ef(int vi,int addh){
    int l = 0,r = top-1,m,res = 0;
    if(h[maxi]<=h[vi]+addh)return maxi;
    while(l<r){
        m = (l+r)>>1;
        if(h[stack[m]]<=h[vi]+addh){
            r = m-1;
        }else{
            l = m+1;
            res=m;
        }
    }
    return stack[res];
}
int main(){    
    int tt = clock();
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    while(scanf("%d%d",&n,&addh)!=EOF){  
        memset(f,0,sizeof(f));   
                 
        for(i=0,maxi=n;i<n;i++){
            scanf("%d",&h[i]);
            h[i+n] = h[i+n+n] = h[i];
            if(h[maxi]<h[i+n])maxi = i+n;
        }
        //printf("%d*\n",h[0]);
        for(i=1,sum[0] = h[0];i<n*3;i++)sum[i] = sum[i-1] + h[i];        
        stack[0] = maxi;
        top = 1;
       
        for(now=maxi+1;now<maxi+n;now++){
            prev = push(now);
            f[now][0] = f[prev][0] + (LL)h[now] * (now-prev-1)-(sum[now-1]-sum[prev]);
            for(j=0;j<=addh;j++)
                for(k=0;k<=j;k++){
                    f[now][j] = f[prev][j] + (LL)h[now] * (now-prev-1)-(sum[now-1]-sum[prev]);           
                    tprev = ef(now,k);
                    f[now][j] = max(f[tprev][j-k] + min((LL)(h[now]+k),(LL)h[tprev]) * (now-tprev-1)-(sum[now-1]-sum[tprev]),f[now][j]);
                }
        }
        top = 1;

        for(now=maxi-1;now>maxi-n;now--){
            prev = push(now);
            f[now][0] = f[prev][0] + (LL)h[now] * (prev-now-1)-(sum[prev-1]-sum[now]);  
            for(j=1;j<=addh;j++)
                for(k=0;k<=j;k++){                  
                    f[now][j] = f[prev][j] + (LL)h[now] * (prev-now-1)-(sum[prev-1]-sum[now]);           
                    tprev = ef(now,k);
                    f[now][j] = max(f[tprev][j-k] + min((LL)(h[now]+k),(LL)h[tprev]) * (tprev-now-1)-((LL)sum[tprev-1]-sum[now]),f[now][j]);
                    //if(min(h[now]+k,h[tprev]) * (tprev-now-1)-((LL)sum[tprev-1]-sum[now])<0)printf("%I64d %d*\n",min((LL)h[now]+k,(LL)h[tprev]), (tprev-now-1));
                }
        }
        result = 0;
        for(i=0;i<n;i++)
            for(k=0;k<=addh;k++)
                result = max(result,f[maxi-i][k]+f[maxi+n-i-1][addh-k]);
        printf("%I64d\n",result);
    }
    cerr<<"time:"<<clock()-tt<<endl;
}
