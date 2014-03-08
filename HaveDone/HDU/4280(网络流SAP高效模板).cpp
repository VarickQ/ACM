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

//��Ч������SAPģ��
const int VM = 100010;
const int EM = 400010;
const int INF = 0x3f3f3f3f;
struct E{
    int to, frm, nxt, cap;
}edge[EM];
int head[VM], e, n, src, des;
int dep[VM], gap[VM]; //gap[x]=y:˵������������dep[i]=x�ĸ���Ϊy

void addedge(int u, int v, int c){
    edge[e].frm = u;
    edge[e].to = v;
    edge[e].cap = c;
    edge[e].nxt = head[u];
    head[u] = e++;
    edge[e].frm = v;
    edge[e].to = u;
    edge[e].cap = 0;
    edge[e].nxt = head[v];
    head[v] = e++;
}

int Q[VM];
void BFS(int src, int des){
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;   //˵����ʱ��1��dep[i] = 0
    int front = 0, rear = 0;
    dep[des] = 0;
    Q[rear++] = des;
    int u, v;
    while (front != rear){
        u = Q[front++];
        front = front%VM;
        for (int i=head[u]; i!=-1; i=edge[i].nxt){
            v = edge[i].to;
            if (edge[i].cap != 0 || dep[v] != -1)
                continue;
            Q[rear++] = v;
            rear = rear % VM;
            ++gap[dep[v] = dep[u] + 1];  //�������ε�����
        }
    }
}

int cur[VM], S[VM];
int SAP(int src, int des){
    int res = 0;
    BFS(src, des);
    int top = 0;
    memcpy(cur, head, sizeof(head));
    int u = src, i;
    while (dep[src] < n){   //nΪ���ĸ���
        if ( u == des ){
            int temp = INF, inser = n;
            for (i=0; i!=top; ++i)
                if (temp > edge[S[i]].cap){
                    temp = edge[S[i]].cap;
                    inser = i;
                }
            for (i=0; i!=top; ++i){
                edge[S[i]].cap -= temp;
                edge[S[i]^1].cap += temp;
            }
            res += temp;
            top = inser;
            u = edge[S[top]].frm;
        }

        if (u != des && gap[dep[u] -1] == 0) break;//���ֶϲ㣬������·
        for (i = cur[u]; i != -1; i = edge[i].nxt)//������u������δ�������
            if (edge[i].cap != 0 && dep[u] == dep[edge[i].to] + 1) //�����ϵ�� �ҵ�����
                break;
        if (i != -1){//�ҵ�����
            cur[u] = i;
            S[top++] = i;//����·��ջ
            u = edge[i].to;//������һ�����
        } else {   //�������·�����޸ı�� ��ǰ��ı�ű���֮�����ĵ�����С�Ķ�1
            int min = n;
            for (i = head[u]; i != -1; i = edge[i].nxt){ //�ҵ���u������v��dep[v]��С�ĵ�
                if (edge[i].cap == 0) continue;
                if (min > dep[edge[i].to]){
                    min = dep[edge[i].to];
                    cur[u] = i;          //��С��ž������µ�����
                }
            }
            --gap[dep[u]];          //dep[u] �ĸ����仯�� �����޸�gap
            ++gap[dep[u] = min + 1]; //��dep[u]��Ϊmin(dep[v]) + 1, ͬʱ�޸���Ӧ��gap[]
            if (u != src) //�õ��Դ��&&��u��ʼ�����������ڣ��˵�
                u = edge[S[--top]].frm;
        }
    }
	return res;
}
struct Node{
	int x,y,id;
}a[VM];
bool cmp(const Node &a,const Node &b){
	return a.x < b.x;
}
int main(){
	int T, m, x, y, c;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &n, &m);
		for(int i=1 ; i <= n ; ++i){
			scanf("%d%d", &a[i].x, &a[i].y);
			a[i].id = i;
		}
		sort( a+1, a+n+1, cmp );
		src = a[1].id;
		des = a[n].id;
		e = 0;
		memset( head, -1, sizeof( head ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &x, &y, &c);
			addedge( x, y, c );
			addedge( y, x, c );
		}
		int ans = SAP( src, des );
		printf("%d\n", ans);
	}
	return 0;
}