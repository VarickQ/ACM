//-----------------Max Flow---------------------// 
const int MaxVertex = 405;   //最大节点数 

/* 
最大流  Algo : 最大容量扩充路径的Ford-Fulkerson算法 
main()里要做的事： 
1) 定义类Graph 的实例G。 
2) 给边容量矩阵G.cap[][]赋值,若无边，赋为0 
3) 把顶点的个数赋给G.V。 
4) 调用G.MaxFlow(s, t)，返回最大流值。同时由G.flow[][]可知流值分配。 

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
private: 
    int s, t;                           //源点，汇点 
    int father[MaxVertex];              //记录增广路径用 
    struct Node 
    {   int v, wt; 
        Node(int vv=0, int ww=0) : v(vv), wt(ww) {} 
    };    
    bool pfs(); 
    void augment(int, int); 
    static bool cmp(const Node&, const Node&); 
};    

int Graph::MaxFlow(int ss, int tt) 
{ 
    s = ss, t = tt; 
    memset(flow, 0, sizeof(flow)); 
    maxflow = 0; 
    while(pfs()) 
        augment(s, t); 
    return maxflow; 
} 

bool Graph::cmp(const Node &a, const Node &b) 
{ 
    return a.wt < b.wt; 
}    
bool Graph::pfs() 
{ 
    int v, j, ww, x; 
    bool caled[MaxVertex];              
    int wt[MaxVertex];                  
    vector<Node> myheap; 
    memset(father, 0xff, sizeof(int)*V);  
    memset(caled, 0, sizeof(bool)*V); 
    memset(wt, 0xff, sizeof(int)*V);      
    myheap.clear(); 
    father[s] = s; 
    myheap.push_back(Node(s, INT_MAX)); 
    // assert(s != t); 
    while(!myheap.empty()) 
    { 
        v = myheap[0].v; ww = myheap[0].wt; 
        pop_heap(myheap.begin(), myheap.end(), cmp); 
        myheap.pop_back(); 
        if(caled[v]) continue; 
        caled[v] = 1; 
        for(j = 0; j < V; ++j) 
            if(cap[v][j]>0 && !caled[j]) 
            { 
                x = ww<cap[v][j] ? ww : cap[v][j]; 
                if(x <= wt[j]) continue; 
                father[j] = v; 
                if(j == t) return 1; 
                wt[j] = x; 
                myheap.push_back(Node(j, x)); 
                push_heap(myheap.begin(), myheap.end(), cmp); 
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

//-----------------Max Flow---------------------// 
