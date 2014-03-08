#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 2050;
const __int64 inf = (1LL)<<60;
#define ll __int64

ll dp[15][N];
int n,m;
bool ok(int i,int j){
	int t = m;
	while(t--){
		if(i&1){
			if(j&1){
				if((i&2)&(j&2)){
					t--;
					i >>= 1;
					j >>= 1;
				}
				else return false;
			}
		}
		else if(!(j&1)) return false;
		i >>= 1;
		j >>= 1;
	}
	return true;
}

int main(){
	int i,j,k;
	while(scanf("%d%d",&n,&m) && (n+m))
	{
		if(n*m&1) printf("0\n");
		else {
			memset(dp,0,sizeof(dp));
			for(i=0 ; i < (1<<m) ; ++i)
				if(ok(i,(1<<m)-1)) dp[0][i] = 1;
			for(i=1 ; i < n ; ++i)
				for(j=0 ; j < (1<<m) ; ++j)
					for(k=0 ; k < (1<<m) ; ++k){
						if(dp[i-1][k] && ok(j,k))
							dp[i][j] += dp[i-1][k];
					}
			printf("%I64d\n",dp[n-1][(1<<m)-1]);
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

const int N = 2050;
const __int64 inf = (1LL)<<60;
#define ll __int64
ll ans[11][11]={
	{0,1,0,1,0,1,0,1,0,1,0},
	{1,2,3,5,8,13,21,34,55,89,144},
	{0,3,0,11,0,41,0,153,0,571,0},
	{1,5,11,36,95,281,781,2245,6336,18061,51205},
	{0,8,0,95,0,1183,0,14824,0,185921,0},
	{1,13,41,281,1183,6728,31529,167089,817991,4213133,21001799},
	{0,21,0,781,0,31529,0,1292697,0,53175517,0},
	{1,34,153,2245,14824,167089,1292697,12988816,108435745,1031151241,8940739824},
	{0,55,0,6336,0,817991,0,108435745,0,14479521761,0},
	{1,89,571,18061,185921,4213133,53175517,1031151241,14479521761,258584046368,3852472573499},
	{0,144,0,51205,0,21001799,0,8940739824,0,3852472573499,0}
};

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && (n+m))
	{
		printf("%I64d\n",ans[--n][--m]);
	}
	return 0;
}