//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <map>
//#include <queue>
//#include <vector>
//#include <string>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//typedef long long ll;
//#define CLR(arr,val) memset(arr,val,sizeof(arr));
//const double eps = 1e-8;
//const int inf = 1000000000;
//const int M = 6050000;
//const int N = 1005;
//
////char temp[M],t[M];//´ò±í³ÌÐò
////int num;
////void fun( char *p ){
////	if( num > 20 ) return ;
////	CLR(temp,0);
////	int k = 0, len = strlen(p);
////	for(int i=0 ; i < len ; ++i){
////		if( p[i] == '0' ){
////			temp[k++] = '1';
////			temp[k++] = '0';
////		}
////		else if( p[i] == '1' ){
////			temp[k++] = '0';
////			temp[k++] = '1';
////		}
////	}
////	int cnt = 0;
////	for(int i=0 ; i < k-1 ; ++i)
////		if( temp[i]=='0' && temp[i+1]=='0' )
////			cnt++;
////	printf("%d :%d\n", num+1, cnt);
////	strcpy( t, temp );
////	num++;
////	fun( t );
////}
//ll ans[N];
//int main() {
//////////////////////////////////////////
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//#endif
//////////////////////////////////////////
//	int n;
//	//fun("1");
//	ans[1] = 0;
//	ans[2] = ans[3] = 1;
//	for(int i=4 ; i <= 1000 ; ++i){
//		ll sum = 0;
//		for(int j=1 ; j < i ; ++j)
//			sum += ans[j];
//		ans[i] = sum;
//		if( i%2==0 ) ans[i]++;
//	}
//	while( scanf("%d", &n) != EOF ){
//		printf("%d\n", ans[n]);
//	}
//    return 0;
//}

import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger one,ans[] = new BigInteger[1005];
		//zero = new BigInteger("0");
		one = new BigInteger("1");
		ans[1] = new BigInteger("0");
		ans[2] = new BigInteger("1");
		ans[3] = new BigInteger("1");
		for(int i=4 ; i <= 1000 ; ++i){
			BigInteger sum = new BigInteger("0");
			ans[i] = new BigInteger("0");
			for(int j=2 ; j < i ; ++j)
				sum = sum.add(ans[j]);
			ans[i] = ans[i].add(sum);
			if(i%2==0) ans[i] = ans[i].add(one);
		}
		while( cin.hasNextInt() ){
			int n = cin.nextInt();
			System.out.println(ans[n]);
		}

	}

}
