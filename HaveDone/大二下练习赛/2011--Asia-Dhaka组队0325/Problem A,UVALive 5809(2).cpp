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