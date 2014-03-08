#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
const int inf = 2000000000;
const int M = 35000;
const int N = 1005;

bool su[M];
int prime[M],cnt;
void PrimeList(){
	su[1] = su[0] = true;
	for(ll i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(ll j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-100 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}
int main(){
	PrimeList();
	int n,m;
	while(scanf("%d",&n) == 1)
	{
		for(int i=0 ; i < n ; ++i){
			scanf("%d",&m);
			for(int j=0 ; j <= M-100 ; ++j)
				if(prime[j] > m){
					printf("%d\n",prime[j]);
					break;
				}
		}
	}
	return 0;
}