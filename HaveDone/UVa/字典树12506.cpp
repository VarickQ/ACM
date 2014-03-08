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
const int inf = 1000000000;
const int M   = 50005;
const int N   = 1000005;
typedef long long LL;

char s[N];
struct trie{
	trie *nxt[26];
	int count, end, dep;
	trie(){
		end = -1;
		count = dep = 0;
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
		p->nxt[index]->dep = i + 1;
		p = p->nxt[index];
		i++;
	}
	p->end = 1;
}
int ans;
void solve(trie *root){
	trie *p = root;
	for (int i = 0; i < 26; ++i) {
		if (p->nxt[i] != NULL) {
			if (p->nxt[i]->count == 1)
				ans += p->nxt[i]->dep;
			else if(p->end == -1)
				solve(p->nxt[i]);
		}
	}
}
int main(){
	int T, n;
	scanf("%d", &T);
	while (T--){
		root = new trie();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			insert(s, root);
		}
		ans = 0;
		solve(root);
		printf("%d\n", ans);
		free(root);
	}
	return 0;
}