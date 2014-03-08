#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 65;
typedef __int64 LL;

char s1[N],s2[N];
int main(){
    int T, cs=0;
    scanf("%d", &T);
    while( T-- ){
        scanf("%s%s", s1, s2);
        int len = strlen(s1);
        printf("Case #%d: ", ++cs);
        if( len > 2 ){
            int sum1 = 0, sum2 = 0;
            for(int i=0 ; i < len ; ++i){
                sum1 += s1[i]-'a';
                sum2 += s2[i]-'a';
            }
            if( abs(sum1-sum2)%2==0 ) puts("YES");
            else puts("NO");
        } else {
            bool f = false;
            int t = 26;
            while( t-- ){
                if( strcmp(s1,s2) ){
                    char tmp = s1[1];
                    s1[1] = (s1[0]+1-'a')%26+'a';
                    s1[0] = (tmp+1-'a')%26+'a';
                } else {
                    f = true; break;
                }
            }
            if( f ) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}