#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 2000000000;
const int M   = 1000000000;
const int N   = 100001;

char str[N][20],in[20];
bool check(int tt){
	char a[20],b[20];
	strcpy(a,str[tt]);
	strcpy(b,in);
	int l1 = strlen(a);
	int l2 = strlen(b);
	if(abs(l1-l2) >= 2) return false;
	if(l1 == l2){//replace
		int pos=-1;
		for(int i=0 ; i < l1 ; ++i)
			if(a[i] != b[i]){
				pos = i; break;
			}
		b[pos] = a[pos];
		if(strcmp(a,b) != 0) return false;
	}else if(l1 == l2+1){//insert
		int pos = -1;
		for(int i=0 ; i < l2 ; ++i)
			if(a[i] != b[i]){
				pos = i; break;
			}
		if(pos==-1) {
			b[l2++]=a[l1-1];
			b[l2]='\0';
		} else {
			l2++;
			for(int i=l2-1 ; i > pos ; --i)
				b[i] = b[i-1];
			b[pos] = a[pos];
			b[l2++] = '\0';
		}
		if(strcmp(a,b) != 0) return false;
	}else if(l1+1 == l2){//delete
		int pos = -1;
		for(int i=0 ; i < l1 ; ++i)
			if(a[i] != b[i]){
				pos = i; break;
			}
		if(pos == -1) b[l2-1]='\0';
		else {
			for(int i=pos ; i < l2-1 ; ++i)
				b[i] = b[i+1];
			b[l2-1] = '\0';
		}
		if(strcmp(a,b) != 0) return false;
	}
	return true;
}
int main()
{
	int k=0;
	while(scanf("%s",str[k])){
		if(strcmp(str[k],"#")==0) break;
		k++;
	}
	while(scanf("%s",in)){
		if(strcmp(in,"#")==0) break;
		bool f = false;
		for(int i=0 ; i < k ; ++i)
			if(strcmp(str[i],in)==0){
				f = true; break;
			}
		if(f){
			printf("%s is correct\n",in);
		} else {
			printf("%s:",in);
			for(int i=0 ; i < k ; ++i)
				if(check(i))
					printf(" %s",str[i]);
			printf("\n");
		}
	}
	return 0;
}