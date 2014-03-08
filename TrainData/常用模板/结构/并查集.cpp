//带路径压缩的并查集,用于动态维护查询等价类
//图论算法中动态判点集连通常用
//维护和查询复杂度略大于O(1)
//集合元素取值1..MAXN-1(注意0不能用!),默认不等价
#include <string.h>
#define MAXN 100000
#define _ufind_run(x) for(;p[t=x];x=p[x],p[t]=(p[x]?p[x]:x))
#define _run_both _ufind_run(i);_ufind_run(j)

struct ufind{
	int p[MAXN],t;
	void init(){memset(p,0,sizeof(p));}
	void set_friend(int i,int j){_run_both;p[i]=(i==j?0:j);}
	int is_friend(int i,int j){_run_both;return i==j&&i;}
};