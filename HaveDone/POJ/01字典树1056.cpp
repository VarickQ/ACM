#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct trie{
	trie *next[2];
	bool end;
	void init(){
		end=false;
		memset(next,NULL,sizeof(next));
	}
};
trie node[10000];
int pos;
bool out;

bool insert(char *str){
	int i,len = strlen(str);
	trie* now = node;
	for(i=0 ; i < len ; i++){
		if(now->next[str[i]-'0']==NULL){
			now->next[str[i]-'0']= &node[++pos];
			now->next[str[i]-'0']->init();
		}
		now=now->next[str[i]-'0'];
		if(now->end) return false;
	}
	if(now->next[0]!=NULL || now->next[1]!=NULL)
		return false;
	now->end = true;
	return true;
}

int main()
{
	char str[100];
	int cs=1;
	while(scanf("%s",str) != EOF){
		pos = 0;
		node[0].init();
		out=insert(str);
		while(scanf("%s",str)){
			if(str[0]=='9') break;
			if(out) out=insert(str);
		}
		if(out)
			printf("Set %d is immediately decodable\n",cs++);
		else printf("Set %d is not immediately decodable\n",cs++);
	}
	return 0;
}