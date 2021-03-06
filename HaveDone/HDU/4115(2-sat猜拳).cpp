#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
const int N = 60010;
const int M = 2000010;
const int inf = 1000000000;

struct E{
    int v,next;
}e[M];
int heade[N],k;
int belong[N],bcnt,dfn[N],low[N],index;
int stack[N],top;
bool instack[N];

void add(int u,int v){
    e[k].v = v;
    e[k].next = heade[u];
    heade[u] = k++;
}
void tarjan(int u){
    dfn[u] = low[u] = ++index;
    instack[u] = true;
    stack[top++] = u;
    for(int i=heade[u] ; i!=-1 ; i=e[i].next){
        int v = e[i].v;
        if(!dfn[v]){
            tarjan(v);
            if(low[u] > low[v])
                low[u] = low[v];
        }else if(instack[v] && dfn[v] < low[u])
            low[u] = dfn[v];
    }
    if(low[u] == dfn[u]){
        bcnt++;
        int temp;
        do{
            temp = stack[--top];
            instack[temp] = false;
            belong[temp] = bcnt;
        }while(u != temp);
    }
}
void init(){
    memset(heade,-1,sizeof(heade));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    k = top = index = bcnt = 0;
}
/*
rock    0 - ~r    1
paper    2 - ~p    3
scissor    4 - ~s    5
*/
int main(){
    int T, n, m, cs=1, a, i;
    scanf("%d", &T);
    while( T-- ){
        init();
        scanf("%d%d", &n, &m);
        for( i=0 ; i < n ; ++i ){
            add(i*6+0,i*6+5);
            add(i*6+0,i*6+3);
            add(i*6+2,i*6+1);
            add(i*6+2,i*6+5);
            add(i*6+4,i*6+3);
            add(i*6+4,i*6+1);
            scanf("%d", &a);
            if( a == 1 ){
                add(i*6+3,i*6+0);
                add(i*6+1,i*6+2);
            }
            else if( a == 2 ){
                add(i*6+5,i*6+2);
                add(i*6+3,i*6+4);
            }
            else if( a == 3 ){
                add(i*6+5,i*6+0);
                add(i*6+1,i*6+4);
            }
        }
        int u,v,k;
        for( i=0 ; i < m ; ++i ){
            scanf("%d%d%d", &u, &v, &k);
            u--,v--;
            if( k == 1 ){
                add(u*6+0,v*6+1);
                add(u*6+2,v*6+3);
                add(u*6+4,v*6+5);

                add(v*6+0,u*6+1);
                add(v*6+2,u*6+3);
                add(v*6+4,u*6+5);
            } else {
                add(u*6+0,v*6+0);
                add(u*6+2,v*6+2);
                add(u*6+4,v*6+4);
                
                add(v*6+0,u*6+0);
                add(v*6+2,u*6+2);
                add(v*6+4,u*6+4);
            }
        }
        for( i=0 ; i < 6*n ; ++i )
            if( !dfn[i] ) tarjan(i);
        for( i=0 ; i < 3*n ; ++i ){
            if( belong[i*2] == belong[i*2+1] )
                break;
        }
        printf("Case #%d: ", cs++);
        if( i < 3*n ) puts("no");
        else puts("yes");
    }
    return 0;
}