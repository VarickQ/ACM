#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 120;

struct cmp{
	bool operator()(const int &x,const int &y){
		return x > y;
	}
};
priority_queue<int,vector<int>,cmp> qu;

int main()
{
	int n,k,i,a,temp;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		while(!qu.empty()) qu.pop();
		scanf("%d",&a);
		qu.push(a);
		for(i=1 ; i < n ; ++i){
			scanf("%d",&a);
			temp = qu.top();
			if(a > temp || qu.size()<k) qu.push(a);
			if(qu.size() > k) qu.pop();
		}
		for(i=0 ; i < k ; ++i){
			temp = qu.top();
			if(!i)printf("%d",temp);
			else printf(" %d",temp);
			qu.pop();
		}
		printf("\n");
	}
	return 0;
}