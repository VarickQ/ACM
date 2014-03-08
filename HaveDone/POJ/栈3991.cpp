#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N = 20050;

char s[N];
stack<char> sta;
int main(){
	int cs = 1;
	while( scanf("%s", s) != EOF ){
		if( s[0] == '-' ) break;
		while(!sta.empty()) sta.pop();
		int ans = 0;
		for(int i=0 ; s[i] ; ++i){
			if( s[i] == '{' )
				sta.push(s[i]);
			else {
				if( sta.empty() ){
					sta.push(s[i]);
					ans++;
				}
				else sta.pop();
			}
		}
		ans += sta.size()/2;
		printf("%d. %d\n", cs++, ans);
	}
	return 0;
}