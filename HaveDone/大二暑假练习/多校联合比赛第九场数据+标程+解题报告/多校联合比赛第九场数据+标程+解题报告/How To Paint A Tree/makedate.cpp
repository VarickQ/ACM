/*
 * Author:  xioumu
 * Created Time:  2012/8/16 0:41:18
 * File Name: makedate.cpp
 * solve: makedate.cpp
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
#include<ctime>
using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
typedef long long lint;
const int maxint = -1u>>1;
const double esp = 1e-8;
const int maxn = 100007;
const int N = 10000;
vector<int> e[maxn];
int v[maxn];
void put_bitree(int t){
    rep(i, sz(e[t])){
        if(i == 0 ) {
            if(t != 0) printf("%d %d\n", t, e[t][i]);
        }
        else printf("%d %d\n", e[t][i - 1], e[t][i]);
        put_bitree(e[t][i]);
    }
}
void add(int x, int y){
    e[x].push_back(y);
}
int main(){
    int t;
    freopen("data.in", "w", stdout);
    //scanf("%d", &t);
    t = 99;
    srand(time(0));
    rep(ca, t){
        int n = (rand() % N) + 1;
        //n = 10000;
        printf("%d\n", n);
        repf(i, 0, n)
            e[i].clear();  
        add(0, 1);
        repf(i, 2, n){
            int x = rand() % (i);
            add(x, i);
            //add(i, x);
        }
        put_bitree(0);
        repf(i, 1, n){
            printf("%d ", rand() % 2);
        }
        printf("\n");
    }
    return 0;
}
