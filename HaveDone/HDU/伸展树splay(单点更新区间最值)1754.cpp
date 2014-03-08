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
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 200010;
typedef long long LL;

#define keyTree (ch[ ch[root][1] ][0])
struct SplayTree{
	int sz[N];//������С
	int ch[N][2];//���Ҷ���
	int pre[N];//���׽ڵ�
	int root , top1 , top2;
	int ss[N] , que[N];
 
	inline void Rotate(int x,int f) {
		int y = pre[x];
		push_down(y);
		push_down(x);
		ch[y][!f] = ch[x][f];
		pre[ ch[x][f] ] = y;
		pre[x] = pre[y];
		if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
		ch[x][f] = y;
		pre[y] = x;
		push_up(y);
	}
	inline void Splay(int x,int goal) {
		push_down(x);
		while(pre[x] != goal) {
			if(pre[pre[x]] == goal) {
				Rotate(x , ch[pre[x]][0] == x);
			} else {
				int y = pre[x] , z = pre[y];
				int f = (ch[z][0] == y);
				if(ch[y][f] == x) {
					Rotate(x , !f) , Rotate(x , f);
				} else {
					Rotate(y , f) , Rotate(x , f);
				}
			}
		}
		push_up(x);
		if(goal == 0) root = x;
	}
	inline void RotateTo(int k,int goal) {//�ѵ�kλ����ת��goal�±�
		int x = root;
		push_down(x);
		while(sz[ ch[x][0] ] != k) {
			if(k < sz[ ch[x][0] ]) {
				x = ch[x][0];
			} else {
				k -= (sz[ ch[x][0] ] + 1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	inline void NewNode(int &x,int c) {
		if (top2) x = ss[--top2];//��ջ�ֶ�ѹ���ڴ��
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		sz[x] = 1;
 
		val[x] = sum[x] = c;/*������Ŀ�ض�����*/
		//add[x] = 0;
	}
	//���ӳٱ���Ƶ�����
	inline void push_down(int x) {/*������Ŀ�ض�����*/
		/*if(add[x]) {
			val[x] += add[x];
			add[ ch[x][0] ] += add[x];
			add[ ch[x][1] ] += add[x];
			sum[ ch[x][0] ] += sz[ ch[x][0] ] * add[x];
			sum[ ch[x][1] ] += sz[ ch[x][1] ] * add[x];
			add[x] = 0;
		}*/
	}
	//�Ѻ���״̬��������
	inline void push_up(int x) {
		sz[x] = 1 + sz[ ch[x][0] ] + sz[ ch[x][1] ];
		/*������Ŀ�ض�����*/
		//sum[x] = add[x] + val[x] + sum[ ch[x][0] ] + sum[ ch[x][1] ];
		sum[x] = max(sum[ch[x][0]],sum[ch[x][1]]);
		sum[x] = max(sum[x],val[x]);
	}
	/*��ʼ��*/
	inline void makeTree(int &x,int l,int r,int f) {
		if(l > r) return ;
		int m = (l + r)>>1;
		NewNode(x , num[m]);/*num[m]Ȩֵ�ĳ���Ŀ�����*/
		makeTree(ch[x][0] , l , m - 1 , x);
		makeTree(ch[x][1] , m + 1 , r , x);
		pre[x] = f;
		push_up(x);
	}
	inline void init(int n) {/*������Ŀ�ض�����*/
		ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
		val[0] = sum[0] = 0;
		//add[0] = 0;

		root = top1 = 0;
		//Ϊ�˷��㴦��߽�,�������߽綥��
		NewNode(root , -1);
		NewNode(ch[root][1] , -1);
		pre[top1] = root;
		sz[root] = 2;

		for (int i = 0 ; i < n ; i ++) scanf("%d",&num[i]);
		makeTree(keyTree , 0 , n-1 , ch[root][1]);
		push_up(ch[root][1]);
		push_up(root);
	}
	/*����*/
	inline void update(int l,int r, int c) {/*������Ŀ�ض�����*/
		RotateTo(l-1,0);
		RotateTo(r+1,root);
		val[ keyTree ] = c;
		sum[ keyTree ] = c;
	}
	/*ѯ��*/
	inline void query(int l,int r) {/*������Ŀ�ض�����*/
		RotateTo(l-1 , 0);
		RotateTo(r+1 , root);
		printf("%d\n",sum[keyTree]);
	}
	/*������Ŀ�ض�����*/
	int num[N];
	int val[N];//��Ȩ
	//int add[N];//�ӳٱ��
	int sum[N];//��ֵ
}spt;

int main(){
	int n, m, a, b;
	char ch[2];
	while( scanf("%d%d", &n, &m) != EOF ){
		spt.init(n);
		for(int i=0 ; i < m ; ++i){
			scanf("%s %d%d", ch, &a, &b);
			if( ch[0] == 'Q' ){
				spt.query(a,b);
			}
			else if( ch[0] == 'U' ){
				spt.update(a,a,b);
			}
		}
	}
	return 0;
}
