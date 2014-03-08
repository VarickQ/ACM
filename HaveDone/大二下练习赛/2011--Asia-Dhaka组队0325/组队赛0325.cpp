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
const int N   = 10005;
typedef long long ll;

int main(){
	int T,a,b,c,cs=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &a, &b, &c);
		if( a>20 || b>20 || c>20 )
			printf("Case %d: bad\n", cs++);
		else printf("Case %d: good\n", cs++);
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
const int M   = 5005;
const int N   = 105;
typedef long long ll;

int n,sum,pos,m;
struct A{
	int val,id;
}a[N];
struct Node{
	int v,next;
}e[M];
int heade[N],k;
void add( int u, int v ){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}
struct cmp{//从大到小
	bool operator()(const int &x,const int &y){
		return a[x].val < a[y].val;
	}
};
//priority_queue<int,vector<int>,cmp> qu;
void dfs(int u){
	priority_queue<int,vector<int>,cmp> q;
	for(int i=heade[u] ; i!=-1 ; i=e[i].next)
		q.push(e[i].v);
	if( q.empty() ){
		pos = u; return ;
	}
	sum += a[q.top()].val;
	dfs( q.top() );
}
int main(){
	int T,cs=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=0 ; i < n ; ++i){
			scanf("%d", &a[i].val);
			a[i].id = i;
		}
		memset( heade, -1, sizeof( heade ) );
		k = 0;
		int u,v;
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d", &u, &v);
			add( u, v );
		}
		sum = 0;
		dfs(0);
		printf("Case %d: %d %d\n",cs++,sum,pos);
	}
	return 0;
}
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
const int N   = 1002;
typedef long long ll;

int rowNum[N],colNum[N];
int mat[N][N];
int main(){
	int cs=1,n,m,T,sum,a;
	char str[N];
	scanf("%d", &T);
	while(T--){
		memset( rowNum, 0, sizeof( rowNum ) );
		memset( colNum, 0, sizeof( colNum ) );
		memset( mat, 0, sizeof( mat ) );
		scanf("%d%d", &n, &m);
		sum = 0;
		for(int i=0 ; i < n ; ++i){
			scanf("%s", str);
			for(int j=0 ; str[j] ; ++j){
				mat[i][j] = str[j]-'0';
				sum += str[j]-'0';
				rowNum[i] += str[j]-'0';
				colNum[j] += str[j]-'0';
			}
		}
		bool frow=false,fcol=false;
		int r,c,rowSum=0,colSum=0;
		if( sum%n == 0 ){
			frow = true;
			r = sum/n;
		}
		if( sum%m == 0 ){
			fcol = true;
			c = sum/m;
		}
		if( frow ){
			rowSum = inf;
			for(int i=0 ; i < n ; ++i){
				int num = 0;
				sum = 0;
				for(int j=(i+1)%n ; j!=i ; j=(j+1)%n){
					num = num + rowNum[j] - r;
					sum += abs(num);
				}
				if( sum < rowSum ) rowSum = sum;
			}
		}
		if( fcol ){
			colSum = inf;
			for(int i=0 ; i < m ; ++i){
				int num = 0;
				sum = 0;
				for(int j=(i+1)%m ; j!=i ; j=(j+1)%m){
					num = num + colNum[j] - c;
					sum += abs(num);
				}
				if( sum < colSum ) colSum = sum;
			}
		}
		printf("Case %d: ",cs++);
		
		if( frow && fcol )
			printf("both %d\n", rowSum+colSum);
		else if( frow ) printf("row %d\n", rowSum);
		else if( fcol )	printf("column %d\n", colSum);
		else printf("impossible\n");
	}
	return 0;
}