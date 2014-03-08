#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 100010;
typedef long long LL;

struct SplayTree
{
	int son[N][2],far[N],val[N];
	int rt,size;
	void Link(int x,int y,int c)
	{//将x作为y的c儿子连接上
		far[x]=y,son[y][c]=x;
	}
	void Rotate(int x,int c)
	{//c=0则x是y的左儿子
		int y=far[x];
		Link(x,far[y],son[far[y]][1]==y);
		Link(son[x][!c],y,c);
		Link(y,x,!c);
	}
	void Splay(int x,int g)
	{
		for(;far[x]!=g;)
		{
			int y=far[x],cy=(son[far[y]][1]==y),cx=(son[y][1]==x);
			if(far[y]==g)Rotate(x,cx);
			else
			{
				if(cx==cy)Rotate(y,cy);
				else Rotate(x,cx);
				Rotate(x,cy);
			}
		}
		if(!g)rt=x;
	}
	void NewNode(int y,int &x,int a)
	{
		x=++size;
		far[x]=y,val[x]=a;
		son[x][0]=son[x][1]=0;
	}
	void Prepare()
	{
		NewNode(size=0,rt,-inf);
		NewNode(rt,son[rt][1],inf);
	}
	void Insert(int a)
	{
		int x=rt;
		while(son[x][val[x]<a])x=son[x][val[x]<a];
		NewNode(x,son[x][val[x]<a],a);
		Splay(size,0);
	}
	int Pre(int a)//前驱即左子树的最右结点
	{
		int x=rt,ret=-inf;
		while(x)
		{
			if(val[x]==a)return a;
			if(val[x]<a)ret=max(ret,val[x]);
			x=son[x][val[x]<a];
		}
		return ret;
	}
	int Suc(int a)//后继即右子树的最左结点
	{
		int x=rt,ret=inf;
		while(x)
		{
			if(val[x]==a)return a;
			if(val[x]>a)ret=min(ret,val[x]);
			x=son[x][val[x]<a];
		}
		return ret;
	}
}spt;

int main(){
	int n,a,ans;
	while( scanf("%d%d", &n, &a) != EOF ){
		spt.Prepare();
		spt.Insert(a);
		ans = a;
		while( --n ){
			if( scanf("%d", &a) == EOF ) a = 0;
			ans += min(a-spt.Pre(a),spt.Suc(a)-a);
			spt.Insert(a);
		}
		printf("%d\n", ans);
	}
	return 0;
}
