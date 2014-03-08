#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#define MAX 1000
int main() {
	freopen("data.in", "w", stdout);
	int i, n;
	srand((unsigned)time(NULL));
	n = 10000;
	printf("%d\n", n);
	for(i=0; i<n; i++) {
		printf("%d %d %d %d\n",rand() % MAX, rand() % MAX, rand() % MAX, rand() % MAX);
	}
	return 0; 
}
