#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN
using namespace std;
int getrand(int l,int r){
    int t = rand(); 
    return (t*1.0*(r-l)/32000)+l;
}
int main() {
    int ti=1,i,T=0;
	freopen("data.in", "w", stdout);
	srand((unsigned)time(NULL));
	int dataset = 100;
	while(dataset--) {
		int l = 4*ti;
		T++;
        if(dataset>15){
    		l = T * 5;
        }else{
            l = T * 100;
        }
        //l = 10;
		printf("%d %d\n",l,getrand(1,10)); 
		for(i=0;i<l;i++){
        	printf("%d ",(getrand(1,T*T*T)%10000000)); 
        	//printf("%d ",getrand(1,1000000000)); 
        }
        puts("");
	}
	return 0;
}
