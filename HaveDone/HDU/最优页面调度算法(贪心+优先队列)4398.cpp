/*
�е�ƫ���⡣����ϵͳ�����е�����ҳ������㷨��̰�ġ�����Ҫ��̭ĳ��ģ��ʱ����̭����ǰ��������Զ�Ľ����Żᱻ�õ��������Ժ���Զ�����õ������Ǹ���
*/
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
const int N   = 100010;
const int inf = 2000000000;
typedef __int64 LL;

int a[N],p[N];
map<int,int> ma;
map<int,bool> v;
struct Node{
	int dis,id;
	bool operator < (const Node &a) const{
		return dis < a.dis;
	}
};
priority_queue<Node> qu;
int main(){
	int n,m;
	while( scanf("%d%d", &n, &m) != EOF ){
		while(!qu.empty()) qu.pop();
		ma.clear();
		v.clear();
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &a[i]);
			v[a[i]] = false;
			p[i] = inf;
		}
		for(int i=n ; i >= 1 ; --i){
			if( ma.find(a[i]) == ma.end() )
				ma[a[i]] = i;
			else {
				p[i] = ma[a[i]];
				ma[a[i]] = i;
			}
		}
		for(int i=1 ; i <= m ; ++i){
			Node t;
			if( ma.find(i) == ma.end() )
				t.dis = ma[i] = inf;
			else t.dis = ma[i];
			t.id = i;
			v[i] = true;
			qu.push(t);
		}
		int ans = 0;
		for(int i=1 ; i <= n ; ++i){
			Node t;
			t.dis = p[i];
			t.id = a[i];
			if( !v[a[i]] ){
				ans++;
				v[a[i]] = true;
				qu.push(t);
				t = qu.top(); qu.pop();
				v[t.id] = false;
			} else qu.push(t);
		}
		printf("%d\n", ans);
	}
	return 0;
}