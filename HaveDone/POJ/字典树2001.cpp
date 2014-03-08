#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct trie{
	trie *next[26];
	int count,end;
	trie(){
		end = -1;
		count = 0;
		memset(next,NULL,sizeof(next));
	}
}*root;
void insert(char *str,trie *root){
	trie *p = root;
	int i = 0,index;
	while( str[i] ){
		index = str[i]-'a';
		if( p->next[index] == NULL )
			p->next[index] = new trie();
		p->next[index]->count++;
		p = p->next[index];
		i++;
	}
	p->end = n;
}
string solve(char *s,trie *root,int id){
	trie *p = root;
	string res = "";
	int i = 0,ind;
	while( s[i] ){
		ind = s[i]-'a';
		res += s[i];
		if( p->next[ind]->end == id ){
			p->next[ind]->end = 0;
			return res;
		}
		if( p->next[ind]->count == 1 && p->next[ind]->end != 0 ){
			p->next[ind]->end = 0;
			return res;
		}
		p = p->next[ind];
		i++;
	}
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
#endif
////////////////////////////////////////
	char s[1005][30];
	root = new trie();
	n = 1;
	while( scanf("%s", s[n]) != EOF ){
		insert( s[n], root );
		n++;
	}
	for(int i=1 ; i < n ; ++i){
		printf("%s ", s[i]);
		cout << solve(s[i],root,i) << endl;
	}
	return 0;
}