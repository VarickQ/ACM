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
typedef long long ll;
const int inf = 2000000000;
const int M = 100000;
const int N = 1005;

struct BigNumber
{
    string num;
    BigNumber() {}
    BigNumber(string str)
    {
        reverse(str.begin(), str.end());
        num = str;
    }
    BigNumber operator+(BigNumber T)
    {
        BigNumber ret;
        int lenT = T.num.length();
        int len = num.length();
        int i, t, temp;
        for (i = 0, t = 0; i < lenT && i < len; i++)
        {
            temp = num[i] - '0' + T.num[i] - '0' + t;
            ret.num += temp % 10 + '0';
            t = temp / 10;
        }
        for (; i < lenT; i++)
        {
            temp = T.num[i] - '0' + t;
            ret.num += temp % 10 + '0';
            t = temp / 10;
        }
        for (; i < len; i++)
        {
            temp = num[i] - '0' + t;
            ret.num += temp % 10 + '0';
            t = temp / 10;
        }
        while (t)
        {
            ret.num += t % 10 + '0';
            t /= 10;
        }
        return ret;
    }
    BigNumber operator*(int n)
    {
        int len = num.length();
        int i, t, temp;
        BigNumber ret;
        for (i = 0, t = 0; i < len; i++)
        {
            temp = (num[i] - '0') * n + t;
            t = temp / 10;
            ret.num += temp % 10 + '0';
        }
        while (t)
        {
            ret.num += t % 10 + '0';
            t /= 10;
        }
        return ret;
    }
    void print()
    {
        reverse(num.begin(), num.end());
        cout << num << endl;
        reverse(num.begin(), num.end());
    }
};
int main(){
	int T,a,k;
	BigNumber n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&k);
		n = BigNumber("1");
		for(int i=2 ; i <= a ; ++i)
			n = n*i;
		int cnt=0;
		for(int i=0 ; i < n.num.length() ; ++i)
			if(n.num[i] == k+'0') cnt++;
		cout << cnt << endl;
	}
	return 0;
}
