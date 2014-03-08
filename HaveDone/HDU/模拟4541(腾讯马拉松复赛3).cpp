#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
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
typedef long long LL;
const double eps = 1e-8;
const LL MOD = 1000000007;
const int inf = 1000000000;
const int M = 100005;
const int N = 100005;

char c[105][30]={
"zero","one","two","three","four","five","six","seven"
,"eight","nine","ten","eleven","twelve","thirteen","fourteen"
,"fifteen","sixteen","seventeen","eighteen","nineteen","twenty"
,"twentyone","twentytwo","twentythree","twentyfour","twentyfive"
,"twentysix","twentyseven","twentyeight","twentynine","thirty","thirtyone"
,"thirtytwo","thirtythree","thirtyfour","thirtyfive","thirtysix","thirtyseven"
,"thirtyeight","thirtynine","forty","fortyone","fortytwo","fortythree","fortyfour"
,"fortyfive","fortysix","fortyseven","fortyeight","fortynine","fifty","fiftyone","fiftytwo"
,"fiftythree","fiftyfour","fiftyfive","fiftysix","fiftyseven","fiftyeight","fiftynine","sixty"
,"sixtyone","sixtytwo","sixtythree","sixtyfour","sixtyfive","sixtysix","sixtyseven","sixtyeight"
,"sixtynine","seventy","seventyone","seventytwo","seventythree","seventyfour","seventyfive"
,"seventysix","seventyseven","seventyeight","seventynine","eighty","eightyone","eightytwo"
,"eightythree","eightyfour","eightyfive","eightysix","eightyseven","eightyeight","eightynine"
,"ninety","ninetyone","ninetytwo","ninetythree","ninetyfour","ninetyfive","ninetysix"
,"ninetyseven","ninetyeight","ninetynine",
"onegoogol","twogoogol","sixgoogol","tengoogol"
};
map<string,int> ma;
string s[105];
bool cmp(const string a,const string b){
    return a.length() < b.length();
}
vector<int> v;
int main(){
    for(int i=0 ; i <= 99 ; ++i){
        s[i] = c[i];
        ma[s[i]] = i;
    }
    s[100] = c[100];
    ma[s[100]] = 100000;
    s[101] = c[101];
    ma[s[101]] = 200000;
    s[102] = c[102];
    ma[s[102]] = 600000;
    s[103] = c[103];
    ma[s[103]] = 1000000;
    sort( s, s+104, cmp );
    int T, n, m;
    scanf("%d", &T);
    for(int cs=1 ; cs <= T; ++cs){
        v.clear();
        scanf("%d%d", &n, &m);
        printf("Case #%d: ", cs);
        for(int i=0 ; i <= 100 ; ++i)
            if( s[i].length() == n )
                v.push_back(ma[s[i]]);
        if( v.size() < m ){
            puts("-1"); continue;
        }
        sort( v.begin(), v.end() );
        int res = v[m-1];
        if( res >= 100000 ){
            printf("%d", res);
            for(int i=1 ; i <= 95 ; ++i) printf("0");
            puts("");
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}