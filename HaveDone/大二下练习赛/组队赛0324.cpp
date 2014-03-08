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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 10005;
const int N   = 25;
typedef long long ll;

int a[N],b[N],n;
bool check(int b[]){
	for(int i=2 ; i <= n ; ++i)
		if( b[i] != b[1] ) return false;
	return true;
}
int main(){
	int cs = 1;
	while( scanf("%d", &n) && n ){
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		if( check(a) ){
			printf("Case %d: 0 iterations\n", cs++);
			continue;
		}
		int ans = 0;
		while( ans < 1000 ){
			for(int i=1 ; i < n ; ++i)
				b[i] = abs(a[i]-a[i+1]);
			b[n] = abs(a[n]-a[1]);
			ans++;
			if( check(b) ) break;
			for(int i=1 ; i <= n ; ++i)
				a[i] = b[i];
		}
		if( ans < 1000 )
			printf("Case %d: %d iterations\n", cs++,ans);
		else printf("Case %d: not attained\n", cs++);
	}
	return 0;
}

#include <iostream>
using namespace std;

long long dp[33][33];
bool vis[33][33];
void init()
{
	for (int i = 0; i < 33; i ++)
		dp[i][0] = 1;
	dp[0][1] = 1;
	for (int j = 1; j < 33; j ++)
		for (int i = 0; i < 33; i ++)
		{
			if (i == 0)
				dp[i][j] = dp[1][j-1];
			else
				dp[i][j] = dp[i-1][j] + dp[i+1][j-1];
		}
}

int main()
{
	init();
	int n;
	while (cin >> n && n)
	{
		cout << dp[0][n] << endl;
	}
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 10005;
const int N   = 1000005;
typedef long long ll;

int a[105],b[105];
struct A{
	int day,price;
}x[N];
bool cmp( const A a, const A b ){
	if( a.price == b.price ) return a.day < b.day;
	return a.price < b.price;
}
int main(){
	int n,k1,k2,cs=1;
	while( scanf("%d%d%d",&n,&k1,&k2) &&(n+k1+k2) ){
		
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &x[i].price);
			x[i].day = i+1;
		}
		sort( x, x+n, cmp );
		for(int i=0 ; i < k1 ; ++i)
			a[i] = x[i].day;
		for(int i=n-1,k=0 ; k < k2 ; --i,++k)
			b[k] = x[i].day;

		sort( a, a+k1 );
		sort( b, b+k2 );

		printf("Case %d\n", cs++);
		for(int i=0 ; i < k1-1 ; ++i)
			printf("%d ", a[i]);
		printf("%d\n", a[k1-1]);

		for(int i=k2-1 ; i > 0 ; --i)
			printf("%d ", b[i]);
		printf("%d\n", b[0]);
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 10005;
const int N   = 300005;
typedef long long ll;

char str[N],a[N];
//字符串循环同构的最小表示法
int MinimumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l && k < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else{
            if(t > 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
    }
    return (i < j ? i : j);
}
int main(){
	while( scanf("%s", str) != EOF ){
		int len = strlen( str );
		for(int i=0 ; i < len-1 ; ++i)
			a[i] = ((str[i+1]-str[i])+8)%8+'0';
		a[len-1] = (str[0]-str[len-1]+8)%8+'0';
		a[len] = '\0';
		
		int pos = MinimumRepresentation( a, len );
		for(int i=pos ; i < len ; ++i)
			printf("%c", a[i]);
		for(int i=0 ; i < pos ; ++i)
			printf("%c", a[i]);
		printf("\n");
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 10005;
const int N   = 300005;
typedef long long ll;

char name[205][100];
char user[205][100];
int main(){
	int n,maxLen,cs=1,i,j,k,len;
	char temp[100];
	while( scanf("%d%d\n", &n, &maxLen) && (n+maxLen) ){
		memset( name, 0, sizeof( name ) );
		memset( user, 0, sizeof( user ) );
		for( i=0 ; i < n ; ++i ){
			gets( name[i] );
			len = strlen( name[i] );
			for( j=0 ; j < len ; ++j )
				if( name[i][j]>='A' && name[i][j]<='Z')
					name[i][j] = name[i][j]-'A'+'a';
			for( j=0 ; j < len ; ++j )
				if( name[i][j]!='\'' && name[i][j]!='-' )
					break;
			user[i][0] = name[i][j];
			for( k=0,j=len-1 ; j >= 0 ; --j ){
				if( name[i][j] == ' ') break;
				if( name[i][j]=='\'' || name[i][j]=='-' )
					continue;
				temp[k++] = name[i][j];
			}
			k--;
			for( j=1 ; k >= 0 && j < maxLen ; ++j,--k )
				user[i][j] = temp[k];
		}
		printf("Case %d\n", cs++);
		for( i=0 ; i < n ; ++i ){
			for( j=0 ; j < i ; ++j ){
				strcpy( temp, user[i] );
				if(i!=j && !strcmp(temp,user[j]) ){
					int l = strlen( temp );
					bool ff = false;
					if( l < maxLen ){
						for( k=1 ; k <= 9 ; ++k ){
							temp[l] = k+'0';
							temp[l+1] = '\0';
							bool f = false;
							for(int p=0 ; p < n ; ++p)
								if( !strcmp(temp,user[p]) ){
									f=true; break;
								}
							if( !f ){
								strcpy(user[i],temp);
								ff = true;
								break;
							}
						}
					} else {
						for( k=1 ; k <= 9 ; ++k ){
							temp[maxLen] = '\0';
							temp[maxLen-1] = k+'0';
							bool f = false;
							for(int p=0 ; p < n ; ++p)
								if( !strcmp(temp,user[p]) ){
									f=true; break;
								}
							if( !f ){
								strcpy(user[i],temp);
								ff = true;
								break;
							}
						}
					}
					if( !ff ){
						if( l+2 <= maxLen ){
							for( k=10 ; k <= 99 ; ++k ){
								temp[l] = k/10+'0';
								temp[l+1] = k%10+'0';
								temp[l+2] = '\0';
								bool f = false;
								for(int p=0 ; p < n ; ++p)
									if( !strcmp(temp,user[p]) ){
										f=true; break;
									}
								if( !f ){
									strcpy(user[i],temp);
									break;
								}
							}
						}
						else {
							for( k=10 ; k <= 99 ; ++k ){
								temp[maxLen] = '\0';
								temp[maxLen-1] = k%10+'0';
								temp[maxLen-2] = k/10+'0';
								bool f = false;
								for(int p=0 ; p < n ; ++p)
									if( !strcmp(temp,user[p]) ){
										f=true; break;
									}
								if( !f ){
									strcpy(user[i],temp);
									break;
								}
							}
						}
					}
				}
			}
		}

		for( i=0 ; i < n ; ++i )
			printf("%s\n", user[i]);
	}
	return 0;
}