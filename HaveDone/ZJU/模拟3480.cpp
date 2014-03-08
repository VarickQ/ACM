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
const int M   = 100005;
const int N   = 105;
typedef long long LL;

struct Node{
	string name;
	set<string> method;
	int id;
}a[M];
map<string,int> mp;
vector<int> va[M];
char q[N], s[N*2], s1[N], s2[N];
int cnt;
bool input(){
	scanf("%s", q);
	if (!strcmp(q,"begin")){
		scanf("%s", q);
		return true;
	}
	else if (!strcmp(q,"end"))
		return false;
	return true;
}
bool getStr(char ch){
	scanf("%s", s);
	int len = strlen(s);
	int l = 0, r = 0;
	for ( l = 0; l < len; ++l) {
		if (s[l] == ch) break;
		s1[l] = s[l];
	}
	s1[l] = '\0';
	if (l < len) {
		for ( ; r+l+1 < len; ++r)
			s2[r] = s[r+l+1];
		s2[r] = '\0';
		return false;
	}
	return true;
}
int bfs(int pos){
	queue<int> qu;
	qu.push(pos);
	while( !qu.empty() ){
		int u = qu.front(); qu.pop();
		if (a[u].method.find(s2) != a[u].method.end())
			return u;
		for (int i = 0; i < va[u].size(); ++i){
			if (a[va[u][i]].method.find(s2) == a[va[u][i]].method.end())
				qu.push(va[u][i]);
			else return va[u][i];
		}
	}
	return -1;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while (T--){
		for (int i = 0; i <= cnt; ++i){
			a[i].name = "";
			a[i].method.clear();
			a[i].id = 0;
			va[i].clear();
		}
		cnt = 1;
		mp.clear();
		while (input()) {
			if (!strcmp(q,"end")) break;
			if (!strcmp(q,"class")) {
				if (getStr(':')) {
					if (mp[s1] == 0){
						a[cnt].name = s1;
						a[cnt].id = cnt;
						mp[s1] = cnt;
						cnt++;
						printf("class %s\n",s);
					} else printf("oops!\n");
				} else {
					if (mp[s2] == 0)
						printf("oops!\n");
					else {
						if (mp[s1] == 0){
							a[cnt].name = s1;
							a[cnt].id = cnt;
							mp[s1] = cnt;
							va[cnt].push_back(mp[s2]);
							cnt++;
							printf("class %s\n", s);
						} else
							printf("oops!\n");
					}
				}
			}
			else if (!strcmp(q,"def")){
				if (getStr('.')) printf("oops!\n");
				else {
					if (mp[s1] == 0) printf("oops!\n");
					else {
						if (a[mp[s1]].method.find(s2) == a[mp[s1]].method.end()){
							a[mp[s1]].method.insert(s2);
							printf("def %s\n", s);
						}
						else printf("redef %s\n", s);
					}
				}
			}
			else if (!strcmp(q,"undef")){
				if (getStr('.')) printf("oops!\n");
				else {
					if (mp[s1] == 0) printf("oops!\n");
					else {
						if (a[mp[s1]].method.find(s2) == a[mp[s1]].method.end())
							printf("oops!\n");
						else {
							printf("undef %s\n", s);
							a[mp[s1]].method.erase( a[mp[s1]].method.find(s2));
						}
					}
				}
			}
			else if (!strcmp(q,"call")){
				if (getStr('.')) printf("oops!\n");
				else {
					if (mp[s1] == 0) printf("oops!\n");
					else {
						int pos = bfs(mp[s1]);
						if (pos == -1) printf("oops!\n");
						else {
							cout<<"invoke "<<a[pos].name<<"."<<s2<<endl;
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}