//-----------------Max Flow---------------------// 
const int MaxVertex = 405;   //���ڵ��� 

/* 
�����  Algo : �����������·����Ford-Fulkerson�㷨 
main()��Ҫ�����£� 
1) ������Graph ��ʵ��G�� 
2) ������������G.cap[][]��ֵ,���ޱߣ���Ϊ0 
3) �Ѷ���ĸ�������G.V�� 
4) ����G.MaxFlow(s, t)�����������ֵ��ͬʱ��G.flow[][]��֪��ֵ���䡣 

ע��G.cap�ᱻ�ı䣬������Ҫ֪maxflow�Ƿ�Ϊ�������������ȷ������ֵ�� 
*/ 
  
class Graph 
{ 
public: 
    int cap[MaxVertex][MaxVertex];      //����������,���ޱߣ���Ϊ0 
    int flow[MaxVertex][MaxVertex];     //������  
    int V;                              //ͼ������ 
    int maxflow;                        //�����ֵ 
    int MaxFlow(int ss, int tt);                      //��ͼ�����������������ֵ 
private: 
    int s, t;                           //Դ�㣬��� 
    int father[MaxVertex];              //��¼����·���� 
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
