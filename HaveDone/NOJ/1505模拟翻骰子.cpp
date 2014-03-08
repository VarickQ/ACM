#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1000010;

struct A{
	int top,bottom,north,south,west,east;
	void init(){
		top = 1;
		bottom = 6;
		north = 2;
		south = 4;
		west = 3;
		east = 5;
	}
}a;
char str[N];
int main()
{
	int n,temp;
	while(scanf("%d",&n) == 1)
	{
		a.init();
		scanf("%s",str);
		for(int i=0 ; str[i] ; ++i){
			if(str[i] == 'N'){
				temp = a.top;
				a.top = a.south;
				a.south = a.bottom;
				a.bottom = a.north;
				a.north = temp;
			}
			else if(str[i] == 'S'){
				temp = a.top;
				a.top = a.north;
				a.north = a.bottom;
				a.bottom = a.south;
				a.south = temp;
			}
			else if(str[i] == 'E'){
				temp = a.top;
				a.top = a.west;
				a.west = a.bottom;
				a.bottom = a.east;
				a.east = temp;
			}
			else if(str[i] == 'W'){
				temp = a.top;
				a.top = a.east;
				a.east = a.bottom;
				a.bottom = a.west;
				a.west = temp;
			}
		}
		printf("%d %d %d %d %d %d\n",a.top,a.bottom,a.north,a.south,a.west,a.east);
	}
	return 0;
}