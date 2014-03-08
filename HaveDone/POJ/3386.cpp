#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 2000;

int main(){
	int A,B,a,b,p;
	while(scanf("%d%d%d%d%d",&A,&a,&B,&b,&p) != EOF){
		if(A<=b && B<=p || A+B<=p || B<=a && A<=p)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}