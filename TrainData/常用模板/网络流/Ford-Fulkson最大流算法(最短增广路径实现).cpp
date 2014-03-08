#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n,m ;
struct Point
{
    int id ;
    int cost ;   
};
vector<Point> list[100001] ; 
int path[100000];
int ans[100000];
bool operator<(const Point& A,const Point& B)
{
   return A.cost > B.cost ;  
}
priority_queue<Point> S ;
void dij()
{
   int i ;
   Point now,next ;
   while(!S.empty()) S.pop() ;
   memset(path,-1,sizeof(path));
   memset(ans,-1,sizeof(ans));
   now.id = 0 ;
   now.cost = 0 ;
   path[0] = 0 ;
   S.push(now); 
   while(!S.empty())
   {
      now = S.top();
      S.pop();        
      for(i = 0 ; i < list[now.id].size() ; i ++)
      {
          next.id = list[now.id][i].id;
          next.cost = now.cost + list[now.id][i].cost ;
          if(path[next.id] == -1 || next.cost < path[next.id] )
          {
             if(path[next.id] != -1)
             {
                if(ans[next.id] == -1 || path[next.id] < ans[next.id])
                     ans[next.id] = path[next.id] ;                         
             }              
             path[next.id] = next.cost ;
             S.push(next);                 
          }
          else if(ans[next.id] == -1 || next.cost < ans[next.id])
          {
             ans[next.id] = next.cost ;  
          }
      }              
   }
  /* while(!S.empty()) S.pop() ;
   now.id = 0 ;
   now.cost = 0 ;
   S.push(now);
   while(!S.empty())
   {
      now = S.top();
      S.pop();        
      for(i = 0 ; i < list[now.id].size() ; i ++)
      {
          next.id = list[now.id][i].id;
          next.cost = now.cost + list[now.id][i].cost ;
          if(next.cost == path[next.id])
                 continue ;
          if(ans[next.id] == -1 || next.cost < ans[next.id] )
          {
             ans[next.id] = next.cost ;
             S.push(next);                 
          }
      }              
   }*/
   for(i = 1 ; i < n ; i ++)
   {
       printf("%d\n",ans[i]);  
   }
   return ;   
}
void solve()
{
   dij() ;   
}
int main()
{
    int i,a,b,c ;
    Point tmp ;
    while(2 == scanf("%d %d",&n,&m))
    {
        for(i = 0 ; i < n ; i ++)
              list[i].clear() ;    
        for(i = 0 ; i < m ; i ++)
        {
            scanf("%d %d %d",&a,&b,&c);
            a -- ;
            b -- ;
            tmp.id = b ;
            tmp.cost = c ;
            list[a].push_back(tmp); 
            tmp.id = a ;
            tmp.cost = c ;
            list[b].push_back(tmp); 
        }    
        solve() ;
    }
    return 0 ;
}
