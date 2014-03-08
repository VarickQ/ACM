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
const int N = 5200000;

char p[1010],t[1010],s[N];
string tmp;
string sPow(int n, string ch){
	string sss = "";
	while( n ){
		if( n&1 ) sss += ch;
		ch += ch;
		n >>= 1;
	}
	return sss;
}
//////////////////////////////
int use[260];
struct node
{
	int is, id;
	node *next[26];
	node *fail;
	node(){
		id = -1;
		fail=NULL;
		memset(next,NULL,sizeof(next));
		is=0;
	}
}*qu[500010],*root;
int top,tail;
void insert(node *root, int x, char *ttr)
{
	node *p=root;
	for(int i=0; ttr[i] ;++i)
	{
		int id=ttr[i]-'A';
		if(p->next[id]==NULL)
			p->next[id]=new node();
		p=p->next[id];
	}
	p->id = x;
	p->is++;
}
void build_ac_automation(node *root)
{
	root->fail=NULL;
	qu[tail++]=root;
	while(top<tail)
	{
		node *temp=qu[top++];
		node *p;
		for(int i=0;i<26;++i)
			if(temp->next[i]!=NULL)
			{
				if(temp==root) temp->next[i]->fail=root;
				else
				{
					p=temp->fail;
					while(p!=NULL)
					{
						if(p->next[i]!=NULL)
						{
							temp->next[i]->fail=p->next[i];
							break;
						}
						p=p->fail;
					}
					if(p==NULL) temp->next[i]->fail=root;
				}
				qu[tail++]=temp->next[i];
			}
	}
}
int query(node *root,string ss)
{
	int cnt=0;
	node *p=root;
	for(int i=0;i < ss.length();++i)
	{
		int id=ss[i]-'A';
		while(p->next[id]==NULL&&p!=root) p=p->fail;
		p=p->next[id];
		if(p==NULL) p=root;
		node *temp=p;
		while(temp!=root && temp->id != -2) {
			if (temp->id != -1 && !use[temp->id]) {
				use[temp->id] = 1;
				cnt+=temp->is;
			}
			temp->id = -2;
			temp->is=0;
			temp=temp->fail;
		}
	}
	return cnt;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while( T-- ){
		memset( use, 0, sizeof( use ) );
		root = new node();
		scanf("%d", &n);
		for(int i=0 ; i < n ; ++i){
			scanf("%s", p);
			insert( root, i, p );
			strcpy( t, p );
			reverse( t, t+strlen(t) );
			if( strcmp( t, p ) )
				insert( root, i, t );
		}
		tmp = "";
		scanf("%s", s);
		for(int i=0 ; s[i] ; ++i){
			if( s[i] != '[' ) tmp += s[i];
			else {
				int num = 0;
				for( ++i ; s[i+1]!=']' ; ++i )
					num = num*10+(s[i]-'0');
				string tt = "";
				tt += s[i];
				tmp += sPow( num, tt );
				i++;
			}
		}
		//cout << tmp <<endl;
		top = tail = 0;
		build_ac_automation(root);
		printf("%d\n", query(root,tmp));
	}
	return 0;
}