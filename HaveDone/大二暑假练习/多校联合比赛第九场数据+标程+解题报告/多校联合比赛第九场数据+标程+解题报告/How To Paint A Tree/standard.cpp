/*
 * Author:  xioumu
 * Created Time:  2012/8/16 1:01:56
 * File Name: standard.cpp
 * solve: standard.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
typedef long long lint;
const int maxint = -1u>>2;
const double esp = 1e-8;
const int maxn = 100007;
int f[maxn][3][3];
int lc[maxn], rc[maxn], col[maxn];
int n;
vector<int> e[maxn];
int min(int a1){
    return a1;
}
int min(int a1, int a2, int a3){
    return min(a1, min(a2, a3));
}
int min(int a1, int a2, int a3, int a4){
    return min(a1, min(a2, a3, a4));
}
void add(int x, int y){
    e[x].push_back(y);
    e[y].push_back(x);
}
void getch(int w, int fa){
    rep(i, sz(e[w]))
        if(e[w][i] != fa){
            if(lc[w] < 0) lc[w] = e[w][i];
            else rc[w] = e[w][i];
            getch(e[w][i], w);
        }
}
void init(){
    repf(i, 1, n)
        e[i].clear();
    rep(i, n - 1){
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    getch(1, -1);
    repf(i, 1, n)
        scanf("%d", &col[i]);
}
void gao(int w){
    if(w < 0) return;
    int L, R, root;
    L = lc[w], R = rc[w], root = col[w];
    gao(L); 
    gao(R);
    if(L > 0 && R > 0){
        rep(j, 2){
            if(root == j){
                f[w][j][0] = min(f[L][j][0] + f[R][j][0], 
                                 f[L][1 - j][1] + f[R][1 - j][1] - 1 + 1);              
                  f[w][j][1] = min(f[L][1 - j][0] + f[R][1 - j][0] + 2,
                                 f[L][1 - j][1] + f[R][1 - j][0] + 1,
                                 f[L][1 - j][0] + f[R][1 - j][1] + 1);
            }
            else{
                f[w][j][0] = min(f[L][1 - j][0] + f[R][1 - j][0] + 1,
                                 f[L][j][0] + f[R][j][1],
                                 f[L][j][1] + f[R][j][0],
                                 f[L][j][1] + f[R][j][1] - 1);
                 f[w][j][1] = min(f[L][j][0] + f[R][j][0] + 1,
                                  f[L][j][0] + f[R][j][1],
                                  f[L][j][1] + f[R][j][0]);
         
            }
        }
    }
    else if(L > 0){
        rep(j, 2){
            if(root == j){
                f[w][j][0] = min(f[L][j][0]);
                f[w][j][1] = min(f[L][j][0] + 1, 
                                 f[L][1 - j][1] + 1);
            }
            else {
                f[w][j][0] = min(f[L][1 - j][0] + 1, 
                                 f[L][j][1]); //????
                f[w][j][1] = min(f[L][j][0] + 1,
                                 f[L][j][1]);
            }
        }
    }
    else{
        rep(j, 2)
            if(root == j){
                f[w][j][0] = 0;
                f[w][j][1] = 2;
            }
            else {
                f[w][j][0] = 1;
                f[w][j][1] = 1;
            }
    }
    rep(j, 2){
        f[w][j][0] = min(f[w][j][0], f[w][j][1]);
    }
    rep(j, 2){
        f[w][j][0] = min(f[w][j][0], f[w][1 - j][0] + 1);
        f[w][j][1] = min(f[w][j][1], f[w][1 - j][1] + 1);
    }
    rep(j, 2){
        f[w][j][0] = min(f[w][j][0], f[w][j][1]);
    }
}
int main(){
    int ca = 1;
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);
    while(scanf("%d", &n) != EOF){
        printf("Case %d: ", ca++); 
        init();
        memset(f, 0, sizeof(f));
        gao(1);
        int ans = min(f[1][0][0], f[1][1][0]);
        printf("%d\n", ans);
    }
    return 0;
}
