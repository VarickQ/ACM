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
const int M = 100000;
const int N = 1005;

int main()
{
	double h,t,v,x,Min,l;
	while(scanf("%lf%lf%lf%lf",&h,&t,&v,&x) != EOF){
		if(h/x < t) Min=0;
		else{
			l = x*(v*t-h)/(v-x);
			Min = (h-l)/v;
		}
		printf("%lf %lf\n",Min,min(h/x,t));
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
const int inf = 2000000000;
const int M = 100000;
const int N = 1005;

int main()
{
	int n,ans;
	char str[5];
	while(scanf("%d%s",&n,str) != EOF){
		ans = -1;
		if(n==1 || n==2){
			if(str[0]=='A'||str[0]=='D') ans=1;
			else if(str[0]=='B'||str[0]=='C') ans=2;
			else ans=3;
		} else if(n>=3 && n <=20){
			if(str[0]=='A'||str[0]=='F') ans=1;
			else if(str[0]=='B'||str[0]=='C'||str[0]=='D'||str[0]=='E') ans=2;
			else ans=3;
		} else if(n>=21 && n<=65){
			if(str[0]=='A'||str[0]=='K') ans=1;
			else if(str[0]=='C'||str[0]=='D'||str[0]=='G'||str[0]=='H') ans=2;
			else ans=3;
		}
		if(ans==1) printf("window\n");
		else if(ans==2) printf("aisle\n");
		else if(ans==3) printf("neither\n");
	}
	return 0;
}

///////////////ฒน
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
const int M = 100000;
const int N = 1005;

string a[N];
map<string,bool> ma;
int n;
bool check(int z){
	string temp;
	int i,j,l=n/z;
	for(i=1 ; i <= n ; ){
		temp = a[i];
		i++;
		for(j=i-1 ; i < j+l ; ++i){
			if(a[i]=="unknown")continue;
			if(a[i]==temp)continue;
			if(temp=="unknown"){
				temp = a[i];
				continue;
			}
			return false;
		}
		if(ma[temp] && temp!="unknown")
			return false;
		else ma[temp] = true;
	}
	return true;
}
int main(){
	int i;
	while(scanf("%d",&n) == 1){
		for(i=1 ; i <= n ; ++i)
			cin >> a[i];
		bool f = true;
		for(i=1 ; i <= n ; ++i){
			if(n%i)continue;
			ma.clear();
			if(check(i)){
				if(f){
					printf("%d",i);
					f = false;
				} else printf(" %d",i);
			}
		}
		if(f)printf("Igor is wrong.");
		printf("\n");
	}
	return 0;
}