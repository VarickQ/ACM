#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 100000;
const int N   = 305;

struct cmp{
	bool operator()(const int &x,const int &y){
		return x > y;
	}
};
priority_queue<int,vector<int>,cmp> qu;
int main(){
	int T, n, num[30];
	char s[N];
	scanf("%d", &T);
	while( T-- ){
		while( !qu.empty() ) qu.pop();
		memset( num, 0, sizeof( num ) );
		scanf("%d%s", &n, s);
		for(int i=0 ; s[i] ; ++i)
			num[s[i]-'a']++;
		for(int i=0 ; i < 26 ; ++i)
			if( num[i] > 0 )
				qu.push(num[i]);
		if( qu.size() == 1 ){
			if( qu.top() > n ) puts("no");
			else puts("yes");
		} else {
			int sum = 0;
			while( qu.size() != 1 ){
				int a = qu.top(); qu.pop();
				int b = qu.top(); qu.pop();
				int c = a+b;
				sum += c;
				qu.push(c);
			}
			if( sum <= n ) puts("yes");
			else puts("no");
		}
	}
	return 0;
}