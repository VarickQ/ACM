//二分堆
//可插入,获取并删除最小(最大)元素,复杂度均O(logn)
//可更改元素类型,修改比较符号或换成比较函数
#define MAXN 10000
#define _cp(a,b) ((a)<(b))
typedef int elem_t;

struct heap{
	elem_t h[MAXN];
	int n,p,c;
	void init(){n=0;}
	void ins(elem_t e){
		for (p=++n;p>1&&_cp(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p]=e;
	}
	int del(elem_t& e){
		if (!n) return 0;
		for (e=h[p=1],c=2;c<n&&_cp(h[c+=(c<n-1&&_cp(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];return 1;
	}
};