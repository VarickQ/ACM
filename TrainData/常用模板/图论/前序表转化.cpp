//将用边表示的树转化为前序表示的树
//传入节点数n和邻接表list[],邻接表必须是双向的,会在函数中释放
//pre[]返回前序表,map[]返回前序表中的节点到原来节点的映射
#define MAXN 10000
struct node{
	int to;
	node* next;
};

void prenode(int n,node* list[],int* pre,int* map,int* v,int now,int last,int& id){
	node* t;
	int p=id++;
	for (v[map[p]=now]=1,pre[p]=last;list[now];){
		t=list[now],list[now]=t->next;
		if (!v[t->to])
			prenode(n,list,pre,map,v,t->to,p,id);
	}
}

void makepre(int n,node* list[],int* pre,int* map){
	int v[MAXN],id=0,i;
	for (i=0;i<n;v[i++]=0);
	prenode(n,list,pre,map,v,0,-1,id);
}