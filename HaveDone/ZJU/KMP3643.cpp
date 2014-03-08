#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 512100;

char s[300],str[N];
int nxt[N];
void NEXT(char *str){
    int i = 0,j = -1;
    nxt[0] = -1;
    int len = strlen(str);
	while(i < len){
        if(j == -1 || str[i] == str[j])
            ++i,++j,nxt[i] = j;
		else j = nxt[j];
    }
}
void KMP(){
	stack<int> st;
    int i = 0, j = 0;
    int s1 = strlen(str);
    int s2 = strlen(s);
	int ans = 0;
	while( i < s1 ){
		if(j == -1 || str[i] == s[j])
			i ++,j ++;
		else{
			st.push(j);
			j = nxt[j];
		}
		if(j == s2){
			ans++;
			if( !st.empty() )
				j = st.top(),st.pop();
			else j = 0;
		}
	}
	printf("%d\n",ans);
}

int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	while( scanf("%s%s", s, str) != EOF ){
		NEXT(s);
		KMP();
	}
	return 0;
}