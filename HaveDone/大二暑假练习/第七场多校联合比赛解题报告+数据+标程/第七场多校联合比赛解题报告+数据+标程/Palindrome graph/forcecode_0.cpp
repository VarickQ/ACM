#include<stdio.h>
#include<memory.h> 
#define LL long long
#define MM 100000007
int n,m,i,j,k,ti,tj,tmp;
int g[10005][10005];
LL result;
LL calc(int n){
    return n*(n+1)/2;
}
LL pow_mod(LL a,LL n,LL m){
    int b = 1;
    while(n>0){
        if(n&1)b = (b*a)%m;
        n>>=1;
        a = (a*a)%m;
    }
    return b;
}
void add(int ti,int tj){
    g[ti][tj] = 1;   
    g[n-1-ti][tj] = 1;   
    g[ti][n-1-tj] = 1;   
    g[n-1-ti][n-1-tj] = 1;
    g[tj][ti] = 1;   
    g[n-1-tj][ti] = 1;   
    g[tj][n-1-ti] = 1;   
    g[n-1-tj][n-1-ti] = 1;  
}
int main(){
        FILE *ff,*fi; 
    LL ttt,res;
    
    freopen("data.in","r",stdin);
    fi = fopen("data.out","r");
    ff = fopen("forcedata_0.out","w");
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        memset(g,0,sizeof(g));
        //if(n>8000)break;
        for(i=0;i<m;i++){
            scanf("%d%d%",&ti,&tj);   
            //printf("%d %d\n",n,tj); 
            add(ti,tj);
        }
        result = 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(!g[i][j]){
                    result++;
                    add(i,j);
                }
            }
        //printf("%I64d\n",result);
        fscanf(fi,"%I64d",&ttt);
        result = pow_mod(k,result,MM);
        printf("%I64d %s\n",result,ttt==result?"ok":"!!!!!!!!!!!!!!!!!!!!!!");
        if(ttt!=result)scanf(" ");
        fprintf(ff,"%I64d\n",result);
    }
    scanf(" ");
}
