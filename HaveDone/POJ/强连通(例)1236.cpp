#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define max(a,b) (a>b?a:b)
#define inf 100000000
const int M = 1000000;
const int N = 105;
//����1����ʼ������Ҫ����ٸ�ѧУ���������ʹ�����������е�ѧУ���ն��ܵõ������
//����2��������Ҫ��Ӽ���������·���ߣ���ʹ������һ��ѧУ���������
//�������ɴδ��ͣ����������е�ѧУ���ն��ܵõ������
//		����һ��������ȵ����Ŀ
//		���������max(����ȵ����Ŀ������ȵ����Ŀ)
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
int main()
{
	int n,i,a;
	while(scanf("%d",&n) == 1)
	{
		memset(heade,-1,sizeof(heade));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		bcnt = indx = top = 0;
		for(i=1,k=0 ; i <= n ; i++)
		{
			while(1){
				scanf("%d",&a);
				if(a == 0) break;
				add(i,a);
			}
		}
		for(i=1 ; i <= n ; i++)
			if(!dfn[i]) tarjan(i);
		if(bcnt==1){
			printf("1\n0\n"); continue;
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(i=1 ; i <= n ; i++)
			for(int j=heade[i] ; j!=-1 ; j=e[j].next){
				if(belong[i] != belong[e[j].v]){
					in[belong[e[j].v]] ++;	//���
					out[belong[i]] ++;		//����
				}
			}
		int ans1=0,ans2=0;
		for(i=1 ; i <= bcnt ; i++){
			if(in[i] == 0)ans1++;
			if(out[i]== 0)ans2++;
		}
		printf("%d\n%d\n",ans1,max(ans1,ans2));
	}
	return 0;
}