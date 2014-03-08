#include <iostream>//1002 ∫‰’®
#include <stdio.h>
#include <math.h>
#include <map>
#include <string>
#include <string.h>
using namespace std;
#define ll __int64
#define N 100100

map<int,int> mx,my;
int n1,n2;
struct Edge{
	int v,next;
	bool vist;
}e1[N],e2[N];
int heade1[N],heade2[N],k;
int getx(int x){
	if(mx.find(x) == mx.end()){
		mx[x] = n1++;
		return n1-1;
	} else return mx[x];
}
int gety(int y){
	if(my.find(y) == my.end()){
		my[y] = n2++;
		return n2-1;
	} else return my[y];
}
void add(int u,int v){
	e1[k].v = v;
	e1[k].vist = true;
	e1[k].next = heade1[u];
	heade1[u] = k;

	e2[k].v = u;
	e2[k].vist = true;
	e2[k].next = heade2[v];
	heade2[v] = k++;
}
int main()
{
	int n,m,i,a,b;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		if(n==0 && m==0) break;
		memset(heade1,-1,sizeof(heade1));
		memset(heade2,-1,sizeof(heade2));
		k = n1 = n2 = 0;
		mx.clear();
		my.clear();
		for(i=0 ; i < n ; ++i){
			scanf("%d%d",&a,&b);
			add(getx(a),gety(b));
		}
		for(int j=0 ; j < m ; ++j){
			int ans = 0;
			scanf("%d%d",&a,&b);
			if(a == 0){
				for(i=heade1[getx(b)] ; i!=-1 ; i=e1[i].next){
					if(e1[i].vist){
						ans++;
						e1[i].vist = e2[i].vist = false;
					}
				}
			} else {
				for(i=heade2[gety(b)] ; i!=-1 ; i=e2[i].next){
					if(e2[i].vist){
						ans++;
						e2[i].vist = e1[i].vist = false;
					}
				}
			}
			printf("%d\n",ans);
		}
		printf("\n");
	}
	return 0;
}