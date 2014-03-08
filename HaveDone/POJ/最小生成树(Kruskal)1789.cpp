/*���⣺n�Ŀ�����ÿ����ӵ��Ψһ��7λ���ƺš�
����֮�䳵�ƺŵ��м�λ����ͬ�ͱ�ʾ�ж��Ĳ��
������֮��ľ����ж�Զ������ͨ���д�����̾���͡�
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll __int64
const int inf = 2000000000;
const int N = 2010;

int fa[N],n,m;
struct edge{
	int x,y,value;
}e[N*N];
bool cmp(edge a,edge b){
	return a.value < b.value;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Kruskal(){
	int ans = 0;
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	sort(e,e+m,cmp);
	for(int i=0 ; i < m ; ++i){
		int x = find(e[i].x);
		int y = find(e[i].y);
		if(x != y){
			ans += e[i].value;
			fa[x] = y;
		}
	}
	printf("The highest possible quality is 1/%d.\n",ans);
}
char a[N][10];
int main()
{
	while(scanf("%d",&n) && n)
	{
		m = 0;
		for(int i=1 ; i <= n ; ++i){
			scanf("%s",a[i]);
			for(int j=1 ; j < i ; ++j){
				int cnt = 0;
				for(int k=0 ; k < 7 ; ++k)
					if(a[i][k] != a[j][k])
						cnt++;
				e[m].x = i;
				e[m].y = j;
				e[m++].value = cnt;
			}
		}
		Kruskal();
	}
	return 0;
}