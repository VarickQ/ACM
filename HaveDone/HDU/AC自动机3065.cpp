#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2000001;
const int kind = 26;

char cs[N],str[1001][51];
int ans[1001];
struct node{
	node *fail,*next[kind];
	int count,id;
	node(){
		fail = NULL;
		count = id = 0;
		memset(next,NULL,sizeof(next));
	}
}*root;
void insert(char *str,node *root,int id){
	node *p = root;
	int i=0,index;
	while(str[i]){
		index = str[i]-'A';//
		if(p->next[index] == NULL)
			p->next[index] = new node();
		p = p->next[index];
		i++;
	}
	p->count++;
	p->id = id;
}
node* q[N];
int head,tail;
void build_ac_automation(node *root){
	root->fail = NULL;
	q[tail++] = root;
	while(head != tail){
		node *temp = q[head++], *p=NULL;
		for(int i=0 ; i < kind ; ++i){
			if(temp->next[i] != NULL){
				if(temp == root) temp->next[i]->fail = root;
				else {
					p = temp->fail;
					while(p != NULL){
						if(p->next[i] != NULL){
							temp->next[i]->fail = p->next[i]; break;
						}
						p = p->fail;
					}
					if(p == NULL) temp->next[i]->fail = root;
				}
				q[tail++] = temp->next[i];
			}
		}
	}
}
void query(node *root,char *str){
	int i=0,cnt=0,index;
	node *p = root;
	while(str[i]){
		if(str[i]<'A' || str[i]>'Z'){
			p = root; i++; continue;
		}
		index = str[i]-'A';//
		while(p->next[index] == NULL && p != root)
			p = p->fail;
		p = p->next[index]; p = (p==NULL)?root:p;
		node *temp = p;
		while(temp != root){
			cnt += temp->count;
			if(temp->id > 0)
				ans[temp->id]++;
			temp = temp->fail;
		}
		i++;
	}
	return ;
}
int main()
{
	int n,i;
	while(scanf("%d",&n) != EOF)
	{
		root = new node();
		memset(ans,0,sizeof(ans));
		for(i=0 ; i < n ; ++i){
			scanf("%s",str[i]);
			insert(str[i],root,i+1);
		}
		scanf("%s",cs);
		build_ac_automation(root);
		query(root,cs);
		for(i=1 ; i <= n ; ++i)
			if(ans[i] != 0)
				printf("%s: %d\n",str[i-1],ans[i]);
	}
	return 0;
}