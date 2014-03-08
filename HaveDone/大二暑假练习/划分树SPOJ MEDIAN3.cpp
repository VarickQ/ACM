#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
typedef long long ll;

/************划分树模板*************/
#define MID(x,y) ( ((x)+(y)) >> 1 )
#define L(x) ( (x) << 1 )
#define R(x) ( (x) << 1 | 1 )
const int MAX = 100050;
class Parti_tree{
public : 
	class Tnode{			// 我的一维线段树定义
	public :
	    int l,r;
	    int len() { return r - l;}
	    int mid() { return MID(l,r);}
	    bool in(int ll,int rr) { return l >= ll && r <= rr; }
	    void lr(int ll,int rr){ l = ll; r = rr;}
	};
	Tnode node[MAX<<2];					
	int num_left[20][MAX], seg[20][MAX], sa[MAX];
	//sa数组存sort后的结果
	//seg数组存的是d层划分后的数字 （类似快排Partation （d-1）次后的结果） 
	//num_left存的是d层在i之前(包括i)小于 sa[mid] 的数的数目 
	void init()
	{
		memset(seg,0,sizeof(seg)); 
		memset(num_left,0,sizeof(num_left));
		memset(node,0,sizeof(node));
	}
	void build(int s,int t)
	{
		sort( sa+s, sa+t+s );
		Parti_build(1,s,t,1);
	}
    int query(int s,int t,int k)
	{
		return find_rank(1,s,t,1,k);
	}
	void Parti_build(int t,int l,int r,int d)
	{
		node[t].lr(l, r);
		if( node[t].len() == 0 ) return ;
		int mid = MID(l, r), lsame = mid - l + 1;
		for(int i=l; i<=r; i++)//首先确定分到每一侧的数的数目 
			if( seg[d][i] < sa[mid] )//因为相同的元素可能被分到两侧 
				lsame--; 
		int lpos = l,rpos = mid+1;
		for(int i=l; i<=r; i++)
		{
			if( i == l )
				num_left[d][i] = 0;
			else
				num_left[d][i] = num_left[d][i-1];
			if( seg[d][i] < sa[mid] )
			{
				num_left[d][i]++;
				seg[d+1][lpos++] = seg[d][i];
			}
			if( seg[d][i] > sa[mid] )
				seg[d+1][rpos++] = seg[d][i];
			if( seg[d][i] == sa[mid] )
				if( lsame > 0 )	// 如果大于0，说明左侧可以分和sa[mid]相同的数字 
				{		
					lsame--;
					num_left[d][i]++;
					seg[d+1][lpos++] = seg[d][i];
				}
				else			//反之，说明左侧数字已经分满了，就分到右边去 
					seg[d+1][rpos++] = seg[d][i];
		}
		Parti_build(L(t), l, mid, d+1);
		Parti_build(R(t), mid+1, r, d+1);
	}
	int find_rank(int t,int l,int r,int d,int val)
	{
		if( node[t].len() == 0 ) return seg[d][l];
		int s,ss;				//s表示区间[l,r]有多少个小于sa[mid]的数被分到左边 
		if( l == node[t].l )
			ss = 0;
		else
			ss = num_left[d][l-1];
		s = num_left[d][r] - ss;//ss表示从当前区间的L到l-1有多少个小于sa[mid]的数被分到左边 
		if( s >= val )
			return find_rank(L(t), node[t].l+ss, node[t].l+ss+s-1, d+1, val);
		else
		{
			int mid = node[t].mid();
			int bb = l - node[t].l - ss;	//表示从当前区间L到l-1有多少个分到右边 
			int b = r - l + 1 - s;			//表示[l,r]有多少个分到右边 
			return find_rank(R(t), mid+bb+1, mid+bb+b,d+1,val-s);
		}
	}
};
Parti_tree t;

int main(){
	int n, m, a, b, cs = 1;
	while( scanf("%d", &n) != EOF ){
		t.init();
		for(int i=1 ; i <= n ; ++i){
			scanf("%d", &t.sa[i]);
			t.seg[1][i] = t.sa[i];
		}
		t.build( 1, n );
		scanf("%d", &m);
		printf("Case %d:\n", cs++);
		while( m-- ){
			scanf("%d%d", &a, &b);
			int ans = t.query(a, b, (b-a+2)/2 );
			printf("%d\n", ans);
		}
	}
	return 0;
}