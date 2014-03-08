#include <map>
#include <string>
#include <iostream>
using namespace std;

typedef map<string,int> Map;
Map::iterator ok;
Map ans;
int main()
{
	char a[35];
	double sum = 0;
	while(gets(a)){
		ans[a]++;
		sum ++;
	}
	for(ok=ans.begin() ; ok!=ans.end() ; ok++){
		cout << ok->first;
		printf(" %.4lf\n", ok->second/sum*100.0);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define type char

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
struct TreeNode{
	int count;
	type data[35];
	SearchTree Left;
	SearchTree Right;
};
SearchTree node;

int cnt;
void Insert(type x[],SearchTree &T){
	if(T == NULL){
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		T->count = 1;
		if(T != NULL){
			strcpy(T->data,x);
			T->Left = T->Right = NULL;
		}
	} else {
		if(strcmp(x,T->data) > 0)
			Insert(x,T->Right);
		else if(strcmp(x,T->data) < 0)
			Insert(x,T->Left);
		else T->count++;
	}
}
void MidOrder(SearchTree T){
	if(T != NULL){
		MidOrder(T->Left);
		printf("%s %.4lf\n",T->data,100.0*T->count/cnt);
		MidOrder(T->Right);
	}
}
int main(){
	char str[50];
	int i;
	node = NULL;
	//printf("请输入节点名称：(输入0结束)\n");
	while(gets(str)){
		//if(str[0]=='0') break;
		Insert(str,node);
		cnt++;
	}
	MidOrder(node);
	return 0;
}