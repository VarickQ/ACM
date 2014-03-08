#include <stdio.h>

int main(){
	int n,ans;
	double a,now;
	while(scanf("%d",&n) == 1){
		now = 0;
		ans = 1;
		for(int i=0 ; i < n ; ++i){
			scanf("%lf",&a);
			if(now+a > 4489.5){
				now = a;
				ans++;
			} else {
				now += a;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}