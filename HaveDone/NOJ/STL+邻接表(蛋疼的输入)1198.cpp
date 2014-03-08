#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int inf = 1000000000;
const int M = 100000;
const int N = 10000;

map<string,int> ma,ans;
map<int,string> am;
map<string,int>::iterator ok;
struct A{
	int v,next;
}a[N];
int heade[N],e,s;
void add(int u,int v){
	a[e].v = v;
	a[e].next = heade[u];
	heade[u] = e++;
}
char str[N],name[N][20];
bool mark[N];
void dfs(int u){
	mark[u] = true;
	for(int j=heade[u] ; j!=-1 ; j=a[j].next){
		ans[am[a[j].v]] = s++;
		if(!mark[a[j].v])
			dfs(a[j].v);
	}
}
int main(){
	int i=0,j,k,p=0,f,len;
	memset(heade,-1,sizeof(heade));
	e = 0;
	while(gets(str)){
		len = strlen(str);
		for(i=0,j=0,k=0 ; i <= len ; ++i)
		{
			if(str[i]==' ' || str[i]=='\0'){
				name[j][k]='\0'; j++; k = 0;
			}
			else name[j][k++] = str[i];
			if(k==0 && ma.find(name[j-1])==ma.end()){
				if(strcmp(name[j-1],"Superman") == 0){
					ma[name[j-1]] = 0;
					am[0] = name[j-1];
				} else {
					ma[name[j-1]] = ++p;
					am[p] = name[j-1];
				}
				if(j==1) f=ma[name[j-1]];
			}
			if(k==0 && j!=1){
				add(ma[name[j-1]],f);
				//add(f,ma[name[j-1]]);
			}
		}
		memset(str,0,sizeof(0));
	}
	s = 0;
	dfs(0);
	//sort(ans,ans+s);
	for(ok=ans.begin() ; ok!=ans.end() ; ++ok)
		cout << ok->first << endl;
	return 0;
}