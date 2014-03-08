#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int mark[N];
int st[N], top;
int c[N];
int Lowbit(int t){
	return t & ( -t );
}
void update(int pos, int num){
	while (pos < N) {
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int end){
	int sum = 0;
	while (end > 0) {
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}
int getNum(int s){
	int l = 1, r = N - 5;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		int left = Sum(mid - 1);
		int right = Sum(mid);
		if (left < s && s <= right)
			break;
		if (left >= s)
			r = mid - 1;
		else l = mid + 1;
	}
	return mid;
}
int main(){
	top = 0;
	int T, num;
	char str[20];
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%s", str);
		if (!strcmp(str,"Pop")) {
			if (top == 0) puts("Invalid");
			else {
				num = st[--top];
				printf("%d\n", num);
				update(num, -1);
			}
		} else if (!strcmp(str,"PeekMedian")) {
			if (top == 0) puts("Invalid");
			else {
				int tmp = 0;
				if (top&1) tmp = (top + 1) / 2;
				else tmp = top / 2;
				printf("%d\n", getNum(tmp));
			}
		} else if (!strcmp(str,"Push")) {
			scanf("%d", &num);
			st[top++] = num;
			update(num, 1);
		}
	}
    return 0;
}