//1009
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
const int inf = 2000000000;
const int N   = 105;

int check( int a, int b, int c){
	if( a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
		return 1;
	if( a*a+b*b<c*c || a*a+c*c<b*b || b*b+c*c<a*a)
		return 2;
	return 3;
}
int main(){
	int T,n,a,b,c,cs=1;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &a, &b, &c);
		printf("Case %d: ", cs++);
		int k = check( a, b, c );
		if( k == 1 ) printf("Right triangle\n");
		else if( k == 2 )
			printf("Obtuse triangle\n");
		else printf("Acute triangle\n");
	}
	return 0;
}
//1000
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
const int inf = 2000000000;
const int N   = 105;

char str[10][30]={{"When Winter Fades"},{"Yu Jian"},
{"Tin O O"},{"I Missed"},{"Stefanie"},{"The Same"},
{"About"},{"Honey Honey"},{"Unfinished"},{"Hey Jude"}};

int main(){
	int T,n;//5.9 1
	scanf("%d", &T);
	printf("Best wishes to Stefanie\n\n");
	while( T-- ){
		scanf("%d", &n);
		n -= 2*(n/7);
		printf("%s\n", str[n%10]);
	}
	return 0;
} 
//1001
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
const int inf = 2000000000;
const int N   = 105;
const double eps = 1e-10;

double xx,yy;
bool check1( double x ){
	if( xx-x+sqrt(yy+sqrt(x)) > 0 )
		return  true;
	return false;
}
bool check2( double y ){
	if( yy-y+sqrt(xx+sqrt(y)) > 0 )
		return  true;
	return false;
}
int main(){
	int T,cs=1,t;
	double l,r,mid;
	scanf("%d", &T);
	while( T-- ){
		scanf("%lf%lf", &xx, &yy);
		printf("Case %d: ", cs++);
		if(xx==0 && yy==0){
			printf("0.000000 0.000000\n");
			continue;
		}
		t = 500;
		l=0,r=20000,mid;
		while( t-- ){
			mid = (l+r)/2;
			if( check1( mid ) )
				l = mid;
			else r = mid;
		}
		printf("%.6lf ", mid);
		t = 500;
		l=0,r=20000,mid;
		while( t-- ){
			mid = (l+r)/2;
			if( check2( mid ) )
				l = mid;
			else r = mid;
		}
		printf("%.6lf\n", mid);
	}
	return 0;
}
//1008
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
const int inf = 2000000000;
const int N   = 105;
const double eps = 1e-10;

int a[20],mark[500];
int main(){
	printf("2 3 6\n");
	a[1] = 2; a[2] = 3; a[3] = 6;
	int x,y,i,j;
	for(i=4 ; i <= 18 ; ++i){
		memset( mark, 0, sizeof( mark ) );
		for(j=1 ; j < i ; ++j)
			mark[a[j]] = 1;
		bool f = false;
		for(j=1 ; j < i ; ++j)
			for(x=2 ; x <= i*i ; ++x)
				for(y=2 ; y <= i*i ; ++y)
					if(x*y==a[j]*(x+y) && !mark[x] && !mark[y] && x!=y)
					{
						f = true;
						goto next;
					}
next:
		if( f ){
			a[j] = x;
			a[i] = y;
			sort( a+1, a+i+1 );
			for( j=1 ; j < i ; ++j)
				printf("%d ", a[j]);
			printf("%d\n", a[i]);
		}
	}
	return 0;
}