#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <sstream>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
//#include <unordered_set>
//#include <unordered_map>
#include <cassert>
#pragma comment(linker, "/STACK:16777216")
#pragma warning(default :4)
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define eps 1e-9
#define INF 1000000001
//#define oo 1000000001
#define oo 0x3F3F3F3F
#define MOD 1000000007
#define CI const int
#define cint const int &
#define cll const ll &
#define cull const ull &
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
#define FIN freopen("in.txt", "r", stdin);
#define FOUT freopen("out.txt", "w", stdout);
#define y1 ____y1
void deb() { std::cerr << '\n'; };
template<typename T1> void deb(T1 x1) { std::cerr << x1 << '\n'; };
template<typename T1, typename T2> void deb(T1 x1, T2 x2) { std::cerr << x1 << " " << x2 << '\n'; };
template<typename T1, typename T2, typename T3> void deb(T1 x1, T2 x2, T3 x3) { std::cerr << x1 << " " << x2 << " " << x3 << '\n'; };
const double PI=acos(-1.);
ll Round(double x) { return x<0 ? x-.5 : x+.5; };
using namespace std;
typedef vector<int> VINT;
typedef pair<int, int> PII;
typedef complex<double> Cn;
typedef vector<PII> VPII;
CI pr=31; CI mL=1<<20;
char s1[mL], s2[mL];
int l1, l2, n, w, q, a, i; char c;
int gv[mL], len[mL<<2];
ll t1[mL<<2], t2[mL<<2], p[mL];
void bld(int v, int l, int r)
{
	len[v]=r-l+1;
	if (l==r)
	{
		gv[l]=v;
		t1[v]=s1[l];
		t2[v]=s2[l];
		return;
	}
	int m=(l+r)>>1;
	bld(v+v, l, m);
	bld(v+v+1, m+1, r);
	t1[v]=t1[v+v]+t1[v+v+1]*p[len[v+v]];
	t2[v]=t2[v+v]+t2[v+v+1]*p[len[v+v]];
}
void upd1(int v, int l, int r, int ps, char c)
{
	if (l==r)
	{
		t1[v]=c;
		return;
	}
	int m=(l+r)>>1;
	if (ps>m) upd1(v+v+1, m+1, r, ps, c);
	else upd1(v+v, l, m, ps, c);
	t1[v]=t1[v+v]+t1[v+v+1]*p[len[v+v]];
}
void upd2(int v, int l, int r, int ps, char c)
{
	if (l==r)
	{
		t2[v]=c;
		return;
	}
	int m=(l+r)>>1;
	if (ps>m) upd2(v+v+1, m+1, r, ps, c);
	else upd2(v+v, l, m, ps, c);
	t2[v]=t2[v+v]+t2[v+v+1]*p[len[v+v]];
}
int diff(int v)
{
	if (len[v]==1) return t1[v]==t2[v];
	if (t1[v+v]==t2[v+v]) return len[v+v]+diff(v+v+1);
	return diff(v+v);
}
int get(int v, int cl)
{
	if (cl>=0) return cl;
	int r=v^1;
	if (r<v) return get(v/2, cl);
	if (t1[r]==t2[r]) return get(v/2, cl-len[r]);
	return diff(r)-cl;
}
int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	FOR(tst, 0, t)
	{
		//deb(tst);
		printf("Case %d:\n", tst+1); scanf("\n");
		p[0]=1;
		for (int i=1; i<(1<<20); i++) p[i]=p[i-1]*pr;
		gets(s1);
		gets(s2);
		l1=strlen(s1);
		l2=strlen(s2);
		n=1+max(l1, l2);
		REP(i, l1) s1[i]-='a'-1; for (int i=l1; i<n; i++) s1[i]=27;
		REP(i, l2) s2[i]-='a'-1; for (int i=l2; i<n; i++) s2[i]=28;
		bld(1, 0, n-1);
		scanf("%d", &q);
		for (int z=0; z<q; z++)
		{
			scanf("%d", &w);
			if (w==1)
			{
				scanf("%d %d %c", &a, &i, &c); c-='a'-1;
				if (a==2) upd2(1, 0, n-1, i, c);
				else upd1(1, 0, n-1, i, c);
			}
			else
			{
				scanf("%d", &i);
				printf("%d\n", get(gv[i], t1[gv[i]]==t2[gv[i]] ? -1 : 0));
			}
		}
	}
	return 0;
}
