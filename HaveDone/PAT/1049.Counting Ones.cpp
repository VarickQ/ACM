#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

//http://blog.csdn.net/SJF0115/article/details/8600599
int getOnes(int n){
	int tmp = 1, ret = 0;
	while (n / tmp) {
		int left = n / (tmp * 10);
		int now = (n / tmp) % 10;
		int right = n % tmp;
		if (now == 0) {
			//��ǰλ������Ϊ0,���ܳ���1�Ĵ����ɸ���λ����
			//���ڸ���λ������ * ��ǰλ��
			ret += left * tmp;
		} else if (now == 1) {
			//��ǰλ����Ϊ1,���ܳ���1�Ĵ��������ܸ���λӰ�컹�ܵ�λӰ��
			//���ڸ���λ������ * ��ǰλ�� + ��λ���� + 1
			ret += left * tmp + right + 1;
		} else {
			//��ǰλ�����ִ���1��2~9��,����1��������ɸ���λ����
			//���ڣ�����λ���� + 1�� * ��ǰλ��
			ret += (left + 1) * tmp;
		}
		tmp *= 10;
	}
	return ret;
}
int main(){
	int n;
	scanf("%d", &n);
	int ans = getOnes(n);
	printf("%d\n", ans);
    return 0;
}