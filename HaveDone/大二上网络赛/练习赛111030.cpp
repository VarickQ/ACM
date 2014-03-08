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
#define eps 1e-8
#define PI acos(-1.0)
const int inf = 2000000000;
const int M = 105555;
const int N = 1001;

int main(){
	int sum,n,a;
	while(scanf("%d",&n) == 1){
		sum = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%d",&a);
			sum += a;
		}
		printf("%d\n",sum+1);
	}
	return 0;
}

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
#define eps 1e-8
#define PI acos(-1.0)
const int inf = 2000000000;
const int M = 105555;
const int N = 1001;

int main(){
	double c;
	int a,b;
	while(scanf("%d%d%lf",&a,&b,&c) == 3){
		if(a==0&&b==0&&c==0) break;
		if(c < PI) printf("%d\n",a-1);
		else printf("%d\n",a-2);
	}
	return 0;
}