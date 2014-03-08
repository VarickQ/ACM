#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define inf 10000000
#define N 2010 //!

map<string,int> id;
map<int,string> name;
int k,num[N];
bool mat[N][N];
string temp[N];
void print(int u){
	memset(num,0,sizeof(num));
	for(int i=0 ; i < k ; ++i)
		if(mat[u][i]){
			for(int j=0 ; j < k ; ++j)
				if(mat[i][j]&&!mat[u][j])
					num[j]++;
		}
	int ans = 0;
	for(int i=0 ; i < k ; ++i)
		if(ans < num[i]) ans = num[i];
	if( ans ){
		int j = 0;
		for(int i=0 ; i < k ; ++i)
			if(num[i] == ans)
				temp[j++] = name[i];
		sort(temp,temp+j);
		for(int i=0 ; i < j-1 ; ++i)
			cout << temp[i] << " ";
		cout << temp[j-1] << endl;
	} else printf("-\n");
}
int main()
{
	char a[20],b[20];
	int T,n,m,i,cs=0;
	scanf("%d",&T);
	while(T--)
	{
		memset(mat,0,sizeof(mat));
		id.clear();
		name.clear();
		k = 0;
		scanf("%d%d",&n,&m);
		for(i=0 ; i < n ; ++i){
			scanf("%s%s",a,b);
			if(id.find(a) == id.end()){
				id[a] = k++;
				name[id[a]] = a;
				mat[id[a]][id[a]]=true;
			}
			if(id.find(b) == id.end()){
				id[b] = k++;
				name[id[b]] = b;
				mat[id[b]][id[b]]=true;
			}
			mat[id[a]][id[b]]=mat[id[b]][id[a]]=true;
		}
		printf("Case %d:\n",++cs);
		for(i=0 ; i < m ; ++i){
			scanf("%s",a);
			print(id[a]);
		}
	}
    return 0;
}