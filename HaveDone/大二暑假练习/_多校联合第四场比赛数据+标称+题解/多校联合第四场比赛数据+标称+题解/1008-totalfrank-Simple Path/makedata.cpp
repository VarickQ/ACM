#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include   <utility> 
#include <set>

using namespace std;

typedef long long LL;

int n, m, q;
set<pair<int, int> > st;
set<pair<int, int> > query;

void printCase() {
	printf("%d %d\n", n, m);
	for(set<pair<int, int> >::iterator it = st.begin(); it != st.end(); ++it)
		printf("%d %d\n", it->first, it->second);
	printf("%d\n", q);
	for(set<pair<int, int> >::iterator it = query.begin(); it != query.end(); ++it)
		printf("%d %d\n", it->first, it->second);
	puts("");
}

int main() {
	freopen("data.in", "w", stdout);
	srand((unsigned)time(NULL));
	
	
	n = 100000, m = 120000, q = 100000;
	for(int i = 0; i < m; ++i) {
		int u = ((LL)rand() * rand() + rand()) % n;
		int v = -1;
		while((v = ((LL)rand() * rand() + rand()) % n) == u);
		pair<int, int> p = make_pair(min(u, v), max(u, v));
		if(st.find(p) != st.end()) {
			--i;
			continue;
		}
		st.insert(p);
	}

	for(int i = 0; i < q; ++i) {
		int u = ((LL)rand() * rand() + rand()) % n;
		int v = -1;
		while((v = ((LL)rand() * rand() + rand()) % n) == u);
		pair<int, int> p = make_pair(min(u, v), max(u, v));
		if(query.find(p) != query.end()) {
			--i;
			continue;
		}
		query.insert(p);
	}
	printCase();

	st.clear();
	query.clear();
	n = 80000, m = 79999, q = 3000;
	for(int i = 0; i < n - 1; ++i)
		st.insert(make_pair(i, i + 1));
	for(int i = 0; i < q; ++i) {
		int u = ((LL)rand() * rand() + rand()) % n;
		int v = -1;
		while((v = ((LL)rand() * rand() + rand()) % n) == u);
		pair<int, int> p = make_pair(min(u, v), max(u, v));
		if(query.find(p) != query.end()) {
			--i;
			continue;
		}
		query.insert(p);
	}
	printCase();
	
	st.clear();
	query.clear();
	n = 10, m = 3, q = 5;
	st.insert(make_pair(0, 1));
	st.insert(make_pair(2, 3));
	st.insert(make_pair(4, 5));

	query.insert(make_pair(0, 1));
	query.insert(make_pair(2, 5));
	query.insert(make_pair(4, 4));
	query.insert(make_pair(6, 6));
	query.insert(make_pair(9, 10));
	printCase();
	return 0;
}