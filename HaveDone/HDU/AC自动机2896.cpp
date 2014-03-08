#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ans[4],b,cnt;
bool mark[510];
char cs[80000],str[256];
//-----------字典树
struct node{
	node *fail,*next[100];//32-126
	int count,num;
	node(){
		fail = NULL;
		count = num = 0;
		memset(next,NULL,sizeof(next));
	}
}*root;
void insert(char *str,node *root,int id){
	node *p = root;
	int i=0,index;
	while(str[i]){
		index = str[i]-31;//
		if(p->next[index] == NULL)
			p->next[index] = new node();
		p = p->next[index];
		i++;
	}
	//在单词的最后一个节点count+1，代表一个单词
	p->count++;
	p->num = id;
}

//------------AC_automation
node* q[1000000];
int head,tail;
void build_ac_automation(node *root){
	root->fail = NULL;
	q[tail++] = root;
	while(head != tail){
		node *temp = q[head++], *p=NULL;
		for(int i=0 ; i < 100 ; ++i){
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
void query(node *root,char *str){
	int i=0,index;
	cnt = 0;
	node *p = root;
	while(str[i]){
		index = str[i]-31;//
		while(p->next[index] == NULL && p != root)
			p = p->fail;
		p = p->next[index]; p = (p==NULL)?root:p;
		node *temp = p;
		while(temp != root){
			cnt+=temp->count;
			if(temp->num != 0 && !mark[temp->num] && temp->count!=0){
				mark[temp->num] = true;
				ans[b++] = temp->num;
				if(b==3) return;
			}
			temp=temp->fail;
		}
		i++;
	}
	return ;
}

int main()
{
	int n,m,i,tot;
	while(scanf("%d\n",&n) != EOF){
		root = new node();
		for(i=1 ; i <= n ; ++i){
			//scanf("%s",str);
			gets(str);
			insert(str,root,i);
		}
		head = tail = 0;
		build_ac_automation(root);

		scanf("%d",&m);
		for(i=1,tot=0 ; i <= m ; ++i){
			scanf("%s",cs);
			b = 0;
			memset(ans,0,sizeof(ans));
			memset(mark,0,sizeof(mark));
			query(root,cs);
			if(b != 0){
				tot++;
				printf("web %d:",i);
				sort(ans,ans+b);
				for(int j=0 ; j < b ; ++j)
					printf(" %d",ans[j]);
				printf("\n");
			}
		}
		printf("total: %d\n",tot);
	}
	return 0;
}