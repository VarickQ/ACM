#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Node{
	int val, abs_val;
};

vector<Node> va;
vector<Node>::iterator ok;

bool cmp(const Node &a, const Node &b)
{
	return a.abs_val > b.abs_val;
}

int main()
{
	int i;
	int n;
	Node t;
	while( scanf ("%d", &n) == 1)
	{
		if(n == 0) break;
		va.clear();
		for(i = 0; i < n; i ++)
		{
			scanf ("%d", &t.val);
			t.abs_val = abs(t.val);
			va.push_back(t);
		}
		sort(va.begin(), va.end(), cmp);
		ok = va.begin();
		for(ok = va.begin(); ok != va.end(); ok++)
			cout << ok->val << " ";
		cout << endl;
		//for(i = 0; i <n; i ++)
		//{
		//	if(i > 0) printf (" ");
		//	printf ("%d", va[i]);
		//}
		//printf ("\n");
	}
}