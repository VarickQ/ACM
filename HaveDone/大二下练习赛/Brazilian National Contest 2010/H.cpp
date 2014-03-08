//H Ä£Äâ+KMP by Varick_Q
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 100000000;
const int M   = 2000100;
const int N   = 100005;
typedef long long ll;

int Next[100002];
void NEXT(int *str,int len){
    int i = 0,j = -1;
    Next[0] = -1;
	while(i < len){
        if(j == -1 || str[i] == str[j])
            ++i,++j,Next[i] = j;
		else j = Next[j];
    }
}
void KMP(int *cs, int s1, int *str, int s2){
    int i = 0, j = 0;
	int ans = 0;
	while(i < s1 && j < s2){
		if(j == -1 || cs[i] == str[j])
			i ++,j ++;
		else j = Next[j];
	}
	if(j == s2) printf("S\n");
	else printf("N\n");
}
int v[500];
int main(){
	v['A'] = 0;
	v['A'+'#'] = v['B'+'b'] = 1;
	v['C'+'b'] = v['B'] = 2;
	v['B'+'#'] = v['C'] = 3;
	v['C'+'#'] = v['D'+'b'] = 4;
	v['D'] = 5;
	v['D'+'#'] = v['E'+'b'] = 6;
	v['F'+'b'] = v['E'] = 7;
	v['E'+'#'] = v['F'] = 8;
	v['F'+'#'] = v['G'+'b'] = 9;
	v['G'] = 10;
	v['G'+'#'] = v['A'+'b'] = 11;
	int n,m;
	int a[N],b[N];
	while( scanf("%d%d", &n, &m) && (n+m) ){
		char s[3],temp[3];
		scanf("%s", temp);
		for(int i=1 ; i < n ; ++i){
			scanf("%s", s);
			int num1=0,num2=0;
			for(int j=0 ; temp[j] ; ++j)
				num1 += temp[j];
			for(int j=0 ; s[j] ; ++j)
				num2 += s[j];
			a[i-1] = (v[num2]-v[num1]+12)%12;
			strcpy(temp,s);
		}

		scanf("%s", temp);
		for(int i=1 ; i < m ; ++i){
			scanf("%s", s);
			int num1=0,num2=0;
			for(int j=0 ; temp[j] ; ++j)
				num1 += temp[j];
			for(int j=0 ; s[j] ; ++j)
				num2 += s[j];
			b[i-1] = (v[num2]-v[num1]+12)%12;
			strcpy(temp,s);
		}

		NEXT(b,m-1);
		KMP(a,n-1,b,m-1);
	}
	return 0;
}