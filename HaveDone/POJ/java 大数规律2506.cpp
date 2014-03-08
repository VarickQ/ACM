/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <time.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N   = 255;
typedef long long LL;

LL dp[N];//2*i能有的情况种数
int main(){
	int n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;
	for(int i=3 ; i <= 250 ; ++i)
	//最右边是竖着的一块 dp[i-1]
	//最右边是横着的两块 dp[i-2]
	//最右边是一块 2*2的 dp[i-2]
		dp[i] = dp[i-1]+dp[i-2]*2;
	while( scanf("%d", &n) != EOF ){
		printf("%lld\n", dp[n]);
	}
	return 0;
}
*/
import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger dp[] = new BigInteger[265];
		BigInteger two = new BigInteger("2");
		dp[0] = new BigInteger("1");
		dp[1] = new BigInteger("1");
		dp[2] = new BigInteger("3");
		for(int i=3 ; i < 260 ; ++i )
			dp[i] = dp[i-1].add(dp[i-2].multiply(two));
		
		while( cin.hasNextInt() ){
			int n = cin.nextInt();
			System.out.println( dp[n] );
		}
	}

}