#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int inf = 2000000000;
const int M = 2000100;
const int N = 10010;
int day[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int isleap(int n){
	if((n%4==0 && n%100!=0) || n%400==0)
		return 29;
	return 28;
}
int main(){
	int T,m1,d1,y,m2,d2,res,cs=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d/%d/%d %d/%d",&m1,&d1,&y,&m2,&d2);
		res = inf;
		if(m1 == 1){
			if(m2 == 1)	res = d2-d1;
			else if(m2 == 12){
				res = d2-d1-31; y--;
			}
			else if(m2 == 2) res = d2-d1+31;
		} else if(m1 == 12){
			if(m2 == 12) res = d2-d1;
			else if(m2 == 1){
				res = d2-d1+31; y++;
			}
			else if(m2 == 11)res = d2-d1-day[11];
		} else if(m1 == 2){
			if(m2 == 2) res = d2-d1;
			else if(m2 == 1) res = d2-d1-31;
			else if(m2 == 3) res = d2-d1+isleap(y);
		} else if(m1 == 3){
			if(m2 == 3) res = d2-d1;
			else if(m2 == 2) res = d2-d1-isleap(y);
			else if(m2 == 4) res = d2-d1+day[4];
		} else {
			if(m1 == m2)res = d2-d1;
			else if(m1==m2+1)res = d2-d1-day[m2];
			else if(m1+1==m2)res = d2-d1+day[m1];
		}
		printf("%d ",++cs);
		if(abs(res) > 7)	printf("OUT OF RANGE\n");
		else {
			if(res == 0) printf("SAME DAY\n");
			else {
				printf("%d/%d/%d ",m2,d2,y);
				if(res < 0){
					res = -res;
					if(res == 1)printf("IS 1 DAY PRIOR\n");
					else printf("IS %d DAYS PRIOR\n",res);
				} else {
					if(res == 1)printf("IS 1 DAY AFTER\n");
					else printf("IS %d DAYS AFTER\n",res);
				}
			}
		}
	}
	return 0;
}