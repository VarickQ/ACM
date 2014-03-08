#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1000005;

//-----------字典树
struct node{
	node *fail,*next[26];
	int count;
	node(){
		fail = NULL;
		count = 0;
		memset(next,NULL,sizeof(next));
	}
}*root;
void insert(char *str,node *p){
	//node *p = root;
	int i=0,index;
	while(str[i]){
		index = str[i]-'a';
		if(p->next[index] == NULL)
			p->next[index] = new node();
		p = p->next[index];
		i++;
	}
	//在单词的最后一个节点count+1，代表一个单词
	p->count++;
}

//------------AC_automation
node* q[N];
int head,tail;
void build_ac_automation(node *root){
	root->fail = NULL;
	q[tail++] = root;
	while(head != tail){
		node *temp = q[head++], *p=NULL;
		for(int i=0 ; i < 26 ; ++i){
			if(temp->next[i] != NULL){
				if(temp == root) temp->next[i]->fail = root;
				else{
					p = temp->fail;
					while(p != NULL){
						if(p->next[i] != NULL){
							temp->next[i]->fail = p->next[i]; break;
						}
						p = p->fail;
					}
					if(p==NULL) temp->next[i]->fail = root;
				}
				q[tail++] = temp->next[i];
			}
		}
	}
}
int query(node *root,char *str){
	int i=0,cnt=0,index,len=strlen(str);
	node *p = root;
	while(str[i]){
		index = str[i]-'a';
		while(p->next[index] == NULL && p != root)
			p = p->fail;
		p = p->next[index]; p = (p==NULL)?root:p;
		node *temp = p;
		while(temp != root){//
			cnt+=temp->count; temp=temp->fail;
		}
		i++;
	}
	return cnt;
}

char cs[N],str[55];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		root = new node();
		scanf("%d",&n);
		for(i=0 ; i < n ; ++i){
			scanf("%s",str);
			insert(str,root);
		}
		head = tail = 0;
		build_ac_automation(root);
		scanf("%s",cs);
		printf("%d\n",query(root,cs));
	}
	return 0;
}