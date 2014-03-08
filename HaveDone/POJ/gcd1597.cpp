#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 20005;
const int N = 10005;

int gcd( int a, int b ){
	if( b == 0 ) return a;
	else return gcd( b, a%b );
}
int main(){
	int step,mod,len,x;
	while( scanf("%d%d",&step,&mod) != EOF ){
		len = 0,x = step;
		while( x != 0 ){
			x /= 10; len++;
		}
		for(int i=0 ; i < 10-len ; ++i)
			printf(" ");
		printf("%d", step);

		len = 0,x = mod;
		while( x != 0 ){
			x /= 10; len++;
		}
		for(int i=0 ; i < 10-len ; ++i)
			printf(" ");
		printf("%d", mod);

		if( gcd( step, mod ) == 1 )
			printf("    Good Choice\n\n");
		else
			printf("    Bad Choice\n\n");
	}
	return 0;
}