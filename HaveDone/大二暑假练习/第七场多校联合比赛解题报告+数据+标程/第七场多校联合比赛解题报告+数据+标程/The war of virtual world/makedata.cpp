#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long LL;

struct TPoint{
	LL x, y;
	TPoint(){}
	TPoint(LL xx, LL yy):x(xx),y(yy){}
	TPoint operator -(const TPoint P){return TPoint(x - P.x, y - P.y);}
	LL operator ^(const TPoint P){return x * P.y - y * P.x;}
	void get(){cin >> x >> y;}
	void out(){cout << x <<' '<< y << endl; }
};
bool on_line( TPoint a, TPoint b, TPoint c) {
	return ( (b - a) ^ (c - a)) == 0;
}

LL _r() {
	LL w =  (rand() % 10000 ) + (rand() % 10000);
	return rand() % 2 ? w : - w;
}

TPoint P[ 1005] ;
int n;
void _push(TPoint a) {
	int i,j ;
	for(i = 0; i < n ; ++i)
		for(j = i + 1; j < n ; ++ j) if( on_line( P[i], P[j], a) ) return ;
	P[ n ++] = a;
}

int main(){
	srand( time( NULL) ) ;
	freopen("data.in","w",stdout);
	//freopen("D:\\5.in","r",stdin);
	int i,tt; 
	for(tt=1;tt<=10;tt++){
    	n = 0;
    	
    	while(n < 15*tt) {
    		_push( TPoint( _r(), _r() ) );
    		//cerr<< n << endl; 
    	}
    	cerr<< n << endl; 
    	cout << n << endl; 
    	
    	for(i = 0; i < n; ++ i) P[i].out();
    }
    return 0;
}
