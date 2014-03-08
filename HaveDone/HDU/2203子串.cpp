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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 100005;

char s1[N],s2[N],temp[N];
int main(){
	while( scanf("%s %s",s1,s2) != EOF ){
		strcpy( temp, s1 );
		strcat( s1, temp );
		if( strstr( s1, s2 ) )
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}