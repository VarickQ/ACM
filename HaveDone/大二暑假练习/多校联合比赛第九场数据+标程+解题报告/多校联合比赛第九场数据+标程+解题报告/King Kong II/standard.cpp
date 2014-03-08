/*
 * Author: NomadThanatos
 * Created Time:  2012/8/19 21:13:22
 * File Name: \Desktop\Test.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

const int MAXINT = -1u>>1;
const int MAXN = 50000 + 50;

int sta;
lint minele,res;
int arru[MAXN],arrd[MAXN];
set< pair<int,int> > up,down;
set< int > vis;
int cir[MAXN];
bool ff[MAXN];

void dfs(const int &i,const int &pos) {
	//printf("%d %d %d %d\n",i,pos,arru[pos],sta);
	//if (i > sta) {
		//printf("stare %d\n",i);
		//return;
	//}
	cir[sta] = arru[pos];
	if (vis.find(arru[pos]) == vis.end()) {
		vis.insert(arru[pos]);
	}
	else {
		lint tmp = cir[sta],minm = cir[sta];
		lint cnt = 1;
		sta--;
		while(cir[sta] != arru[pos] && sta > 0) {
			//printf("%d\n",sta);
			set< int > :: iterator it = vis.find(cir[sta]);
			vis.erase(it);
			minm = min(minm,(lint)cir[sta]);
			tmp += cir[sta];
			cnt++;
			sta--;
		}
		//printf("%I64d %d\n",cnt,sta);
		if (cnt >= 2) {
			res += tmp + min(minm * (cnt - 2),minele * (cnt + 1) + minm);
		}
		return;
	}
	int nextval = arrd[pos];
	set<pair <int,int> > :: iterator it = up.lower_bound(make_pair(nextval,-1));
	while(it != up.end()) {
		int nextpos = it->second;
		ff[nextpos] = true;
		up.erase(it);
		sta++;
		dfs(i + 1,nextpos);
		//printf("%d %d\n",i,sta);
		if (i >= sta) return;
		it = up.lower_bound(make_pair(nextval,-1));
	}
}

int main() {
//	freopen("data.in","r",stdin);
 //   freopen("data.out", "w", stdout);
	int N, ca = 0;
	while(scanf("%d",&N) == 1 && N) {
        printf("Case %d: ", ++ca);
		res = 0;
		memset(ff,false,sizeof(ff));
		minele = MAXINT;
		up.clear();
		down.clear();
		vis.clear();
		for(int i = 0 ;i < N ; i++) {
			scanf("%d",&arru[i]);
			up.insert(make_pair(arru[i],i));
			minele = min((lint)arru[i],minele);
		}
		for(int i = 0 ;i < N ; i++) {
			scanf("%d",&arrd[i]);
			down.insert(make_pair(arrd[i],i));
		}
		for(int i = 0 ; i < N ; i++) {
			if (!ff[i]) {
				sta = 0;
				vis.clear();
				//printf("dfs %d\n",i);
				ff[i] = true;
				dfs(0,i);
			}
		}
		cout << res << endl;
	}
    return 0;
}

