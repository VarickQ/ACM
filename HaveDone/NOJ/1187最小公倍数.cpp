#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 1000000000;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int T,n,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&a);
		for(int i=1 ; i < n ; ++i){
			scanf("%d",&b);
			if(a > b) a = a/gcd(a,b)*b;
			else a = a/gcd(b,a)*b;
		}
		printf("%d\n",a);
	}
	return 0;
}