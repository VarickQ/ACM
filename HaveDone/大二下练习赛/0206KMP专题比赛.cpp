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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 100005;

char str[N];
int next[N];
void Next( char *str ){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int main(){
	int T,len;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", str);
		Next( str );
		len = strlen( str );
		int ans,x = len - next[len];//Ñ­»·½Úx=len-next[len];
		if(len%x == 0){
			if(len == x) ans = len;
			else ans = 0;
		} else ans = x - len%x;
		printf("%d\n", ans);
		/*if( len <= next[len]*2) printf("0\n");
		else printf("%d\n", len-next[len]*2);*/
	}
	return 0;
}
//1003
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
const int N   = 1000005;

char str[N];
int next[N];
void Next(){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int main(){
	int n,cs=1;
	while( scanf("%d", &n) && n ){
		scanf("%s", str);
		Next();
		printf("Test case #%d\n",cs++);
		for(int i=2 ; i <= n ; ++i){
			int j = i-next[i];
			if( i%j==0 && i/j > 1)
				printf("%d %d\n",i,i/j);
		}
		printf("\n");
	}
	return 0;
}
//1004
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
const int N   = 1005;

char cs[N],str[N];
int next[N];
void Next(){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
void KMP(){
	int i = 0, j = 0;
	int s1 = strlen( cs );
	int s2 = strlen( str );
	int ans = 0;
	while( cs[i] ){
		while( i < s1 && j < s2 ){
			if( j == -1 || cs[i] == str[j] )
				++i, ++j;
			else j = next[j];
		}
		if( j >= s2 ){
			ans++;
			j = 0;
		}
	}
	printf("%d\n", ans );
}
int main(){
	while(scanf("%s", cs) != EOF){
		if( cs[0] == '#' ) break;
		scanf("%s", str);
		Next();
		KMP();
	}
	return 0;
}
//1005
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
const int N   = 50005;

char cs[N],str[N];
int next[N];
void Next( char *str ){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int KMP( char *cs, char *str ){
	int i = 0, j = 0;
	int s1 = strlen( cs );
	int s2 = strlen( str );
	while( i < s1 && j < s2 ){
		if( j == -1 || cs[i] == str[j] )
			++i, ++j;
		else j = next[j];
	}
	if( i >= s1 ) return j;
	else return 0;
}
int main(){
	int len;
	while( scanf("%s %s", str, cs) != EOF ){
		int s1 = strlen( str );
		int s2 = strlen( cs );
		if( s2 > s1 ){
			for(int i=0,j=s2-s1 ; j < s2 ; ++i,++j)
				cs[i] = cs[j];
			cs[s1] = '\0';
		} else if( s2 < s1 )
			str[s2] = '\0';
		Next( str );
		len = KMP( cs, str );
		if(len != 0){
			for(int i=0 ; i < len ; ++i)
				printf("%c", str[i]);
			printf(" %d\n", len );
		} else printf("0\n");
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
typedef __int64 ll;
const int inf = 2000000000;
const int N   = 100005;

char cs[N],str[N];
int next[N];
void Next( char *str ){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int KMP( char *cs, char *str ){
	int i = 0, j = 0;
	int s1 = strlen( cs );
	int s2 = strlen( str );
	while( i < s1 && j < s2 ){
		if( j == -1 || cs[i] == str[j] )
			++i, ++j;
		else j = next[j];
	}
	if( i >= s1 ) return j;
	else return 0;
}
int main(){
	int s1,s2;
	while( scanf("%s %s", cs, str) != EOF ){

		memset( next, 0, sizeof( next ) );
		Next( str );
		s1 = KMP( cs, str );
		
		memset( next, 0, sizeof( next ) );
		Next( cs );
		s2 = KMP( str, cs );

		if( s1 == s2 ){
			if( strcmp( cs, str ) < 0 ){
				printf("%s", cs);
				printf("%s", str+s1);
			} else {
				printf("%s", str);
				printf("%s", cs+s1);
			}
		} else if( s1 < s2 ){
			printf("%s", str);
			printf("%s", cs+s2);
		} else {
			printf("%s", cs);
			printf("%s", str+s1);
		}
		printf("\n");
	}
	return 0;
}
//1006 ²¹
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
const int N   = 200005;

char str[N],s[N];
int next[N],num[N];
void Next( char *str ){
	int i = 0, j = -1;
	next[0] = -1;
	while( str[i] ){
		if( j == -1 || str[i] == str[j] )
			++i, ++j, next[i] = j;
		else j = next[j];
	}
}
int main(){
	int T,len,ans;
	scanf("%d", &T);
	while( T-- ){
		memset( num, 0, sizeof( num ) );
		scanf("%d", &len);
		scanf("%s", str);
		Next( str );
		for(int i=len ; i >= 1 ; --i){
			num[i]++;
			num[next[i]] += num[i];
		}
		ans = 0;
		for(int i=1 ; i <= len ; ++i)
			ans = (ans+num[i])%10007;
		printf("%d\n", ans);
	}
	return 0;
}