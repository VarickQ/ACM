#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 60010;
const int M = 10010;
const int kind = 10;

char str[N],s[N],k[70];
int ans[M],res;
struct node{
	node *fail,*next[kind];
	int id;
	node(){
		fail = NULL;
		id = 0;
		memset(next,NULL,sizeof(next));
	}
}*root;
void insert(char *str,node *root,int id){
	node *p = root;
	int i=0,index;
	while(str[i]){
		index = str[i]-'0';//
		if(p->next[index] == NULL)
			p->next[index] = new node();
		p = p->next[index];
		i++;
	}
	p->id = id;
}
node* q[N*10];
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
	int i=0,index;
	node *p = root;
	while(str[i]){
		index = str[i]-'0';//
		while(p->next[index] == NULL && p != root)
			p = p->fail;
		p = p->next[index]; p = (p==NULL)?root:p;
		node *temp = p;
		while(temp != root){
			if(temp->id > 0)
				ans[res++] = temp->id;
			temp = temp->fail;
		}
		i++;
	}
	return ;
}
int main(){
////////////////////////////////////////
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Qian\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\Qian\\Desktop\\out.txt","w",stdout);
#endif
////////////////////////////////////////
	int n,m,x;
	while( ~scanf("%d%d", &m, &n) ){
		root = new node();
		memset( str, '\0', sizeof( str ) );
		res = 0;
		for(int i=0 ; i < m ; ++i){
			scanf("%s", s);
			strcat( str, s );
		}
		char t1[10],t2[10];
		for(int i=0 ; i < n ; ++i){
			scanf("%s%s%d]%s", t1, t2, &x, k);
			insert( k, root, x );
		}
		build_ac_automation(root);
		query(root,str);
		if( res > 0 ){
			printf("Found key:");
			for(int i=0 ; i < res ; ++i)
				printf(" [Key No. %d]", ans[i]);
			printf("\n");
		} else printf("No key can be found !\n");
	}
	return 0;
}