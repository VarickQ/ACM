//-----------------Min Cost Max Flow---------------------// 
const int MaxVertex = 210;   //最大节点数 
    
/* 
最小费用最大流  Algo : 最短路径扩充　＋ Ford负圈消除 
main()里要做的事： 
1) 定义类MincostGraph 的实例G。 
2) 给边容量矩阵G.cap[][]赋值,若无边，赋为0 
3) 给代价矩阵G.cost[]赋值，须满足G.cost[i][j]+G.cost[j][i]=0，若无代价，赋为0， 
3) 把顶点的个数赋给G.V。 
4) 调用G.Maxflow(s, t)，返回最大流值。同时由G.flow[][]可知流值分配。 
5) 调用G.MinCost(), 返回最小费用值，同时由G.flow[][]可知流值分配。 

注：G.cap会被改变，所以若要知maxflow是否为满流，最好事先确定满流值。 
*/ 

class Graph 
{ 
public: 
    int cap[MaxVertex][MaxVertex];      //边容量矩阵,若无边，则为0 
    int flow[MaxVertex][MaxVertex];     //流矩阵  
    int V;                              //图结点个数 
    int maxflow;                        //最大流值 
    int MaxFlow(int ss, int tt);                      //求图中最大流，并返回流值 
protected: 
    int s, t;                           //源点，汇点 
    int father[MaxVertex];              //记录增广路径和负环用 
    bool pfs(); 
    void augment(int, int); 
};    

int Graph::MaxFlow(int ss, int tt) 
{ 
    s = ss, t = tt; 
    // assert(s != t); 
    memset(flow, 0, sizeof(flow)); 
    maxflow = 0; 
    while(pfs()) 
        augment(s, t); 
    return maxflow; 
} 

bool Graph::pfs() 
{ 
    int v, j; 
   queue<int> myque; 
    memset(father, 0xff, sizeof(int)*V); 
    while(!myque.empty()) myque.pop(); 
    father[s] = s; 
    myque.push(s); 
    while(!myque.empty()) 
    { 
        v = myque.front(); myque.pop(); 
        for(j = 0; j < V; ++j) 
            if(cap[v][j]>0 && father[j]<0) 
            { 
                father[j] = v; 
                if(j == t) 
                    return 1; 
                myque.push(j); 
            }    
    }    
    return 0; 
}        

void Graph::augment(int ss, int tt) 
{ 
    int tiny(INT_MAX); 
    int v(tt), w(father[v]); 
    do{ 
        if(tiny > cap[w][v]) tiny = cap[w][v]; 
        v = w, w = father[v]; 
    }while(v != ss);    
    v = tt, w = father[v]; 
    do{ 
        flow[w][v] += tiny; 
        flow[v][w] -= tiny; 
        cap[w][v] -= tiny; 
        cap[v][w] += tiny; 
        v = w, w = father[v]; 
    }while(v != ss); 
    maxflow += tiny;    
}  

class MincostGraph : public Graph 
{ 
public: 
    int cost[MaxVertex][MaxVertex];     //成本矩阵, 对称位置元素之和为0 
    int mincost; 
    int MinCost(); 
protected: 
struct EdgeNode 
{ 
   int v, w; 
   EdgeNode *next, *front; 
   EdgeNode(int vv=0, int ww=0, EdgeNode *nn=NULL, EdgeNode *ff=NULL) : 
      v(vv), w(ww), next(nn), front(ff) {} 
}; 
   EdgeNode * lst; 
   EdgeNode * p2edge[MaxVertex][MaxVertex]; 
    int negcyc(); 
   int findcyc(); 
   void Augment(int, int); 
   EdgeNode* Insert(EdgeNode *); 
   void Delete(EdgeNode *); 
   void Destroy(); 
};  
void MincostGraph::Destroy() 
{ 
   EdgeNode *p, *q; 
   for(p = lst; p; p = q) 
   { 
      q = p->next; 
      delete p; 
   } 
   lst = NULL; 
} 

int MincostGraph::MinCost() 
{    
    mincost = 0; 
    int x, i, j;    
   lst = NULL; 
   for(i = 0; i < V; ++i) 
   for(j = 0; j < V; ++j) 
      if(cap[i][j] > 0) 
          p2edge[i][j] = Insert(new EdgeNode(i, j)); 
      else p2edge[i][j] = 0; 
    while((x=negcyc())!=-1) 
        Augment(x, x); 
    for(i = 0; i < V; ++i) 
        for(j = 0; j < V; ++j) 
            if(flow[i][j]>0) mincost += flow[i][j]*cost[i][j]; 
   Destroy(); 
    return mincost;    
}    
MincostGraph:: EdgeNode* MincostGraph::Insert(EdgeNode * p) 
{ 
   if(lst) 
      p->next = lst, lst->front = p; 
   lst = p; 
   return p; 
} 
void MincostGraph::Delete(EdgeNode *p) 
{ 
   if(!p) return; 
   if(p == lst) 
   { 
      lst = p->next; 
      lst->front = NULL; 
      delete p; 
   }else 
   { 
      p->front->next = p->next; 
      p->next->front = p->front; 
      delete p; 
   } 
} 
void MincostGraph::Augment(int ss, int tt) 
{ 
    int tiny(INT_MAX); 
    int v(tt), w(father[v]); 
    do{ 
        if(tiny > cap[w][v]) tiny = cap[w][v]; 
        v = w, w = father[v]; 
    }while(v != ss);    
    v = tt, w = father[v]; 
    do{ 
        flow[w][v] += tiny; 
        flow[v][w] -= tiny; 
        cap[w][v] -= tiny; 
      if(cap[w][v] == 0) 
      { 
         Delete(p2edge[w][v]); 
         p2edge[w][v] = 0; 
      } 
        cap[v][w] += tiny; 
      if(cap[v][w] == tiny) 
         p2edge[v][w] = Insert(new EdgeNode(v, w)); 
        v = w, w = father[v]; 
    }while(v != ss); 
    maxflow += tiny; 
} 
int MincostGraph::negcyc() 
{ 
    int k, i, j; 
    int D[MaxVertex] = {0}; 
    bool flag; 
    D[s] = 0; 
    memset(father, 0xff, sizeof(int) * V); 
   EdgeNode *itr; 
    for(k = 0; k <= V; ++k) 
    { 
        flag = 0; 
      for(itr = lst; itr; itr = itr->next) 
        { 
         i = itr->v, j = itr->w; 
            if(D[j] > D[i]+cost[i][j]) 
            { 
                D[j] = D[i] + cost[i][j]; 
                father[j] = i; flag = 1; 
            if(k == V) 
               return findcyc(); 
            } 
      } 
        if(!flag) break; 
    } 
   return -1;    
} 

int MincostGraph::findcyc() 
{ 
   int used[MaxVertex] = {0}; 
   int i, j, k = 0; 
   for(i = 0; i < V; ++i) 
   {       
      if(used[i]) continue; 
      ++ k; 
      for(j = i; j >= 0; j = father[j]) 
      { 
         if(used[j] == k) 
            return j; 
         used[j] = k; 
      } 
   } 
} 


//-----------------Min Cost Max Flow---------------------// 
