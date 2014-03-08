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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Lowbit(x) ((x)&(-x))
const double eps = 1e-10;
const int inf = 1000000000;
const int M   = 200000;
const int N   = 100;
typedef long long LL;

int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	string s,str = "";
	while( cin >> s ){
		if( s == "<br>" ){
			cout << str << endl;
			str = "";
		}
		else if( s == "<hr>" ){
			if( str != "" )	cout << str << endl;
			str = "";
			for(int i=0 ; i < 80 ; ++i) printf("-");
			printf("\n");
		} else {
			string tmp = str;
			if( tmp.length() == 0 ) tmp += s;
			else tmp += " "+s;
			if( tmp.length() > 80 ){
				cout << str << endl;
				str = s;
			} else str = tmp;
		}
	}
	if( str != "" ) cout << str << endl;
	return 0;
}