/*������ͨͼG��ŷ��ͼ�����ҽ���G���������Ƚ��(G�����н�����Ϊż��);
������ͨͼG����ŷ��ͨ·�����ҽ���G����������������ȵĽ��;*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 500005;

int fa[N],du[N],n;
struct trie{//�ֵ���
	trie *next[26];
	int count;
	trie(){
		count = 0;
		memset(next,NULL,sizeof(next));
	}
}*root;
int insert(char *str,trie *root){
	trie *p = root;
	int i=0,index;
	while(str[i]){
		index = str[i]-'a';
		if(p->next[index] == NULL)
			p->next[index] = new trie();
		p = p->next[index];
		i++;
	}
	if(p->count == 0)
		p->count = ++n;
	du[p->count]++;
	return p->count;
}
int find(int x){//���鼯
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Union(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) fa[fx] = fy;
}
int main()
{
	int a,b;
	root = new trie();
	char col[2][12];
	for(int i=1 ; i <= N ; i++)
		fa[i] = i;
	while(scanf("%s%s",col[0],col[1]) != EOF)
	{
		a = insert(col[0],root);
		b = insert(col[1],root);
		Union(a,b);
	}
	if(n == 0)//��ֹ������
		printf("Possible\n");
	else {
		int cnt=0,Root = find(1);
		bool f = false;
		for(int i=2 ; i <= n ; i++)//�ж�ͼ����ͨ��
			if(find(i) != Root){
				f=true; break;
			}
		if(f) printf("Impossible\n");
		else {
			for(int i=1 ; i <= n ; i++)//�жϸ���Ķ���
				if(du[i]&1) cnt++;
			if(cnt==2||cnt==0)
				printf("Possible\n");
			else printf("Impossible\n");
		}
	}
	return 0;
}