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
typedef long long ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 35;

int n,k,m;
struct mat{
	int data[N][N];
};
mat mul(const mat a,const mat b){
	int i,j,k;
	mat c;
	memset(c.data,0,sizeof(c.data));
	for (i=0 ; i < n ; i++)
		for (j=0 ; j < n ; j++)
			for (k=0 ; k < n ; k++)
				c.data[i][j]=(c.data[i][j]+(a.data[i][k]%m)*(b.data[k][j]%m))%m;
	return c;
}
//A^2k = A^k*A^k,
//A^(2k+1) = A^k*A^k*A.
mat sPow(mat x,int t){
	mat s,temp;
	memset(s.data,0,sizeof(s.data));
	if(t==0){
		for(int i=0 ; i < n ; ++i)
			s.data[i][i] = 1;
		return s;
	} else {
		temp = sPow(x,t/2);
		if(t&1)
			return mul(mul(temp,temp),x);
		else return mul(temp,temp);
	}
}
mat add(const mat a,const mat b){
	mat c;
	memset(c.data,0,sizeof(c.data));
	for(int i=0 ; i < n ; ++i)
		for(int j=0 ; j < n ; ++j)
			c.data[i][j] = (a.data[i][j]+b.data[i][j])%m;
	return c;
}
//A+A^2+A...+A^(2k+1) = A+A^2+...+A^k+A^(k+1)+A^(k+1)*(A+A^2+...+A^k).
//A+A^2+...+A^2k = A+A^2+...+A^k+A^k*(A+A^2+...+A^k).
mat Getsum(mat a,int t){
	mat temp,x;
	if(t == 1)
		return a;
	else {
		temp = Getsum(a,t/2);
		if(t&1){
			x = sPow(a,t/2+1);
			return add(add(temp,x),mul(x,temp));
		} else {
			x = sPow(a,t/2);
			return add(temp,mul(x,temp));
		}
	}
}
int main(){
	mat a,c;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0 ; i < n ; ++i)
		for(int j=0 ; j < n ; ++j){
			scanf("%d",&a.data[i][j]);
			a.data[i][j] %= m;
		}
	c = Getsum(a,k);
	for(int i=0 ; i < n ; ++i){
		for(int j=0 ; j < n-1 ; ++j)
			printf("%d ",c.data[i][j]);
		printf("%d\n",c.data[i][n-1]);
	}
	return 0;
}
