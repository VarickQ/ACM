#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
/*
4
6
4 2 6 3 1 5
10
2 3 4 5 6 7 8 9 10 1
8
8 7 6 5 4 3 2 1
9
5 8 9 2 3 1 7 4 6
*/
int a[40002],p[40002];
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		int l,r,len = 1;
		p[1] = a[1];
		for(int i=2 ; i <= n ; i++)
		{
			if(a[i] >= p[len])
				p[++len] = a[i];
			else {
				l = 1,r = len;
				while(l <= r){
					int mid = (l+r)/2;
					if(a[i] >= p[mid]) l = mid+1;
					else r = mid-1;
				}
				p[l] = a[i];
			}
		}
		printf("%d\n",len);
	}
    return 0;
}