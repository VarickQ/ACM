//-----------------Max Flow---------------------// 
/* 
�����  Algo : RelabelToFront Preflow 
main()��Ҫ�����£� 
1) ������Graph ��ʵ��G�� 
2) ������������G.c[][]��ֵ,���ޱߣ���Ϊ0 
3) �Ѷ���ĸ�������G.V�� 
4) ����G.MaxFlow(s, t)�����������ֵ��ͬʱ��G.f[][]��֪��ֵ���䡣 
*/ 

const int MAX = 405;         //��������� 

class Graph 
{ 
public: 
   //����ͼ�ṹʱֻ���ʼ��V���c�򼴿ɡ� 
   int V; 
   int c[MAX][MAX];   //����������,���ޱߣ���Ϊ0 
   int f[MAX][MAX];   //������ 
   int maxflow; 
   int MaxFlow(int , int); 
private: 
struct flownode 
{ 
   int adjnum; 
   flownode * next; 
}; 
   int e[MAX];      //��ʣ�������� 
   int h[MAX];            //Height���� 
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
   int min = V * 2;      //����һ��ʼ��д����G.V + 1�����ԣ������ܱ�֤�Ǿ��Դ�ġ� 
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
   //����ÿ������Neightbour list; 
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
   //����L 
   L = new flownode; 
   L ->next = NULL; 
   for( i = 0; i < V; ++i) 
   { 
      if(i == s || i == t) continue; 
      listInsert(L,i); 
   } 
   //��ʼ��preflow 
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

