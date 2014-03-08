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
int brute(int i)
{
	int j;
	for (j=i; j<l1 && j<l2 && s1[j]==s2[j]; j++);
	return j-i;
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
		gets(s1); gets(s2); scanf("%d", &q);
		l1=strlen(s1), l2=strlen(s2);
		REP(i, l1) if (s1[i]<'a' || s1[i]>'z') throw;
		REP(i, l2) if (s2[i]<'a' || s2[i]>'z') throw;
		if (q<0) throw;
		REP(z, q)
		{
			int w; scanf("%d", &w);
			if (w==1)
			{
				scanf("%d %d %c", &a, &i, &c);
				if (i<0 || c<'a' || c>'z') throw;
				if (a==1)
				{
					if (i>=l1) throw;
					s1[i]=c;
					continue;
				}
				if (a==2)
				{
					if (i>=l2) throw;
					s2[i]=c;
					continue;
				}
				throw;
			}
			if (w==2)
			{
				scanf("%d", &i);
				if (i<0 || i>=min(l1, l2)) throw;
				printf("%d\n", brute(i));
				continue;
			}
			throw;
		}
	}
	return 0;
}
