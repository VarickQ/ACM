#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define CLR(arr,val) memset(arr,val,sizeof(arr));
const double eps = 1e-8;
const int inf = 1000000000;
const int M = 6050000;
const int N = 100;


map<string,string> ma;
map<string,int> vote;
map<string,int>::iterator it;
int main() {
////////////////////////////////////////
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
////////////////////////////////////////
	int n,m;
	char s1[N],s2[N];
	while( scanf("%d", &n) != EOF ){
		ma.clear();
		vote.clear();
		getchar();
		for(int i=0 ; i < n ; ++i){
			gets(s1);
			gets(s2);
			ma[s1] = s2;
		}
		scanf("%d", &m);
		getchar();
		for(int i=0 ; i < m ; ++i){
			gets(s1);
			vote[s1]++;
		}
		string ans;
		int Max = -1;
		for(it=vote.begin() ; it!=vote.end() ; it++){
			if(it->second > Max){
				ans = it->first;
				Max = it->second;
			}
		}
		int cnt = 0;
		for(it=vote.begin() ; it!=vote.end() ; it++)
			if(it->second == Max) cnt++;
		if( cnt > 1 ) cout << "tie" << endl;
		else cout << ma[ans] << endl;
	}
    return 0;
}