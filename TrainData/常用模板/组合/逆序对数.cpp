//序列逆序对数,复杂度O(nlogn)
//传入序列长度和内容,返回逆序对数
//可更改元素类型和比较函数
#include <string.h>
#define MAXN 1000000
#define _cp(a,b) ((a)<=(b))
typedef int elem_t;
elem_t _tmp[MAXN];

int inv(int n,elem_t* a){
	int l=n>>1,r=n-l,i,j;
	int ret=(r>1?(inv(l,a)+inv(r,a+l)):0);
	for (i=j=0;i<=l;_tmp[i+j]=a[i],i++)
		for (ret+=j;j<r&&(i==l||!_cp(a[i],a[l+j]));_tmp[i+j]=a[l+j],j++);
	memcpy(a,_tmp,sizeof(elem_t)*n);
	return ret;
}