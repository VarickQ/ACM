#include<stdio.h>
#include<memory.h>
char a,b;
int s[10][10],news[10][10],mix[4][4]={{2,3,1,1},{1,2,3,1},{1,1,2,3},{3,1,1,2}};
int t,i,j,k,tmp;
int getdigit(char c){
    if(c<='9')return c-'0';
    else return c-'A'+10;
}
char output(int v){
    if(v<=9)return '0'+v;
    else return 'A'+v-10;
}
int main(){
    freopen("data.in","r",stdin);
    freopen("forcedata.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        for(i=0;i<4;i++)
            for(j=0;j<4;j++){
                scanf(" %c%c",&a,&b);                
                s[i][j] = 16*getdigit(a)+getdigit(b);
            }
        for(i=0;i<4;i++)
            for(j=0;j<4;j++){
                news[i][j] = 0;
                for(k=0;k<4;k++){
                    if(mix[i][k] == 1){
                        tmp = s[k][j];
                    }else if(mix[i][k] == 2){                        
                        tmp = s[k][j]<<1;                        
                        if(tmp>=256)tmp^=27;                
                    }else if(mix[i][k] == 3){
                        tmp = s[k][j]<<1;
                        if(tmp>=256)tmp^=27;
                        tmp^= s[k][j];
                    }
                    tmp%=256;
                    news[i][j]^=tmp;
                }
                
            }        
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j)printf(" ");
                //printf("%d",news[i][j]);
                printf("%c%c",output(news[i][j]/16),output(news[i][j]%16));
            }
            puts("");
        }
        if(t)puts("");
    }
}
