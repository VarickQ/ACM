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
    double tmp; 
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
		
		tmp = getrand(10,1700)/10.0;
		printf("%d %.1lf\n",l,tmp-90); 
		for(i=0;i<l;i++){
        	printf("%d ",getrand(1,T*T*T)%100000); 
        }
        puts("");

	}
	return 0;
}
