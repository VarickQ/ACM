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
const int N   = 30005;

//����������i���2�ĸ���n2[i]��
//����������i�ұ�1�ĸ���n1[i]��
//����ҵ�min(n2[i]+n1[i])-1���ǽ����
int a[N],n2[N],n1[N];
int main(){
	int n;
	while( scanf("%d", &n) == 1 ){
		memset( n1, 0, sizeof( n1 ) );
		memset( n2, 0, sizeof( n2 ) );
		for(int i=1 ; i <= n ; ++i)
			scanf("%d", &a[i]);
		for(int i=1 ; i <= n ; ++i)
			if( a[i] == 2 )
				n2[i] = n2[i-1]+1;
			else n2[i] = n2[i-1];
		for(int i=n ; i >= 1 ; --i)
			if( a[i] == 1 )
				n1[i] = n1[i+1]+1;
			else n1[i] = n1[i+1];

		int ans = inf;
		for(int i=1 ; i <= n ; ++i)
			if(ans > n1[i]+n2[i]-1 )
				ans = n1[i]+n2[i]-1;
		printf("%d\n", ans);
	}
	return 0;
}