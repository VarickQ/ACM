#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 10010;

bool check(char *a,char *b,char *c){
	int cnt = 0;
	for(int i=0 ; i < 4 ; ++i)
		if(a[i]==b[i] && a[i]==c[i] && b[i]==c[i] ||
			a[i]!=b[i] && a[i]!=c[i] && b[i]!=c[i])
			cnt++;
	if(cnt==4) return true;
	else return false;
}
int main()
{
	char str[25][5];
	int i,j,k,cs;
	bool f;
	while(scanf("%s",str[0]) != EOF)
	{
		for(i=1 ; i < 12 ; ++i)
			scanf("%s",str[i]);
		printf("CARDS: ");
		for(i=0 ; i < 12 ; ++i)
			printf(" %s",str[i]);
		printf("\nSETS:   ");
		cs = 1;
		f = false;
		for(i=0 ; i < 12 ; ++i)
			for(j=i+1 ; j < 12 ; ++j)
				for(k=j+1 ; k < 12 ; ++k)
					if(check(str[i],str[j],str[k])){
						if(f)printf("        ");
						f = true;
						printf("%d.  %s %s %s\n",cs++,str[i],str[j],str[k]);
					}
		if(!f)printf("*** None Found ***\n");
		printf("\n");
	}
	return 0;
}