/********************************************************************
��Ŀ����i+(i+1)+(i+2)�Ľ��������û�н�λ
��ȻҪ�ҳ����ɣ����λ����1,2,3���м����Ҫ����0,1,2,3��
��λ������0,1,2;����ֻҪ�ҳ�n֮ǰ����������������ĸ������Ǵ���
# hdu 2451
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64

int a[12],b[12];
int main(){
	int i,len;
	ll n,ans;
	a[1] = 3;
	for(i=2 ; i <= 10 ; ++i)
		a[i] = a[i-1]*4;
	while(scanf("%I64d",&n)!= EOF){
		if(n < 10){
			if(n <= 3) printf("%I64d\n",n);
			else printf("3\n");
			continue;
		}
		len = 0;
		while(n > 9){
			b[len++] = n%10;
			n /= 10;
		}
		b[len] = n;
		ans = a[len];
		for(i=len ; i >= 0 ; --i){
			if(i == len){
				if(b[i] <= 3) ans += (n-1)*a[i];
				else{
					ans += 3*a[i];
					break;
				}
			}
			else if(i != 0){
				if(b[i] <= 3) ans += b[i]*a[i];
				else{
					ans += 4*a[i];
					break;
				}
			}
			else if(i == 0){
				if(b[i] <= 3) ans += b[i];
				else ans += 3;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}