#include<stdio.h>
#include<map>
#define LL long long
#define MM 100000007
using namespace std;
map<pair<int,int>,int>M;
int n,m,i,j,k,ti,tj,tmp;
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
int main(){

    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        M.clear();
        result = calc((n+1)/2);
        for(i=0;i<m;i++){
            scanf("%d%d",&ti,&tj);    
            if(ti>n-1-ti)ti = n-1-ti;   
            if(tj>n-1-tj)tj = n-1-tj;   
            if(ti>tj){
                tmp = ti,ti = tj,tj = tmp;
            }
            if(!M[make_pair(ti,tj)]){
                M[make_pair(ti,tj)] = 1;
                result--;
            }
        }
        printf("%I64d\n",pow_mod(k,result,MM));
    }
}
