某公司要统计全年盈利状况，对于每一个月来说，如果盈利则盈利S，如果亏空则亏空D。
公司每五个月进行一次统计，全年共统计8次(1-5、2-6、3-7、4-8、5-9、6-10、7-11、8-12)，已知这8次统计的结果全部是亏空(盈利-亏空<0)。
题目给出S和D，判断全年是否能盈利，如果能则求出盈利的最大值，如果不能盈利则输出Deficit。
恩，符合最优子结构性质，可以使用贪心算法。5个月统计一次都亏空，那么有5种情况：
1、若SSSSD亏空，那么全年最优情况为SSSSDSSSSDSS
2、若SSSDD亏空，那么全年最优情况为SSSDDSSSDDSS
3、若SSDDD亏空，那么全年最优情况为SSDDDSSDDDSS
4、若SDDDD亏空，那么全年最优情况为SDDDDSDDDDSD
5、若DDDDD亏空，全年必亏空...
因此只要讨论这5种情况即可...

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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int inf = 1000000000;
const int M   = 105;
const int N   = 5;
typedef long long ll;

int main(){
	int s,d,Max;
	while( scanf("%d%d", &s, &d ) != EOF ){
		Max = -12*d;
		if( 4*s < d )
			Max = max(Max,10*s-2*d);
		if( 3*s < 2*d )
			Max = max(Max,8*s-4*d);
		if( 2*s < 3*d )
			Max = max(Max,6*s-6*d);
		if( s < 4*d )
			Max = max(Max,3*s-9*d);
		if( Max < 0 )
			printf("Deficit\n");
		else printf("%d\n", Max);
	}
	return 0;
}