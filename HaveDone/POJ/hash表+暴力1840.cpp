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
const int inf = 1000000000;
const int M = 5000000;
const int N = 50000;

struct Node{
	int num;
	Node *next;
}node[N];
int main(){
	int a1,a2,a3,a4,a5;
	while( scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5) != EOF ){
		memset( node, 0, sizeof( node ) );
		for(int i=-50 ; i <= 50 ; ++i)
			for(int j=-50 ; j <= 50 ; ++j){
				if( i != 0 && j != 0 ){
					int key = i*i*i*a1+j*j*j*a2;
					int val = key;
					key = abs(key) % N;

					Node *now = new Node;
					now->num = val;
					now->next = NULL;

					Node *temp = &node[key];
					while( temp->next != NULL )
						temp = temp->next;
					temp->next = now;

				}
			}
		int ans = 0;
		for(int i=-50 ; i <= 50 ; ++i)
			for(int j=-50 ; j <= 50 ; ++j)
				for(int k=-50 ; k <= 50 ; ++k){
					if( i!=0 && j!=0 && k!=0 ){
						int key = i*i*i*a3+j*j*j*a4+k*k*k*a5;
						int val = key;
						key = abs(key) % N;

						Node *temp = &node[key];
						while( temp->next != NULL ){
							temp = temp->next;
							if( temp->num + val == 0 )
								ans ++;
						}
					}
				}
		printf("%d\n", ans);
	}
	return 0;
}