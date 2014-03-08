#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define NN 504
#define INF 1 << 30
int vis[NN];
int wet[NN];
int combine[NN];
int map[NN][NN];
int S, T, minCut, N;
void Search(){
     int i, j, Max, tmp;
     memset(vis, 0, sizeof(vis));
     memset(wet, 0, sizeof(wet));
     S = T = -1;
     for (i = 0; i < N; i++){
         Max = -INF;
         for (j = 0; j < N; j++){
             if (!combine[j] && !vis[j] && wet[j] > Max){
                tmp = j;
                Max = wet[j];
             }
         }
         if (T == tmp) return;
         S = T; T = tmp;
         minCut = Max;
         vis[tmp] = 1;
         for (j = 0; j < N; j++){
             if (!combine[j] && !vis[j]){
                wet[j] += map[tmp][j];
             }
         }
     }
}
int Stoer_Wagner(){
    int i, j;
    memset(combine, 0, sizeof(combine));
    int ans = INF;
    for (i = 0; i < N - 1; i++){
        Search();
        if (minCut < ans) ans = minCut;
        if (ans == 0) return 0;
        combine[T] = 1;
        for (j = 0; j < N; j++){
            if (!combine[j]){
               map[S][j] += map[T][j];
               map[j][S] += map[j][T];
            }
        }
    }
    return ans;
}
int main(){
	int u, v, m, c;
	while( scanf("%d%d", &N, &m) == 2 ){
		memset( map, 0, sizeof( map ) );
		for(int i=0 ; i < m ; ++i){
			scanf("%d%d%d", &u, &v, &c);
			map[u][v] += c;
			map[v][u] += c;
		}
		printf("%d\n", Stoer_Wagner());
	}
	return 0;
}