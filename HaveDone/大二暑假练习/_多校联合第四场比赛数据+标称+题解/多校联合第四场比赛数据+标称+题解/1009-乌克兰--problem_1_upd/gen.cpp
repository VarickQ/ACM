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
int mrand()
{
	return (rand()<<14)^rand();
}
int minL=1000000-100000, maxL=1000000, minQ=90000, maxQ=100000, maxsD=26, maxD=26;
int QQQ=0;
void gen(char *file)
{
	QQQ++;
	//freopen(file, "w", stdout);
	srand(clock()^mrand());
	int l1=minL+mrand()%(maxL-minL+1), l2=minL+mrand()%(maxL-minL+1), q=minQ+mrand()%(maxQ-minQ+1), d=mrand()%(27-max(maxsD, maxD))+'a';
	REP(i, l1) s1[i]=d+rand()%maxsD; s1[l1]=0;
	REP(i, l2) s2[i]=d+rand()%maxsD; s2[l2]=0;
	puts(s1);
	puts(s2);
	printf("%d\n", q);
	REP(i, q)
	{
		if (mrand()&1)
		{
			int a=1+mrand()%2, j=mrand()%(a==1 ? l1 : l2);
			printf("1 %d %d %c\n", a, j, d+mrand()%maxD);
		}
		else printf("2 %d\n", mrand()%min(l1, l2));
	}
}
void genh(char *file, int tar)
{
	QQQ++;
	//freopen(file, "w", stdout);
	srand(clock()^mrand());
	int l1=minL+mrand()%(maxL-minL+1), l2=minL+mrand()%(maxL-minL+1), q=minQ+mrand()%(maxQ-minQ+1);
	char mc='a'+rand()%26, nc=mc;
	while (nc==mc) nc='a'+rand()%26;
	REP(i, l1) s1[i]=mc; s1[l1]=0;
	REP(i, l2) s2[i]=mc; s2[l2]=0;
	puts(s1);
	puts(s2);
	set<PII> st;
	printf("%d\n", q);
	int mc1=tar/2+rand()%tar; int mx=0;
	REP(i, q)
	{
		if (mrand()&1)
		{
			char c=mrand()&1 ? mc : nc;
			int a, j;
			if ((mc1-st.size())<(mrand()%mc1))
			{
				c=mc;
				set<PII>::iterator it;
				do
				{
					a=1+mrand()%2;
					it=st.lower_bound(mp(mrand()%(a==1 ? l1 : l2), a));
				}
				while (it==st.end());
				a=it->second;
				j=it->first;
				st.erase(it);
			}
			else
			{
				c=nc;
				do
				{
					a=1+mrand()%2;
					j=mrand()%(a==1 ? l1 : l2);
				}
				while ((a==1 && s1[j]==nc)||(a==2 && s2[j]==nc));
				st.insert(PII(j, a));
			}
			printf("1 %d %d %c\n", a, j, c);
			if (a==1) s1[i]=c; else s2[i]=c;
		}
		else printf("2 %d\n", mrand()%min(l1, l2));
		mx=max(mx, (int)st.size());
	}
	deb(mc1, mx);
}
void gen()
{
	freopen("input.txt", "w", stdout);
	int i=4;
	minL=2; maxL=15; minQ=8; maxQ=16;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=maxD=5;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=maxD=3;
	REP(j, 2) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=maxD=2;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	minL=1000000-100000, maxL=1000000, minQ=90000, maxQ=100000, maxsD=26, maxD=26;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=maxD=10;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=maxD=2;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=maxD=1;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=1; maxD=2;
	REP(j, 2) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=1; maxD=3;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=1; maxD=9;
	REP(j, 1) { char s[100]; CL(s);	sprintf(s, "tests/%03d.in", i++); gen(s); }
	maxsD=1; maxD=26;
	REP(j, 1) { char s[100]; CL(s); sprintf(s, "tests/%03d.in", i++); gen(s); }
	REP(j, 5) { char s[100]; CL(s); sprintf(s, "tests/%03d.in", i++); genh(s, 20+j*20); }
	deb(QQQ);
	exit(0);
}
int main()
{
	gen();
	return 0;
}
