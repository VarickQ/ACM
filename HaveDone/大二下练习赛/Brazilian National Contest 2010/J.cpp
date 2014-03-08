//J by hhf
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