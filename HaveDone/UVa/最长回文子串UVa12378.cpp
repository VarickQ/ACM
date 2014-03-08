#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int N=300010;

int n, p[N];
char s[N], str[N], ss[N];
#define _min(x, y) ((x)<(y)?(x):(y))
void kp(){
    int i, mx = 0, id;
    for( i=1 ; i < n ; i++ ){
        if( mx > i )p[i] = _min( p[2*id-i], p[id]+id-i );
        else p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++);
        if( p[i] + i > mx ){
            mx = p[i] + i;
            id = i;
        }
    }
}

void init(){
	int i, j, k;
	str[0] = '$';
	str[1] = '#';
	for( i=0 ; i < n ; i++ ){
		str[i*2+2] = s[i];
		str[i*2+3] = '#';
	}
	n = n*2+2;
	s[n] = 0;
}

int main(){
	int i, ans, T;
	scanf("%d", &T);
	while(T--){
		CLR( str, 0 );
		scanf("%s", ss);
		n = strlen(ss);
		int t = 0;
		for(int i=0 ; i < n-1 ; ++i)
			if( ss[i] != ss[i+1] )
				s[t++] = ss[i];
		if(s[t-1] != ss[n-1])
			s[t++] = ss[n-1];
		s[t] = '\0';
		n = t;
		init();
		kp();
		ans = 0;
		for(i=0; i < n ; i++)
			if(p[i] > ans)
				ans = p[i];
		printf("%d\n", ans/2);
	}
	return 0;
}

////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const int N = 100050;

char str[N],s[N];
int p[N*2];
int Manacher( char *s, int n ){
	int i, mx = 0, id = 0;
	for ( i = 1; i <= n ; i++ ) {
		p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
		while (i+p[i]<=n && i-p[i]>0 && s[i+p[i]]==s[i-p[i]])
			p[i]++;
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
	}
	int ans = 1;
	for(int i=1 ; i <= n ; ++i)
		ans = max( p[i], ans );
	return ans;
}
int main() {
	int T;
	scanf("%d", &T);
	while( T-- ){
		CLR( str, 0 );
		CLR( s, 0 );
		scanf("%s", str);
		int len = strlen(str);
		str[len] = '#';
		int k = 1;
		s[0] = '#';
		for(int i=0 ; i < len ; ++i)
			if( str[i] != str[i+1] )
				s[k++] = str[i];
		s[k] = '\0';
		printf("%d\n", Manacher(s,k-1));
	}
	return 0;
}