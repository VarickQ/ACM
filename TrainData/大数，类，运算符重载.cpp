#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

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

BigNumber d[305][305];

int main()
{
	int i,j;

	for(i=0;i<=300;i++)

		d[0][i] = BigNumber("1");

	for(i=1;i<=300;i++)
	{
		d[i][i] = d[i-1][i];

		 for(j=i + 1;j<=300;j++)
			
			d[i][j] = d[i-1][j] + d[i][j - 1];
	}

	int n;

	while(scanf("%d",&n),n)
	{
		BigNumber ans = d[n][n] * 2;

		ans.print();
	}

	return 0;
}
