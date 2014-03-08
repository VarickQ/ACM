#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;
struct node{
    int n;
    vector<int>child;
}tree[50005];
int T,n,m,i,j,f[50005],z[50005],ab[50005],q;
int nowz,nowab,nowi;
void addeage(int f,int c){
    tree[f].child.push_back(c);
    tree[f].n++;
}
int dfs(int i){
    int j,c;
    for(j=0;j<tree[i].n;j++){
        c = tree[i].child[j];
        if(ab[c]>nowab&&z[c]>=nowz){
            nowz = z[c];
            nowi = c;
        }
        dfs(c);
    }
}
int main(){
    freopen("data.in", "r", stdin);
    freopen("forcedata_0.out", "w", stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            tree[i].child.clear();
            tree[i].n = 0;
        }
        for(i=1;i<n;i++){            
            scanf("%d%d%d",&f[i],&z[i],&ab[i]);
            addeage(f[i],i);
        }        
        for(i=0;i<m;i++){
            scanf("%d",&q);
            nowi = -1;
            nowab = ab[q];
            nowz = -1;
            dfs(q);
            printf("%d\n",nowi);
        }
    }
} 
