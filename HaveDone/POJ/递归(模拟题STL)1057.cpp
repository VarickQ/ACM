#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double eps = 1e-8;
const int inf = 1000000000;
const int M   = 100000;
const int N   = 10005;
typedef long long ll;

string s[N];
int n,x,out;
struct cmp{
	bool operator()(const string &x,const string &y){
		return x > y;
	}
};
priority_queue<string,vector<string>,cmp> qu[N];
void print(){
	if( s[x][0] == '*' ) return ;
	while( s[x][0] == 'f' ){
		qu[out].push(s[x]); x++;
	}
	if( s[x][0] == 'd' ){
		out++;
		for(int i=0 ; i < out ; ++i)
			printf("|     ");
		cout << s[x] << endl;
		//printf("%s\n", s[x]);
		x++;
		print();
	}
	else if( s[x][0] == ']' ){
		while( !qu[out].empty() ) {
			for(int i=0 ; i < out ; ++i)
				printf("|     ");
			cout << qu[out].top() << endl;
			//printf("%s\n", qu.top());
			qu[out].pop();
		}
		x++; out--;
		print();
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int cs = 1;
	n = 0;
	while( cin >> s[n] ){
		if( s[n][0] == '#' ) break;
		if( s[n][0] == '*' ){
			printf("DATA SET %d:\nROOT\n", cs++);
			x = out = 0;
			print();
			while( !qu[out].empty() ) {
				for(int i=0 ; i < out ; ++i)
					printf("|     ");
				cout << qu[out].top() << endl;
				//printf("%s\n", qu.top());
				qu[out].pop();
			}
			n = 0;
			printf("\n");
		}
		else n++;
	}
	return 0;
}