#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
#define M 40

int n,m;

int main()
{
	int ca;
	int i,j;
	srand(time(0));
	freopen("data.in","w",stdout);
	ca=1000;
	printf("%d\n",ca);
	while (ca--)
	{
		n=rand()%M+1;
		m=rand()%M+1;
		printf("%d %d\n",n,m);
	}
	return 0;
}
