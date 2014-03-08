//F by fbioki
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200;
int race[maxn][maxn], scoreSystem[maxn][maxn];
int totalScore[maxn];
int raceNum, scoreSystemNum, pilotNum;
int main () {
	int i, j, k;
	while (scanf ("%d%d", &raceNum, &pilotNum) == 2) {
		if (raceNum == 0 && pilotNum == 0) break;
		for (i = 1; i <= raceNum; ++i) {
			for (j = 1; j <= pilotNum; ++j) {
				scanf ("%d", &race[i][j]);
			}
		}

		memset (scoreSystem, 0, sizeof (scoreSystem));
		scanf ("%d", &scoreSystemNum);
		for (i = 1; i <= scoreSystemNum; ++i) {
			scanf ("%d", &k);
			for (j = 1; j <= k; ++j) {
				scanf ("%d", &scoreSystem[i][j]);
			}
		}

		
		for (i = 1; i <= scoreSystemNum; ++i) {
			memset (totalScore, 0, sizeof (totalScore));
			int maxScore = -1;
			int pos = 0;
			for (j = 1; j <= pilotNum; ++j) {
				for (k = 1; k <= raceNum; ++k) {
					totalScore[j] += scoreSystem[i][race[k][j]];
				}
				if (maxScore < totalScore[j]) {
					maxScore = totalScore[j];
					pos = j;
				}
			}
			for (j = 1; j <= pilotNum; ++j) {
				if (totalScore[j] == maxScore) {
					printf ("%d", j);
					break;
				}
			}
			for (; j <= pilotNum; ++j) {
				if (j != pos && totalScore[j] == maxScore) printf (" %d", j);
			}
			printf ("\n");
		}
	}
	return 0;
}