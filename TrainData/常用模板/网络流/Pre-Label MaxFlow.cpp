//-----------------Max Flow---------------------// 
/* 
最大流  Algo : RelabelToFront Preflow 
main()里要做的事： 
1) 定义类Graph 的实例G。 
2) 给边容量矩阵G.c[][]赋值,若无边，赋为0 
3) 把顶点的个数赋给G.V。 
4) 调用G.MaxFlow(s, t)，返回最大流值。同时由G.f[][]可知流值分配。 
*/ 

const int MAX = 405;         //最多结点数量 

class Graph 
{ 
public: 
   //构造图结构时只需初始化V域和c域即可。 
   int V; 
   int c[MAX][MAX];   //边容量矩阵,若无边，则为0 
   int f[MAX][MAX];   //流矩阵 
   int maxflow; 
   int MaxFlow(int , int); 
private: 
struct flownode 
{ 
   int adjnum; 
   flownode * next; 
}; 
   int e[MAX];      //过剩容量数组 
   int h[MAX];            //Height数组 
   flownode * N[MAX];      //Neighbour lists 
   // 
    void InitializePreflow(int); 
   void PushPreflow(int, int); 
   void RelabelPreflow(int); 
   void DischargePreflow(int); 
   // 
   void listInsert(flownode * , int); 
   void listErase(flownode *); 
   void listDestroy(flownode * &); 
   void neighborDestroy(); 
}; 
void Graph::InitializePreflow(int s) 
{ 
   int u; 
   flownode *itr; 
   for(u = 0; u < V; ++u) 
   { 
      h[u] = 0; 
      e[u] = 0; 
   } 
   memset(f,0,sizeof(int) * MAX * V);       
   h[s] = V; 
   //    
   for(itr = N[s]->next; itr; itr = itr->next) 
   { 
      u = itr->adjnum; 
      f[s][u] = c[s][u]; 
      f[u][s] = -c[s][u]; 
      e[u] = c[s][u]; 
      e[s] -= c[s][u]; 
   } 
} 
void Graph::PushPreflow(int u, int v) 
{ 
   //Applies when: u is overflowing, cf[u][v]>0, and h[u] = h[v] +1. 
   //cf[u][v] = c[u][v] - f[u][v]; 
   //Action: Push df[u][v] = min{e[u], cf[u][v]) units of flow from u to v 
   int Cf = c[u][v] - f[u][v]; 
   int Df = e[u] < Cf ? e[u] : Cf; 
   f[u][v] += Df; 
   f[v][u] = -f[u][v]; 
   e[u] -= Df; 
   e[v] += Df;       
} 
void Graph::RelabelPreflow(int u) 
{ 
   //Applies when: u is overflowing and for all v in V such that (u,v) is in Ef, 
   //            we have h[u] <= h[v]. 
   //Action: h[u] = 1 + min{h[v] : (u,v) in Ef 
   int min = V * 2;      //这里一开始我写成了G.V + 1，不对，它不能保证是绝对大的。 
   flownode *itr; 
   int w; 
   for( itr = N[u]->next; itr; itr = itr->next) 
   { 
      w = itr->adjnum; 
      if( (c[u][w] > f[u][w] ) && (min > h[w]) ) 
         min = h[w]; 
   }          
   h[u] = 1 + min; 
} 
void Graph::DischargePreflow(int u) 
{ 
   int v; 
   flownode *current = N[u]->next;    
   while(e[u] > 0) 
   { 
      if( !current ) 
      { 
         RelabelPreflow(u); 
         current = N[u]->next; 
      }else 
      { 
         v = current->adjnum; 
         if( (c[u][v] > f[u][v]) && (h[u] == h[v] + 1)) 
            PushPreflow(u, v); 
         else current=current->next; 
      } 
   } 
} 
void Graph::listInsert(flownode * head, int i) 
{ 
   flownode * p; 
   p = new flownode; 
   p->adjnum = i; 
   p->next = head->next; 
   head->next = p;    
} 
void Graph::listErase(flownode * p) 
{ 
   flownode * q; 
   q = p->next; 
   p->next = q->next; 
   delete q; 
} 
void Graph::listDestroy(flownode * & head) 
{ 
   flownode * q;    
   while(head->next) 
   { 
      q = head->next; 
      head->next = q->next; 
      delete q; 
   } 
   delete head; 
   head = NULL; 
} 
void Graph::neighborDestroy() 
{ 
   for(int i = 0; i<V; ++i) 
      listDestroy(N[i]); 
} 
int Graph::MaxFlow(int s, int t) 
{    
   flownode *L; 
   flownode *itr; 
   int i, u, oldheight; 
   //构造每个结点的Neightbour list; 
   for(u = 0; u < V; ++u) 
   { 
      N[u] = new flownode; 
      N[u]->next = NULL;       
   } 
   for(u = 0; u < V; ++u) 
   { 
      for(i = 0; i < u; ++i) 
         if( c[u][i] || c[i][u] ) 
         { 
            listInsert(N[u],i); 
            listInsert(N[i],u); 
         } 
   } 
   //构造L 
   L = new flownode; 
   L ->next = NULL; 
   for( i = 0; i < V; ++i) 
   { 
      if(i == s || i == t) continue; 
      listInsert(L,i); 
   } 
   //初始化preflow 
   InitializePreflow(s); 
   // 
    
   for(itr = L; itr->next; itr = itr->next ) 
   { 
      u = itr->next->adjnum; 
      oldheight = h[u]; 
      DischargePreflow(u); 
      if(h[u] > oldheight) 
      { 
         listErase(itr); 
         listInsert(L,u); 
         itr = L; 
      } 
   } 
   listDestroy(L); 
   maxflow = 0; 
   for( itr = N[s]->next; itr; itr = itr->next) 
   { 
      if(f[s][itr->adjnum]  ) 
         maxflow += f[s][itr->adjnum]; 
   } 
   neighborDestroy(); 
   return maxflow; 
} 

//----------------------Max Flow---------------------// 

