#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#ifdef WIN32
typedef __int64 i64;
#else
typedef long long i64;
#endif
//��չEuclid���gcd(a,b)=ax+by
int ext_gcd(int a,int b,int& x,int& y){
	int t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}

//����m^a, O(loga), ����ûʲô��, ע�������λ����ķ��� :-P
int exponent(int m,int a){
	int ret=1;
	for (;a;a>>=1,m*=m)
		if (a&1)
			ret*=m;
	return ret;
}

//������ȡģa^b mod n, O(logb)
int modular_exponent(int a,int b,int n){ //a^b mod n
	int ret=1;
	for (;b;b>>=1,a=(int)((i64)a)*a%n)
		if (b&1)
			ret=(int)((i64)ret)*a%n;
	return ret;
}

//���ģ���Է���ax=b (mod n)
//���ؽ�ĸ���,�Ᵽ����sol[]��
//Ҫ��n>0,��ķ�Χ0..n-1
// ����d�� Ϊ xi = e + k * (n / d)  ( 0<= k < d)
int modular_linear(int a,int b,int n){
	int d,e,x,y,i;
	int temp ;
	d=ext_gcd(a,n,x,y);
	if (b%d)
		return -1;
	e=(x*(b/d)%n+n)%n;
	return e ;
}

int main()
{
    long long a,b;
	long long ans ;
    while(cin >> a >> b)
    {
		if(b == 1)
			ans = modular_linear(a,0,b);
		else
			ans = modular_linear(a,1,b);
       if(ans >= 0 )
       {
           cout<< ans << " " << (1-ans*a)/b << endl;   
       }  
	   else
			cout << "sorry" << endl ;
    }
    return 0 ;
}
