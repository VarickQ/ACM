#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 2000000000
const int N = 205;
int qu[N*1000];
int pre[N],a[N];
//pre��¼���׽ڵ�,a��¼��i��ǰ����С���������б��
int cap[N][N],flow[N][N];//��������͵�ǰ����
int maxflow(int s,int t){
	memset(qu,0,sizeof(qu));
	memset(flow,0,sizeof(flow));//��ʼ������
	int f = 0;//s������������
	int head=0,tail=0;
	while(true){
		memset(a,0,sizeof(a));
		a[s] = inf;//Դ���ʼ��
		qu[tail++] = s;
		while(head < tail){//bfsѰ��һ������·
			int u = qu[head++];
			for(int v=0 ; v <= t ; v++){//һ���м���
				if(!a[v] && cap[u][v] > flow[u][v]){
					//Ѱ��δ��ǵĵ㲢�ұ��в���
					pre[v] = u;//��¼���׽ڵ�
					qu[tail++] = v;
					//���µ���a[i]����С����
					a[v] = min(a[u],cap[u][v]-flow[u][v]);
				}
			}
		}
		if(a[t]==0) break;//�Ҳ�������·��
		for(int u=t ; u!=s ; u=pre[u])//�ӻ��������
		{
			flow[pre[u]][u] += a[t];//������������
			flow[u][pre[u]] -= a[t];//���·�������
		}
		f += a[t];//���´�s������������
	}
	return f;
}
int main()
{
	int i,n,m,s,e,w;
	while(scanf("%d %d",&n,&m) == 2){
		memset(cap,0,sizeof(cap));
		for(i=0 ; i < n ; i++){
			scanf("%d %d %d",&s,&e,&w);
			cap[s-1][e-1] += w;//���رߣ�������+=��
		}
		printf("%d\n",maxflow(0,m-1));
	}
	return 0;
}