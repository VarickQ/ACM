#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int M = 35000;
const int N = 1005;

int main()
{
	int len,k,carry;
	char str[62];
	while(scanf("%s",str) != EOF)
	{
		int f = 1;
		len = strlen(str);
		k = len+1;
		carry = 0;
		while(len--){
			if(((str[len]-'0')*k+carry)%10 != 9){
				f = 0; break;
			}
			carry = ((str[len]-'0')*k+carry)/10;
		}
		if( f )
			printf("%s is cyclic\n",str);
		else
			printf("%s is not cyclic\n",str);
	}
	return 0;
}