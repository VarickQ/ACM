ĳ��˾Ҫͳ��ȫ��ӯ��״��������ÿһ������˵�����ӯ����ӯ��S��������������D��
��˾ÿ����½���һ��ͳ�ƣ�ȫ�깲ͳ��8��(1-5��2-6��3-7��4-8��5-9��6-10��7-11��8-12)����֪��8��ͳ�ƵĽ��ȫ���ǿ���(ӯ��-����<0)��
��Ŀ����S��D���ж�ȫ���Ƿ���ӯ��������������ӯ�������ֵ���������ӯ�������Deficit��
�������������ӽṹ���ʣ�����ʹ��̰���㷨��5����ͳ��һ�ζ����գ���ô��5�������
1����SSSSD���գ���ôȫ���������ΪSSSSDSSSSDSS
2����SSSDD���գ���ôȫ���������ΪSSSDDSSSDDSS
3����SSDDD���գ���ôȫ���������ΪSSDDDSSDDDSS
4����SDDDD���գ���ôȫ���������ΪSDDDDSDDDDSD
5����DDDDD���գ�ȫ��ؿ���...
���ֻҪ������5���������...

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