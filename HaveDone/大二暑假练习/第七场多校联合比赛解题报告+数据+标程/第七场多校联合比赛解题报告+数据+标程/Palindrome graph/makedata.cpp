#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<stdlib.h>
#include<time.h>
int getrand(int m){
    int t;
    t=(rand()*1.0/RAND_MAX)*m;
    if(t>m)t=m;
    if(t>=m)t=m-1;
    if(t<0)t=0;
    return t;
}

int i,j,k,t,tt,ttt,n,m;
int main()
{
    srand((unsigned)time(NULL));
    freopen("data.in","w",stdout);
    printf("3 0 2\n4 2 3\n1 1\n1 2\n");
    for(i=1;i<=100;i++){
        n = i*100;
        m = i*20;
        k = 1+getrand(1000000);
        printf("%d %d %d\n",n,m,k);
        for(j=0;j<m;j++){
            printf("%d %d\n",getrand(n),getrand(n));
        }

    }
}
