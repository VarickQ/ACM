#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define ll __int64
const int inf = (1<<30);
const ll M = 1000000007;
const int N = 1000010;

//¿ìËÙÃÝ x^n%M
ll sPow(int x,ll n){
    ll sum = 1;
	ll temp = x%M;//!!!!!!!
    while(n){
        if(n&1) sum = sum*temp%M;
        temp = temp*temp%M;
        n >>= 1;
    }
    return sum;
}
ll numZ[N],numF[N];
int main(){
    int T,n,a,zs,fs,cs=0;
    ll ans,m;
    scanf("%d",&T);
    while(T--){
        memset(numZ,0,sizeof(numZ));
        memset(numF,0,sizeof(numF));
        fs = zs = 0;
        scanf("%d%I64d",&n,&m);
        for(int i=0 ; i < n ; ++i){
            scanf("%d",&a);
            if(a < 0) numF[fs++] = a;
            else numZ[zs++] = a;
        }
        if(fs&1){
            sort(numF,numF+fs);
            while(m && numF[fs-1] != 1)
                m--,numF[fs-1]++;
            if(numF[fs-1] > -1){
                numZ[zs++] = numF[fs-1];
                fs--;
            }
        }
        for(int i=0 ; i < zs ; ++i)
            if(numZ[i] == 0)
                if(m) numZ[i]++,m--;
        for(int i=0 ; i < zs ; ++i)
            if(numZ[i] == 1)
                if(m) numZ[i]++,m--;
        for(int i=0 ; i < zs ; ++i)
            if(numZ[i] == 2)
                if(m) numZ[i]++,m--;
        if(m >= 3){
            numZ[zs++] = sPow(3,m/3);
            m %= 3;
        }
        sort(numZ,numZ+zs);
        if(m == 2) numZ[zs++] = 2;
        if(m == 1) numZ[0]++;
        ans = 1;
        for(int i=0 ; i < fs ; ++i)
            ans = ans*numF[i]%M;
        for(int i=0 ; i < zs ; ++i)
            ans = ans*numZ[i]%M;
        printf("Case %d: %I64d\n",++cs,ans);
    }
    return 0;
}