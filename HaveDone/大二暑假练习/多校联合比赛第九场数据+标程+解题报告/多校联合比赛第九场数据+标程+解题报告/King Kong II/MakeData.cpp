/*
 * Author: NomadThanatos
 * Created Time:  2012/8/19 23:12:13
 * File Name: \Desktop\MakeData.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

const int MAXN = 50000 +  50;

const int MAXINT = -1u>>1;
int arr[MAXN];

int main() {
	freopen("Testadd.in","w",stdout);
	for(int i = 0 ; i < 20 ; i++) {
		int N = rand() % 50000 + 1;
		printf("%d\n",N);
		for(int i = 0 ; i < N ; i++) {
			arr[i] = rand() % 10000;
			printf("%d ",arr[i]);
		}
		printf("\n");
		random_shuffle(arr,arr + N);
		for(int i = 0 ; i < N ; i++) {
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	printf("0\n");
    return 0;
}

