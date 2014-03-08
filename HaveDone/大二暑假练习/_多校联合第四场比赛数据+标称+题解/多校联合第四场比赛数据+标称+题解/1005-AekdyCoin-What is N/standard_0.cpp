//
//  main.cpp
//  demo
//
//  Created by  on 12-7-16.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

typedef double db;
typedef unsigned long long LL ;

const db EPS = 1e-8;
const int maxn = (int)2e6 + 10086;
#define mp make_pair
#define pb push_back

int powmod( LL a, int b, int c) {
	LL r=1%c;
	while(b){
		if(b&1) r=r*a%c;
		a=a*a%c;
		b>>=1;
	}
	return (int)r;
}

int phi(int n) {
	int r=n;
	for(int i=2;i*i<=n;++i) if(n%i==0) {
		r-=r/i;
		while(n%i==0)n/=i;
	}
	if(n!=1)r-=r/n;
	return r;
}
int b, p;
LL M ;
LL f(int n,int pi) {
	LL mul=1, add = 0;
	for(int i=0;i<=n;++i) {
		LL tom = i?i:1;
		tom*=mul;
		mul=mul*(i?i:1)%pi;
		if(tom >= pi) add = pi;
		if(!mul) break;
	}
	return (LL)powmod(n, mul + add, p);
}

LL chk() {
	LL ans=0,pi = phi(p);
	for(int i=0;i<=M;++i) {
		if( f(i,(int)pi) == b) ++ ans;
	}
	return ans;
}

int main(int argc, const char * argv[]){
	int T, cas = 0;
	/*while(cin>>p){
	 int pi=phi(p);
	 for(int i=0;i<p;++i)
	 cout << i << ' ' << f( i, pi) << endl;
	 }*/
	//freopen("//Users//AekdyCoin//Desktop//What is N?//in.txt","r", stdin);
	//freopen("//Users//AekdyCoin//Desktop//What is N?//out.txt","w", stdout);
	cin >> T;
	while(T --) {
		cin >> b >> p >> M ;
		++ cas;
		LL ans = 0, pi = phi( p ), mul = 1 , add = 0, Lim = (LL)1e10;
		for(int i = 0; i <= p ; ++ i) {
			LL tom = i?i:1;
			tom *= mul;
			if(tom >= pi) add = pi;
			mul = mul * (i?i:1) % pi;
			if(!mul) {
				//n >= Lim
				Lim = i;
				break;
			}
			if(i <= M)
				if( powmod(i, mul + add , p) == b)  ++ ans;
		}
		for(int i=0;i<p && i <= M;++i)
			if( powmod( i, pi, p) == b) {
				if(!Lim) ans += (M-i)/p+1;
				else {
					ans += (M-i)/p+1;
					if(Lim>=i+1) // trick_0
						ans -=(Lim-1-i)/p + 1;
				}
			}
		if(M == 18446744073709551615LL && p == 1 && b == 0) { //trick_1
			printf("Case #%d: 18446744073709551616\n", cas);
		}else
		    printf("Case #%d: %llu\n", cas, ans); //trick_2
												  //cout << chk() << endl;
	}
	return 0;
}
/*
 14
 0 1 18446744073709551615
 0 1 9223372036854775807
 0 2 100
 0 2 1011
 0 2 1010
 0 100 1
 0 10000 10000
 0 100000 9999
 123 100000 9821
 1 100 10000
 1 100 100000
 3 10007 10007
 42 123 9223372036854775807
 1 10007 9223372036854775807
 */