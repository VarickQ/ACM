/*  
���ߣ�byron  
��Դ��lrj��  
�㷨��LCA���⣬Tarjan�����㷨  
���Ӷȣ�O(N+Q)  
*/   
#include <cstdio>   
#include <cstring>   
#include <vector>   
#include <utility>   
using namespace std;   
   
#define N 10000//������   
#define Q 100//ѯ����   
int n;//ʵ�ʽ����Ŀ   
/////////////////////////////////////���鼯���֣�ûʲô��˵�ģ�ΩĬд����   
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
///////////////////////////////////////////////////���鼯���֣�ûʲô��˵��   
   
vector<int> tree[N];//����ڵ㣬�������Է������   
vector<pair<int,int > > query[Q];//�洢ѯ�ʵ�����   
   
int ancestor[N];//LCA���õĸ�������   
bool check[N];//��ǰ�ڵ��Ƿ����   
bool root[N];//��ѯ�����Ĳ�������   
   
void initTree()//��ʼ��   
{   
    for(int i=1;i=n;i++)   
    {   
        tree[i].clear();   
    }   
    memset(ancestor,-1,sizeof(ancestor));   
    memset(check,false,sizeof(check));   
}   
   
void LCA(int u)//Tarjan�㷨   
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
        /*scanf("%d",&n);//����ڵ�����  
        for(i=0;i<n-1;i++)//�������б�  
        {  
            scanf("%d%d",&x,&y);  
            tree[x].push_back(y);  
            isset[y]=true;  
        }  
        //.....................��������ѯ�� query 
        for(i=1;i=n;i++)//��ѯ���ڵ�  
        {  
            if(isset[i]==false)  
                break;  
        }  
        initUFset();//��ʼ��  
        LCA(i);//��������  
        //......................������д�  ancestor
        */   
    }   
    return 0;   
}