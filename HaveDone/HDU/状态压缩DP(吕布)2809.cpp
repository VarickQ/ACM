#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define ll __int64
const int N = (1<<20)+100;
const int inf = 1000000000;

struct P{
	int ATI,DEF,HP,exp;
}a[22],lb,now;
int dp[N];
char name[22];
int beat(P a,P b){
	int t,ht,hp;
	ht = max(1,a.ATI-b.DEF);
	t = b.HP/ht;
	if(t*ht >= b.HP) t--;

	ht = max(1,b.ATI-a.DEF);
	hp = a.HP - ht*t;

	return hp>0?hp:0;
}
int main(){
	int InA,InD,InH,n,i,j;
	while(scanf("%d%d%d %d%d%d",&lb.ATI,&lb.DEF,&lb.HP,&InA,&InD,&InH)!=EOF)
	{
		scanf("%d",&n);
		for(i=0 ; i < n ; ++i)
			scanf("%s%d%d%d%d",name,&a[i].ATI,&a[i].DEF,&a[i].HP,&a[i].exp);

		memset(dp,0,sizeof(dp));
		dp[0] = lb.HP;
		for(i=0 ; i < (1<<n)-1 ; ++i){//枚举每个状态
			int exp = 0;
			for(j=0 ; j < n ; ++j)
				if((1<<j)==((1<<j)&i))//已经杀死的对手得到的经验
					exp += a[j].exp;
			for(j=0 ; j < n ; ++j){
				if(!(i&(1<<j))){//未杀死该对手
					now.HP = dp[i];
					now.ATI = lb.ATI + exp/100*InA;
					now.DEF = lb.DEF + exp/100*InD;

					int live = beat(now,a[j]);
					if(live && (exp+a[j].exp)/100 > exp/100)//能杀死该对手并且升级
						live += InH;

					int s = (i|(1<<j));//杀死该对手的状态
					dp[s] = max(dp[s],live);
				}
			}
		}
		if(dp[(1<<n)-1] <= 0)printf("Poor LvBu,his period was gone.\n");
		else printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}