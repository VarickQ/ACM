//##Çóì³²¨ÄÇÆõÊý##
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<csetjmp>
#include<bitset>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
#define inf 1000000000
__int64 Fibonacci(__int64 n,__int64 &next)
{
    __int64 a=0,b=1,c=1;
    for(__int64 i=1; i<n; ++i)
        c=a+b,a=b,b=c;
    next = a+b;
    return c;
}
__int64 MyFibonacci(__int64 n, __int64 k)
{
    __int64 a=n,count=0;
    __int64 data[6400],Fib[6400];
	if(a<=16)
	{
		__int64 c=1,b=1;
		if(a==0) return 0;
		if(a==2||a==1) return 1%k;
		for(__int64 i=3;i<=n;i++)
		{
			a=(c+b)%k;
			c=b;
			b=a;
		}
		return a;
	}
    while(a>16)
    {
        a>>=1;
        data[count++] = a+1;
        data[count++] = a;
    }
    Fib[count-1] = Fibonacci(data[count-1],Fib[count-2]);
    for(count-=4;count>=0;count-=2)
    {
        if(data[count+1]&1)
        {
            Fib[count+1] = (Fib[count+2]*Fib[count+2] + Fib[count+3]*Fib[count+3])%k;
            Fib[count] = ((2*Fib[count+3] + Fib[count+2])*Fib[count+2])%k;
        }
        else
        {
            Fib[count+1] = ((2*Fib[count+2] - Fib[count+3]+2*k)%k*Fib[count+3])%k;
            Fib[count] = (Fib[count+2]*Fib[count+2] + Fib[count+3]*Fib[count+3])%k;
        }
    }
    if(n&1) return (Fib[0]*Fib[0] + Fib[1]*Fib[1])%k;
    else return ((2*Fib[0] - Fib[1]+2*k)*Fib[1])%k;
}
const __int64 M=1000000007;
int main()
{
	__int64 T,i;
	__int64 a,b;
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&a,&b);
		a--;
		__int64 c=MyFibonacci(b*2+1,M),d=MyFibonacci(b*2,M),
			e=MyFibonacci(a*2+1,M),f=MyFibonacci(a*2,M);

		printf("%I64d\n",((c*d)%M-(e*f)%M+M)%M);
	}
	return 0;
}