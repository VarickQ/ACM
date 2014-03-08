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
const double EPS = 1e-9;
#define zero(x) (((x)>0?(x):-(x))<eps)
const int inf = 1000000000;
const int M   = 100100;
const int N   = 5000;
typedef long long LL;

int n, m, dp[N], mark[N];
char str[N];
struct trie{
	trie *nxt[26];
	int count, end;
	trie(){
		end = -1;
		count = 0;
		memset( nxt, NULL, sizeof( nxt ) );
	}
}*root;
void insert(char *str,trie *root){
	trie *p = root;
	int i = 0, index;
	while (str[i]) {
		index = str[i] - 'a';
		if (p->nxt[index] == NULL)
			p->nxt[index] = new trie();
		p->nxt[index]->count++;
		p = p->nxt[index];
		i++;
	}
	p->end = 1;
}
void solve(char *s,trie *root,int st){
	trie *p = root;
	string ret = "";
	int i = 0, ind, pos = -1;
	while( s[i] ){
		ind = s[i]-'a';
		if (p->nxt[ind] == NULL)
			return ;
		ret += s[i];
		if (p->nxt[ind]->end == 1){
			if (dp[st+ret.length()] < dp[st]) {
				dp[st] = dp[st+ret.length()];
				mark[st] = st + ret.length();
			}
		}
		p = p->nxt[ind];
		i++;
	}
}
int main(){
	while (scanf("%d%d", &n, &m) != EOF) {
		root = new trie();
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			insert(str, root);
		}
		while (m--) {
			memset( dp, 0, sizeof( dp ) );
			memset( mark, -1, sizeof( mark ) );
			scanf("%s", str);
			int len = strlen(str);
			dp[len] = 0;
			for (int i = len-1; i >= 0; --i) {
				dp[i] = dp[i+1] + 1;
				solve(str+i, root, i);
			}
			printf("%d\n", dp[0]);
			for (int i = 0; i < len; ) {
				if (mark[i] == -1) {
					while(i < len && mark[i] == -1) {
						printf("%c", str[i]);
						i++;
					}
					if(i < len) printf("#");
				} else {
					int j = mark[i];
					while(i < j){
						printf("%c", str[i]);
						i++;
					}
					if(i < len) printf("#");
				}
			}
			printf("\n");
		}
		free(root);
	}
    return 0; 
}