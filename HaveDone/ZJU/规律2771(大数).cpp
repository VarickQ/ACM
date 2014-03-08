#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;

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

BigNumber dp[65][5];
int main(){
	int n;
	dp[0][1] = BigNumber("1");;
	dp[0][2] = BigNumber("1");;
	dp[0][3] = BigNumber("1");;
	dp[1][1] = BigNumber("1");;
	dp[1][2] = BigNumber("2");;
	dp[1][3] = BigNumber("3");;
	for(int i=2 ; i <= 60 ; ++i){
		dp[i][1] = dp[i-1][3];
		dp[i][2] = dp[i-1][3]+dp[i-1][2];
		dp[i][3] = dp[i-1][3]+dp[i-1][2]+dp[i-1][1];
	}
	while( scanf("%d", &n) != EOF ){
		dp[n][3].print();
	}
	return 0;
}