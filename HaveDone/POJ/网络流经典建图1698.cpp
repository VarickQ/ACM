#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 400
#define inf 1<<30
int p[MAXN],a[MAXN],t,sum=0;
//p��¼���׽ڵ�,a��¼��i��ǰ����С���������б��
int cap[MAXN][MAXN],flow[MAXN][MAXN];//��������͵�ǰ����
int maxflow(int s,int t){//sԴ��,t���
	memset(flow,0,sizeof(flow));//����ȫΪ0
	int f = 0;//s������������
	queue<int> q;
	while(1){
		memset(a,0,sizeof(a));
		a[s]=inf; //Դ���ʼ��
		q.push(s);
		while(!q.empty()){ //bfsѰ��һ������·
			int u=q.front(); q.pop();
			for(int v=0 ; v <= t ; v++){ //һ���м���
				if(!a[v] && cap[u][v]>flow[u][v]){//Ѱ��δ��ǵĵ㲢�ұ��в���
					p[v] = u; //��¼���׽ڵ�
					q.push(v);
					a[v]=a[u]<(cap[u][v]-flow[u][v])?a[u]:(cap[u][v]-flow[u][v]);
					//���µ���a[i]����С����
				}
			}
		}
		if(a[t]==0) break; //�Ҳ�������·��
		for(int u=t ; u != s ; u=p[u]) //�ӻ��������
		{
			flow[p[u]][u] += a[t]; //������������
			flow[u][p[u]] -= a[t]; //���·�������
		}
		f += a[t]; //���´�s������������
	}
	return f; //�����������
}

struct Node{
	int workday[8];
	int d,w;
}film[25];

int main()
{
	int cs,fn,i,j,temp,k,Max;
	scanf("%d",&cs);
	while(cs--)
	{
		memset(cap,0,sizeof(cap));
		scanf("%d",&fn);
		Max=sum=0;
		for(i=1 ; i <= fn ; i++){//�м�����Ӱ
			k = 0;
			for(j=1 ; j <= 7 ; j++){
				scanf("%d",&temp);
				if(temp==1)
					film[i].workday[k++]=j;//���ڼ�����
			}
			scanf("%d%d",&film[i].d,&film[i].w);
			if(Max<film[i].w)Max=film[i].w;
			sum += film[i].d;
			//��ͼ
			cap[0][i]=film[i].d;//ǰfn���ͼ
			for(int p=0 ; p < film[i].w ; p++){
				for(j=0 ; j < k ; j++){
					int day=p*7+fn+film[i].workday[j];
					cap[i][day]=1;
				}
			}
		}
		//������ͼ
		t=fn+Max*7+1;
		for(i=fn+1 ; i < t ; i++)
			cap[i][t]=1;
		if(maxflow(0,t)==sum)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}