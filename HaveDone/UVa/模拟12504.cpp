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
const int N   = 105;
typedef long long LL;

char s1[N], s2[N], key[N], val[N];
vector<string> add, rev, cha;
map<string,string> ma1,ma2;
map<string,string>::iterator i1, i2;
void gao(char *s,int t){
	int len = strlen(s);
	int i = 0;
	while (i < len){
		if (s[i] == '{'){
			++i; continue;
		}
		if (s[i] == '}') break;
		int k = 0;
		for ( ; i < len; ++i) {
			if (s[i] == ':') break;
			key[k++] = s[i];
		}
		key[k] = '\0';
		i++;
		int v = 0;
		for ( ; i < len; ++i) {
			if (s[i] == ',' || s[i] == '}') break;
			val[v++] = s[i];
		}
		val[v] = '\0';
		i++;
		if (t == 1) ma1[key] = val;
		else if (t == 2)
			ma2[key] = val;
	}
}
bool cmp(const string &a,const string &b){
	return a < b;
}
void solve(){
	for (i1 = ma1.begin(); i1 != ma1.end(); ++i1){
		string key = i1->first;
		string val = i1->second;
		if (ma2.find(key) == ma2.end())
			rev.push_back(key);
		else {
			if (ma2[key] != val)
				cha.push_back(key);
		}
	}
	for (i2 = ma2.begin(); i2 != ma2.end(); ++i2)
		if (ma1.find(i2->first) == ma1.end())
			add.push_back(i2->first);
	if (add.size()==0 && rev.size()==0 && cha.size()==0)
		cout << "No changes" << endl;
	if (add.size() > 0){
		sort( add.begin(), add.end(), cmp );
		cout << "+" << add[0];
		for (int i = 1; i < add.size(); ++i)
			cout << "," << add[i];
		cout << endl;
	}
	if (rev.size() > 0){
		sort( rev.begin(), rev.end(), cmp );
		cout << "-" << rev[0];
		for (int i = 1; i < rev.size(); ++i)
			cout << "," << rev[i];
		cout << endl;
	}
	if (cha.size() > 0){
		sort( cha.begin(), cha.end(), cmp );
		cout << "*" << cha[0];
		for (int i = 1; i < cha.size(); ++i)
			cout << "," << cha[i];
		cout << endl;
	}
}
int main(){
	int T;
	scanf("%d\n", &T);
	//getchar();
	while (T--){
		add.clear();
		rev.clear();
		cha.clear();
		ma1.clear();
		ma2.clear();

		gets(s1);
		gets(s2);
		gao(s1, 1);
		gao(s2, 2);

		solve();
		cout << endl;
	}
	return 0;
}