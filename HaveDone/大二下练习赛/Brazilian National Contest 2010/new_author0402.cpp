//A
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
const int M   = 105;
const int N   = 105;
typedef long long ll;

int main(){
	int n;
	char str[N],ans[N];
	while( scanf("%d %s", &n, str) != EOF ){
		if( n==0 && str[0]=='0' ) break;
		int i,k=0;
		for( i=0 ; str[i] ; ++i )
			if( str[i] != n+'0' )
				ans[k++] = str[i];
		for( i=0 ; ans[i] ; ++i )
			if( ans[i] != '0' ) break;
		if( i < k ){
			for( ; i < k ; ++i )
				printf("%c", ans[i]);
			printf("\n");
		} else printf("0\n");
	}
	return 0;
}
//I
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
const int M   = 2000100;
const int N   = 2005;
typedef long long ll;
struct A{
	int v,next;
}e[M];
int heade[M],k;
//belong[i]=j:第i个点所在的强连通分量的编号是j
int in[N],out[N],belong[N],bcnt;
int stack[M],top;
bool instack[M];
//dfn[u]:节点u搜索的次序编号(时间戳)
//low[u]是u或u的子树能够追溯到的最早的栈中节点的次序号
int dfn[N],low[N],indx;

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++indx;	//为节点u设定次序编号和Low初值
	instack[u] = true;		//标记进入栈
	stack[top++] = u;		//将节点u压入栈中
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){//枚举每一条边
		if(!dfn[e[i].v]){	//如果节点v未被访问过
			tarjan(e[i].v);	//继续向下找
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		} else if(instack[e[i].v] && dfn[e[i].v] < low[u])
			//如果节点u还在栈内
			low[u] = dfn[e[i].v];
	}
	
	if(dfn[u]==low[u]){		//如果节点u是强连通分量的根
		bcnt++;
		int temp;
		do{
			temp = stack[--top];	//将v退栈，为该强连通分量中一个顶点
			instack[temp] = false;
			belong[temp] = bcnt;	//缩点，bcnt就是强连通分量的个数
		}while(u != temp);
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)
			break;
		memset(heade,-1,sizeof(heade));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		bcnt = indx = top = 0;
		int i,a,b,c;
		for( i=0 ; i < m ; ++i ){
			scanf("%d%d%d", &a, &b, &c);
			if(c == 1) add(a,b);
			else if(c == 2){
				add(a,b);
				add(b,a);
			}
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		if(bcnt==1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
//B
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
const int M   = 2000100;
const int N   = 105;
typedef long long ll;

struct Node{
	int dir,x,y;//0,1,2,3东南西北
}a;
int n,m,q;
char mat[N][N],qu[50005];
bool check( int x, int y ){
	if(mat[x][y]!='#' && (x>=0&&x<n&&y>=0&&y<m))
		return true;
	return false;
}
int main(){
	while( scanf("%d%d%d", &n, &m, &q) && (n+m+q) ){
		int x,y;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", mat[i]);
			for(int j=0 ; mat[i][j] ; ++j){
				if(mat[i][j]=='N'){//bei
					a.x = i;
					a.y = j;
					a.dir = 3;
				}
				else if( mat[i][j]=='S' ){//nan
					a.x = i;
					a.y = j;
					a.dir = 1;
				}
				else if( mat[i][j]=='L' ){//dong
					a.x = i;
					a.y = j;
					a.dir = 0;
				}
				else if( mat[i][j]=='O' ){//xi
					a.x = i;
					a.y = j;
					a.dir = 2;
				}
			}
		}
		scanf("%s", qu);
		int u,v,ans=0;
		for(int i=0 ; qu[i] ; ++i){
			if( qu[i] == 'D' ){
				a.dir = (a.dir+1)%4;
			}
			else if( qu[i] == 'E' ){
				a.dir = (a.dir-1+4)%4;
			}
			else if( qu[i] == 'F' ){
				if( a.dir == 0 ){
					u = a.x;
					v = a.y+1;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
				else if( a.dir == 1 ){
					u = a.x+1;
					v = a.y;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
				else if( a.dir == 2 ){
					u = a.x;
					v = a.y-1;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
				else if( a.dir == 3 ){
					u = a.x-1;
					v = a.y;
					if( check(u,v) ){
						a.x = u;
						a.y = v;
						if( mat[u][v] == '*' ){
							ans++;
							mat[u][v] = '.';
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
//J
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
const int M   = 2000100;
const int N   = 105;
typedef long long ll;
int f[10];
int main(){
	int n;
	while(scanf("%d",&n),n){
		int ans=0;
		int id;
		while(n--){
			ans =0;
			for(int i=0;i<5;i++)
				scanf("%d",&f[i]);
			for(int i=0;i<5;i++)
				if(f[i]<=127){
					id= i;
					ans++;
				}
			if(ans==1)
				printf("%c\n",'A'+id);
			else
				printf("*\n");
		}
	}
	return 0;
}
//E
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
const int M   = 2000100;
const int N   = 100005;
typedef long long ll;

struct node{
	double x,y;
};
int r1,r2;
int n,m;
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(b.y-a.y)*(b.y-a.y));
}
int duj(node a,node b){
	if(2*r1>n || 2*r1>m || 2*r2 >m || 2*r2 >n)
		return 0;
	if(a.x<0 ||a.y<0 || b.x<0 || b.y<0)
		return 0;
	if(dis(a,b)<r1+r2)
		return 0;
	return 1;
}
node p1,p2;
int main(){
	
	while(scanf("%d%d%d%d",&n,&m,&r1,&r2)!=EOF){
		if(n+m+r1+r2==0)
			break;
		p1.x=r1;p1.y=m-r1;
		p2.x=n-r2;p2.y=r2;
		if(duj(p1,p2))
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}
//F
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200;
int race[maxn][maxn], scoreSystem[maxn][maxn];
int totalScore[maxn];
int raceNum, scoreSystemNum, pilotNum;
int main () {
	int i, j, k;
	while (scanf ("%d%d", &raceNum, &pilotNum) == 2) {
		if (raceNum == 0 && pilotNum == 0) break;
		for (i = 1; i <= raceNum; ++i) {
			for (j = 1; j <= pilotNum; ++j) {
				scanf ("%d", &race[i][j]);
			}
		}

		memset (scoreSystem, 0, sizeof (scoreSystem));
		scanf ("%d", &scoreSystemNum);
		for (i = 1; i <= scoreSystemNum; ++i) {
			scanf ("%d", &k);
			for (j = 1; j <= k; ++j) {
				scanf ("%d", &scoreSystem[i][j]);
			}
		}

		
		for (i = 1; i <= scoreSystemNum; ++i) {
			memset (totalScore, 0, sizeof (totalScore));
			int maxScore = -1;
			int pos = 0;
			for (j = 1; j <= pilotNum; ++j) {
				for (k = 1; k <= raceNum; ++k) {
					totalScore[j] += scoreSystem[i][race[k][j]];
				}
				if (maxScore < totalScore[j]) {
					maxScore = totalScore[j];
					pos = j;
				}
			}
			for (j = 1; j <= pilotNum; ++j) {
				if (totalScore[j] == maxScore) {
					printf ("%d", j);
					break;
				}
			}
			for (; j <= pilotNum; ++j) {
				if (j != pos && totalScore[j] == maxScore) printf (" %d", j);
			}
			printf ("\n");
		}
	}
	return 0;
}
//H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 2000100;
const int N   = 100005;
typedef long long ll;

int Next[100002];
void NEXT(int *str,int len){
    int i = 0,j = -1;
    Next[0] = -1;
	while(i < len){
        if(j == -1 || str[i] == str[j])
            ++i,++j,Next[i] = j;
		else j = Next[j];
    }
}
void KMP(int *cs, int s1, int *str, int s2){
    int i = 0, j = 0;
	int ans = 0;
	while(i < s1 && j < s2){
		if(j == -1 || cs[i] == str[j])
			i ++,j ++;
		else j = Next[j];
	}
	if(j == s2) printf("S\n");
	else printf("N\n");
}
int v[500];
int main(){
	v['A'] = 0;
	v['A'+'#'] = v['B'+'b'] = 1;
	v['C'+'b'] = v['B'] = 2;
	v['B'+'#'] = v['C'] = 3;
	v['C'+'#'] = v['D'+'b'] = 4;
	v['D'] = 5;
	v['D'+'#'] = v['E'+'b'] = 6;
	v['F'+'b'] = v['E'] = 7;
	v['E'+'#'] = v['F'] = 8;
	v['F'+'#'] = v['G'+'b'] = 9;
	v['G'] = 10;
	v['G'+'#'] = v['A'+'b'] = 11;
	int n,m;
	int a[N],b[N];
	while( scanf("%d%d", &n, &m) && (n+m) ){
		char s[3],temp[3];
		scanf("%s", temp);
		for(int i=1 ; i < n ; ++i){
			scanf("%s", s);
			int num1=0,num2=0;
			for(int j=0 ; temp[j] ; ++j)
				num1 += temp[j];
			for(int j=0 ; s[j] ; ++j)
				num2 += s[j];
			a[i-1] = (v[num2]-v[num1]+12)%12;
			strcpy(temp,s);
		}

		scanf("%s", temp);
		for(int i=1 ; i < m ; ++i){
			scanf("%s", s);
			int num1=0,num2=0;
			for(int j=0 ; temp[j] ; ++j)
				num1 += temp[j];
			for(int j=0 ; s[j] ; ++j)
				num2 += s[j];
			b[i-1] = (v[num2]-v[num1]+12)%12;
			strcpy(temp,s);
		}

		NEXT(b,m-1);
		KMP(a,n-1,b,m-1);
	}
	return 0;
}
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 2000100;
const int N   = 100005;
typedef long long ll;

int n,m;
int f[50];
int dp[50][32009];
int ans[50];
int main(){
#ifndef ONLINE_JUDGE
	freopen ("test.txt", "r", stdin);
#endif
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n+m==0)
			break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&f[i]);
			ans[i]=0;
		}
		dp[0][16000]=1;
		for(int i=1;i<=n;i++)
			for(int j=-16000;j<=16000;j++){
				if(dp[i-1][j+16000]){

					dp[i][j+f[i]+16000]=1;

					if(j-f[i]+16000>=0)
						dp[i][j-f[i]+16000]=1;
				}
			}

		if(dp[n][m+16000]==0)
			printf("*\n");
		else{
			dp[n][m+16000]=-1;
			for(int i=n;i>=1;i--)
				for(int j=-16000;j<=16000;j++){
					if(! dp[i-1][j+16000])
						continue;
					if(dp[i][j+16000+f[i]]==-1){

						dp[i-1][j+16000]=-1;
						if(ans[i]==0)
							ans[i]=1;
						else if(ans[i]!=1)
							ans[i]=-2;
					}
					if( j-f[i]+16000>=0 &&dp[i][j+16000-f[i]]==-1){//

						dp[i-1][j+16000]=-1;
						if(ans[i]==0)
							ans[i]=-1;
						else if(ans[i]!=-1)
							ans[i]=-2;
					}
				}
			for(int i=1;i<=n;i++)
				if(ans[i]==-1)
					printf("-");
				else if(ans[i]==1)
					printf("+");
				else
					printf("?");
				printf("\n");
		}
	}
	return 0;
}
//D 补
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 35000;
const int N   = 255;
typedef long long ll;

struct A{
	int c,v,next;
}e[M];
int heade[N],ee;
int n,m,c,k;
int d[N],qu[M];
bool vis[N];
void spfa(int s){
	int i,head=0,tail=1;
	memset( vis, false, sizeof( vis ) );
	for( i=0 ; i<= n ; ++i ) d[i] = inf;
	d[s] = 0;
	qu[0] = s;
	while( tail > head ){
		int u = qu[head];
		vis[u] = true;
		for( i=heade[u] ; i!=-1 ; i=e[i].next ){
			int v = e[i].v;
			if( d[v] > d[u]+e[i].c ){
				d[v] = d[u]+e[i].c;
				if( !vis[v] ){
					vis[v] = true;
					qu[tail++] = v;
				}
			}
		}
		vis[u] = false;
		head++;
	}
}
void add(int u,int v,int c){
	e[ee].v = v;
	e[ee].c = c;
	e[ee].next = heade[u];
	heade[u] = ee++;
}
int main(){
	int u,v,p;
	while( scanf("%d%d%d%d",&n,&m,&c,&k) != EOF ){
		if( !(n+m+c+k) ) break;
		memset( heade, -1, sizeof( heade ) );
		ee = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &u, &v, &p);//v>u
			if( v < u ) swap(u,v);
			if( u < c ){
				if( v < c && v==u+1) add( u, v, p );
				else add( v, u, p );
			} else {
				add( u, v, p );
				add( v, u, p );
			}
		}
		spfa( k );
		printf("%d\n", d[c-1]);
	}
	return 0;
}