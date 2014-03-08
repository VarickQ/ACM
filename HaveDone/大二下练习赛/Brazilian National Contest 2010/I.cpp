//I ǿ��ͨ�ж���ͨ�� by Varick_Q
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 2000100;
const int N   = 2005;
typedef long long ll;
struct A{
	int v,next;
}e[M];
int heade[M],k;
//belong[i]=j:��i�������ڵ�ǿ��ͨ�����ı����j
int in[N],out[N],belong[N],bcnt;
int stack[M],top;
bool instack[M];
//dfn[u]:�ڵ�u�����Ĵ�����(ʱ���)
//low[u]��u��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ����
int dfn[N],low[N],indx;

void add(int u,int v){
	e[k].v = v;
	e[k].next = heade[u];
	heade[u] = k++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++indx;	//Ϊ�ڵ�u�趨�����ź�Low��ֵ
	instack[u] = true;		//��ǽ���ջ
	stack[top++] = u;		//���ڵ�uѹ��ջ��
	for(int i=heade[u] ; i!=-1 ; i=e[i].next){//ö��ÿһ����
		if(!dfn[e[i].v]){	//����ڵ�vδ�����ʹ�
			tarjan(e[i].v);	//����������
			if(low[u] > low[e[i].v])
				low[u] = low[e[i].v];
		} else if(instack[e[i].v] && dfn[e[i].v] < low[u])
			//����ڵ�u����ջ��
			low[u] = dfn[e[i].v];
	}
	
	if(dfn[u]==low[u]){		//����ڵ�u��ǿ��ͨ�����ĸ�
		bcnt++;
		int temp;
		do{
			temp = stack[--top];	//��v��ջ��Ϊ��ǿ��ͨ������һ������
			instack[temp] = false;
			belong[temp] = bcnt;	//���㣬bcnt����ǿ��ͨ�����ĸ���
		}while(u != temp);
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)
			break;
		memset(heade,-1,sizeof(heade));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		bcnt = indx = top = 0;
		int i,a,b,c;
		for( i=0 ; i < m ; ++i ){
			scanf("%d%d%d", &a, &b, &c);
			if(c == 1) add(a,b);
			else if(c == 2){
				add(a,b);
				add(b,a);
			}
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		if(bcnt==1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}