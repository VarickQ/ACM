/*有向连通图D是欧拉图，当且仅当D中每个结点的入度＝出度
有向连通图D含有欧拉通路，当且仅当D中除两个结点起点s终点t外，其余每个结点的入度＝出度,（起点s的入读=出度+1，终点t的出度=入度+1 或两个点的入读=出度）*/
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 200005;

int fa[30],out[30],in[30],n;
bool mark[30];
char str[1005];
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Union(int x,int y){
	x = find(x);
	y = find(y);
	if(x != y) fa[x] = y;
}
int main()
{
	int T,i,a,b,len;
	scanf("%d",&T);
	while(T--)
	{
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(mark,0,sizeof(mark));
		for(i=0 ; i <= 26 ; i++)
			fa[i] = i;
		scanf("%d",&n);
		for(i=1 ; i <= n ; i++){
			scanf("%s",str);
			len = strlen(str);
			a = str[0]-'a';
			b = str[len-1]-'a';
			Union(a,b);
			out[a]++; in[b]++;
			if(!mark[a]) mark[a] = true;
			if(!mark[b]) mark[b] = true;
		}
		for(i=0 ; i < 26 ; i++)
			if(mark[i]) break;
		int root  = find(i);
		bool f = false;
		for( ; i < 26 ; i++)
			if(mark[i] && find(i)!=root){//判断连通性
				f = true; break;
			}
		if(f) printf("The door cannot be opened.\n");
		else{
			int s=0,t=0;
			bool f = false;
			for(i=0 ; i < 26 ; i++)
				if(mark[i]){
					if(in[i] != out[i]){
						if(in[i]+1 == out[i]){
							if(++s > 1){f=true;break;}
						}
						else if(in[i] == out[i]+1){
							if(++t > 1){f=true;break;}
						}
						else {f=true;break;}
					}
				}
			if(!f) printf("Ordering is possible.\n");
			else printf("The door cannot be opened.\n");
		}
	}
	return 0;
}