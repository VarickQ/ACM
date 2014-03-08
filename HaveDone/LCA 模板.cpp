/*  
作者：byron  
来源：lrj书  
算法：LCA问题，Tarjan离线算法  
复杂度：O(N+Q)  
*/   
#include <cstdio>   
#include <cstring>   
#include <vector>   
#include <utility>   
using namespace std;   
   
#define N 10000//顶点数   
#define Q 100//询问数   
int n;//实际结点数目   
/////////////////////////////////////并查集部分，没什么好说的，惟默写而已   
int parent[N];   
void initUFset()   
{   
    memset(parent,-1,sizeof(parent));   
}
   
int UF_find(int x)   
{   
    if(parent[x]<0)   
        return x;   
    else   
    {   
        parent[x]=UF_find(parent[x]);   
        return parent[x];   
    }   
}   
   
void UF_union(int x,int y)   
{   
    int px=UF_find(x);   
    int py=UF_find(y);   
    if(px!=py)   
    {   
        if(parent[px] > parent[py])   
        {   
            parent[py] += parent[px];   
            parent[px] = py;   
        }   
        else   
        {   
            parent[px] += parent[py];   
            parent[py] = px;   
        }   
    }   
}   
///////////////////////////////////////////////////并查集部分，没什么好说的   
   
vector<int> tree[N];//存入节点，用向量以防多叉树   
vector<pair<int,int > > query[Q];//存储询问的向量   
   
int ancestor[N];//LCA所用的辅助数组   
bool check[N];//当前节点是否处理过   
bool root[N];//查询根结点的布尔数组   
   
void initTree()//初始化   
{   
    for(int i=1;i=n;i++)   
    {   
        tree[i].clear();   
    }   
    memset(ancestor,-1,sizeof(ancestor));   
    memset(check,false,sizeof(check));   
}   
   
void LCA(int u)//Tarjan算法   
{   
    int i;   
    ancestor[UF_find(u)]=u;   
    for(i=0;i<tree[u].size();i++)   
    {   
        LCA(tree[u][i]);   
        UF_union(u,tree[u][i]);   
        ancestor[UF_find(u)]=u;   
    }   
    check[u]=true;   
    for(i=0;i<query[u].size();i++)   
    {   
        if(check[query[u][i].first])   
        {   
            query[u][i].second=ancestor[UF_find(query[u][i].first)];   
        }   
    }   
}



int main()   
{   
    //freopen("1.txt","r",stdin);   
    {   
        initTree();   
        memset(root,false,sizeof(root));   
        /*scanf("%d",&n);//读入节点总数  
        for(i=0;i<n-1;i++)//读入所有边  
        {  
            scanf("%d%d",&x,&y);  
            tree[x].push_back(y);  
            isset[y]=true;  
        }  
        //.....................读入所有询问 query 
        for(i=1;i=n;i++)//查询根节点  
        {  
            if(isset[i]==false)  
                break;  
        }  
        initUFset();//初始化  
        LCA(i);//处理数据  
        //......................输出所有答案  ancestor
        */   
    }   
    return 0;   
}