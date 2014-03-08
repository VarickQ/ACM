#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
const int inf = 1000000000;
const int M = 100000;
const int N = 1005;

map<string,int> ma;
map<string,int>::iterator ok;
char a[7],b[7];
bool vs[7][7],f;
int main(){
	int T,n,cs=0,i,j,m;
	char str[22];
	scanf("%d",&T);
	while(T--){
		ma.clear();
		memset(vs,0,sizeof(vs));
		scanf("%d",&n);
		for(i=1 ; i <= n ; ++i){
			scanf("%s",str);
			ma[str] = i;
			a[i-1] = b[i-1] = i+'0';
		}
		i = 1;
		for(ok=ma.begin() ; ok!=ma.end() ; ++ok,++i)
			ok->second = i;
		for(i=1 ; i <= n ; ++i){
			scanf("%d",&m);
			for(j=0 ; j < m ; ++j){
				scanf("%s",str);
				vs[i][ma[str]] = true;
			}
		}
		printf("Case %d: ",++cs);
		do{
			f = true;
			do{
				i = j = 0;
				while(1){
					if(vs[b[i]-'0'][a[j]-'0'])
						j++;
					else i++;
					if(j==n)f = false;
					if(i==n || j==n) break;
				}
				if(!f) break;
			}while(next_permutation(b,b+n));
			if(f) break;
			for(i=1 ; i <= n ; ++i)
				b[i-1] = i+'0';
		}while(next_permutation(a,a+n));
		if(f){
			printf("Yes\n");
			for(i=0 ; i < n ; ++i){
				for(ok=ma.begin() ; ok!=ma.end() ; ++ok)
					if(ok->second == a[i]-'0'){
						if(!i) cout << ok->first;
						else cout <<' '<< ok->first;
						break;
					}
			}
			printf("\n");
		} else printf("No\n");
	}
	return 0;
}