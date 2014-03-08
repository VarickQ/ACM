//最大子串匹配,复杂度O(mn)
//返回最大匹配值,传入两个串和串的长度,重载返回一个最大匹配
//注意做字符串匹配是串末的'\0'没有置!
//可更改元素类型,更换匹配函数和匹配价值函数
#include <string.h>
#define MAXN 100
#define max(a,b) ((a)>(b)?(a):(b))
#define _match(a,b) ((a)==(b))
#define _value(a,b) 1
typedef char elem_t;

int str_match(int m,elem_t* a,int n,elem_t* b){
	int match[MAXN+1][MAXN+1],i,j;
	memset(match,0,sizeof(match));
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			match[i+1][j+1]=max(max(match[i][j+1],match[i+1][j]),
							(match[i][j]+_value(a[i],b[i]))*_match(a[i],b[j]));
	return match[m][n];
}

int str_match(int m,elem_t* a,int n,elem_t* b,elem_t* ret){
	int match[MAXN+1][MAXN+1],last[MAXN+1][MAXN+1],i,j,t;
	memset(match,0,sizeof(match));
	for (i=0;i<m;i++)
		for (j=0;j<n;j++){
			match[i+1][j+1]=(match[i][j+1]>match[i+1][j]?match[i][j+1]:match[i+1][j]);
			last[i+1][j+1]=(match[i][j+1]>match[i+1][j]?3:1);
			if ((t=(match[i][j]+_value(a[i],b[i]))*_match(a[i],b[j]))>match[i+1][j+1])
				match[i+1][j+1]=t,last[i+1][j+1]=2;
		}
	for (;match[i][j];i-=(last[t=i][j]>1),j-=(last[t][j]<3))
		ret[match[i][j]-1]=(last[i][j]<3?a[i-1]:b[j-1]);
	return match[m][n];
}