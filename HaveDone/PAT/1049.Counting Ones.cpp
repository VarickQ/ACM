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
			//当前位上数字为0,可能出现1的次数由更高位决定
			//等于更高位的数字 * 当前位数
			ret += left * tmp;
		} else if (now == 1) {
			//当前位数字为1,可能出现1的次数不仅受更高位影响还受低位影响
			//等于更高位的数字 * 当前位数 + 低位数字 + 1
			ret += left * tmp + right + 1;
		} else {
			//当前位上数字大于1（2~9）,出现1的情况仅由更高位决定
			//等于（更高位数字 + 1） * 当前位数
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