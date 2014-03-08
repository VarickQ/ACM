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
const int N = 61;

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
        int i, j, t, temp; 
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


BigNumber dp[N][N][N];
int main(){
	int n;
	dp[0][0][0] = BigNumber("1");
	dp[0][0][1] = BigNumber("0");
	dp[0][1][0] = BigNumber("0");
	dp[1][0][0] = BigNumber("1");
	dp[0][1][1] = BigNumber("0");
	dp[1][0][1] = BigNumber("0");
	dp[1][1][0] = BigNumber("1");
	dp[1][1][1] = BigNumber("1");
	for(int i=1 ; i <= 60 ; ++i)
		for(int j=0 ; j <= i ; ++j)
			for(int k=0 ; k <= j ; ++k)
			{
				BigNumber temp = BigNumber("0");
				if(i>j && j>=k) temp=temp+dp[i-1][j][k];
				if(i>=j && j>k) temp=temp+dp[i][j-1][k];
				if(i>=j && j>=k && k>0) temp=temp+dp[i][j][k-1];
				if(i>=j && j>=k && k>=0)dp[i][j][k] = temp;
			}
	while(scanf("%d",&n) == 1){
		dp[n][n][n].print();
		printf("\n");
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char str[100100];
int stack[100100];
int ss[100100];

bool judge(int s,int c)
{
	if(str[s] == '(' && str[c] == ')')
		return true;
	if(str[s] == '[' && str[c] == ']')
		return true;
	return false;
}

int main()
{
	int i;
	while(scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		int top = 0;
		stack[0] = 0;
		memset(ss,0,sizeof(ss));
		for(i = 0;i < len;++i)
		{
			if(str[i] == '(' || str[i] == '[')
			{
				stack[top++] = i;
			}
			else
			{
				if(judge(stack[top-1],i) && top != 0)
				{
					ss[stack[top-1]] = i;
					ss[i] = stack[top-1];
					top--;
				}
				else
				{
					top = 0;
				}
			}
		}
		int beg = 1111111,end = 0;
		int a_beg = 1111111,a_end = 0;
		int Ma = 0;
		for(i = 0;i < len;++i)
		{
			if(ss[i])
			{
				if(i!=0 && ss[ss[i-1]] == i-1)
				{
					if(beg == 1111111)
						beg = i;
					end = ss[i];
					if(Ma < end-beg)
					{
						Ma = end-beg;
						a_beg = beg;
						a_end = end;
					}
				}
				else
				{
					beg = i;
					end = ss[i];
					if(Ma < end-beg)
					{
						Ma = end-beg;
						a_beg = beg;
						a_end = end;
					}
				}
				i = ss[i];
			}
		}
		for(i = a_beg;i <= a_end;++i)
			printf("%c",str[i]);
		cout << endl << endl;
	}
	return 0;
}
//��
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
const int N = 61;
#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

int read(bignum_t a,istream& is=cin){
	char buf[MAX*DIGIT+1],ch;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>buf))	return 0;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}

void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
}

int comp(const bignum_t a,const bignum_t b){
	int i;
	if (a[0]!=b[0])
		return a[0]-b[0];
	for (i=a[0];i;i--)
		if (a[i]!=b[i])
			return a[i]-b[i];
	return 0;
}

int comp(const bignum_t a,const int b){
	int c[12]={1};
	for (c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}

int comp(const bignum_t a,const int c,const int d,const bignum_t b){
	int i,t=0,O=-DEPTH*2;
	if (b[0]-a[0]<d&&c)
		return 1;
	for (i=b[0];i>d;i--){
		t=t*DEPTH+a[i-d]*c-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	for (i=d;i;i--){
		t=t*DEPTH-b[i];
		if (t>0) return 1;
		if (t<O) return 0;
	}
	return t>0;
}

void add(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

void add(bignum_t a,const int b){
	int i=1;
	for (a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void sub(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]-=b[i])<0)
			a[i+1]--,a[i]+=DEPTH;
	for (;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const int b){
	int i=1;
	for (a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sub(bignum_t a,const bignum_t b,const int c,const int d){
	int i,O=b[0]+d;
	for (i=1+d;i<=O;i++)
		if ((a[i]-=b[i-d]*c)<0)
			a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
	for (;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t c,const bignum_t a,const bignum_t b){
	int i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for (c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
		for (j=1;j<=b[0];j++)
			if ((c[i+j-1]+=a[i]*b[j])>=DEPTH)
				c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for (c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}

void mul(bignum_t a,const int b){
	int i;
	for (a[1]*=b,i=2;i<=a[0];i++){
		a[i]*=b;
		if (a[i-1]>=DEPTH)
			a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
	}
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void mul(bignum_t b,const bignum_t a,const int c,const int d){
	int i;
	memset((void*)b,0,sizeof(bignum_t));
	for (b[0]=a[0]+d,i=d+1;i<=b[0];i++)
		if ((b[i]+=a[i-d]*c)>=DEPTH)
			b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH;
	for (;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
	for (;!b[b[0]]&&b[0]>1;b[0]--);
}

void div(bignum_t c,bignum_t a,const bignum_t b){
	int h,l,m,i;
	memset((void*)c,0,sizeof(bignum_t));
	c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1;
	for (i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
		for (h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!c[c[0]]&&c[0]>1;c[0]--);
	c[0]=c[0]>1?c[0]:1;
}

void div(bignum_t a,const int b,int& c){
	int i;
	for (c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
	for (;!a[a[0]]&&a[0]>1;a[0]--);
}

void sqrt(bignum_t b,bignum_t a){
	int h,l,m,i;
	memset((void*)b,0,sizeof(bignum_t));
	for (i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
		for (h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
			if (comp(b,m,i-1,a)) h=m-1;
			else l=m;
	for (;!b[b[0]]&&b[0]>1;b[0]--);
	for (i=1;i<=b[0];b[i++]>>=1);
}

int length(const bignum_t a){
	int t,ret;
	for (ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);
	return ret>0?ret:1;
}

int digit(const bignum_t a,const int b){
	int i,ret;
	for (ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);
	return ret%10;
}

int zeronum(const bignum_t a){
	int ret,t;
	for (ret=0;!a[ret+1];ret++);
	for (t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);
	return ret;
}

void comp(int* a,const int l,const int h,const int d){
	int i,j,t;
	for (i=l;i<=h;i++)
		for (t=i,j=2;t>1;j++)
			while (!(t%j))
				a[j]+=d,t/=j;
}

void convert(int* a,const int h,bignum_t b){
	int i,j,t=1;
	memset(b,0,sizeof(bignum_t));
	for (b[0]=b[1]=1,i=2;i<=h;i++)
		if (a[i])
			for (j=a[i];j;t*=i,j--)
				if (t*i>DEPTH)
					mul(b,t),t=1;
	mul(b,t);
}

void combination(bignum_t a,int m,int n){
	int* t=new int[m+1];
	memset((void*)t,0,sizeof(int)*(m+1));
	comp(t,n+1,m,1);
	comp(t,2,m-n,-1);
	convert(t,m,a);
	delete []t;
}

void permutation(bignum_t a,int m,int n){
	int i,t=1;
	memset(a,0,sizeof(bignum_t));
	a[0]=a[1]=1;
	for (i=m-n+1;i<=m;t*=i++)
		if (t*i>DEPTH)
			mul(a,t),t=1;
	mul(a,t);
}

#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))

int read(bignum_t a,int &sgn,istream& is=cin){
	char str[MAX*DIGIT+2],ch,*buf;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if (!(is>>str)) return 0;
	buf=str,sgn=1;
	if (*buf=='-') sgn=-1,buf++;
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	if (a[0]==1&&!a[1]) sgn=0;
	return 1;
}

struct bignum{
	bignum_t num;
	int sgn;
public:
inline bignum(){memset(num,0,sizeof(bignum_t));num[0]=1;sgn=0;}
inline int operator!(){return num[0]==1&&!num[1];}
inline bignum& operator=(const bignum& a){memcpy(num,a.num,sizeof(bignum_t));sgn=a.sgn;return *this;}
inline bignum& operator=(const int a){memset(num,0,sizeof(bignum_t));num[0]=1;sgn=SGN(a);add(num,sgn*a);return *this;};
inline bignum& operator+=(const bignum& a){if(sgn==a.sgn)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memcpy(num,a.num,sizeof(bignum_t));sub(num,t);sgn=a.sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)memcpy(num,a.num,sizeof(bignum_t)),sgn=a.sgn;return *this;}
inline bignum& operator+=(const int a){if(sgn*a>0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memset(num,0,sizeof(bignum_t));num[0]=1;add(num,ABS(a));sgn=-sgn;sub(num,t);}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)sgn=SGN(a),add(num,ABS(a));return *this;}
inline bignum operator+(const bignum& a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret+=a;return ret;}
inline bignum operator+(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret+=a;return ret;}
inline bignum& operator-=(const bignum& a){if(sgn*a.sgn<0)add(num,a.num);else if(sgn&&a.sgn){int ret=comp(num,a.num);if(ret>0)sub(num,a.num);else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memcpy(num,a.num,sizeof(bignum_t));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)add(num,a.num),sgn=-a.sgn;return *this;}
inline bignum& operator-=(const int a){if(sgn*a<0)add(num,ABS(a));else if(sgn&&a){int ret=comp(num,ABS(a));if(ret>0)sub(num,ABS(a));else if(ret<0){bignum_t t;
	memcpy(t,num,sizeof(bignum_t));memset(num,0,sizeof(bignum_t));num[0]=1;add(num,ABS(a));sub(num,t);sgn=-sgn;}else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;}else if(!sgn)sgn=-SGN(a),add(num,ABS(a));return *this;}
inline bignum operator-(const bignum& a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret-=a;return ret;}
inline bignum operator-(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));ret.sgn=sgn;ret-=a;return ret;}
inline bignum& operator*=(const bignum& a){bignum_t t;mul(t,num,a.num);memcpy(num,t,sizeof(bignum_t));sgn*=a.sgn;return *this;}
inline bignum& operator*=(const int a){mul(num,ABS(a));sgn*=SGN(a);return *this;}
inline bignum operator*(const bignum& a){bignum ret;mul(ret.num,num,a.num);ret.sgn=sgn*a.sgn;return ret;}
inline bignum operator*(const int a){bignum ret;memcpy(ret.num,num,sizeof(bignum_t));mul(ret.num,ABS(a));ret.sgn=sgn*SGN(a);return ret;}
inline bignum& operator/=(const bignum& a){bignum_t t;div(t,num,a.num);memcpy(num,t,sizeof(bignum_t));sgn=(num[0]==1&&!num[1])?0:sgn*a.sgn;return *this;}
inline bignum& operator/=(const int a){int t;div(num,ABS(a),t);sgn=(num[0]==1&&!num[1])?0:sgn*SGN(a);return *this;}
inline bignum operator/(const bignum& a){bignum ret;bignum_t t;memcpy(t,num,sizeof(bignum_t));div(ret.num,t,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*a.sgn;return ret;}
inline bignum operator/(const int a){bignum ret;int t;memcpy(ret.num,num,sizeof(bignum_t));div(ret.num,ABS(a),t);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*SGN(a);return ret;}
inline bignum& operator%=(const bignum& a){bignum_t t;div(t,num,a.num);if (num[0]==1&&!num[1])sgn=0;return *this;}
inline int operator%=(const int a){int t;div(num,ABS(a),t);memset(num,0,sizeof(bignum_t));num[0]=1;add(num,t);return t;}
inline bignum operator%(const bignum& a){bignum ret;bignum_t t;memcpy(ret.num,num,sizeof(bignum_t));div(t,ret.num,a.num);ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn;return ret;}
inline int operator%(const int a){bignum ret;int t;memcpy(ret.num,num,sizeof(bignum_t));div(ret.num,ABS(a),t);memset(ret.num,0,sizeof(bignum_t));ret.num[0]=1;add(ret.num,t);return t;}
inline bignum& operator++(){*this+=1;return *this;}
inline bignum& operator--(){*this-=1;return *this;};
inline int operator>(const bignum& a){return sgn>0?(a.sgn>0?comp(num,a.num)>0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<0:0):a.sgn<0);}
inline int operator>(const int a){return sgn>0?(a>0?comp(num,a)>0:1):(sgn<0?(a<0?comp(num,-a)<0:0):a<0);}
inline int operator>=(const bignum& a){return sgn>0?(a.sgn>0?comp(num,a.num)>=0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<=0:0):a.sgn<=0);}
inline int operator>=(const int a){return sgn>0?(a>0?comp(num,a)>=0:1):(sgn<0?(a<0?comp(num,-a)<=0:0):a<=0);}
inline int operator<(const bignum& a){return sgn<0?(a.sgn<0?comp(num,a.num)>0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<0:0):a.sgn>0);}
inline int operator<(const int a){return sgn<0?(a<0?comp(num,-a)>0:1):(sgn>0?(a>0?comp(num,a)<0:0):a>0);}
inline int operator<=(const bignum& a){return sgn<0?(a.sgn<0?comp(num,a.num)>=0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<=0:0):a.sgn>=0);}
inline int operator<=(const int a){return sgn<0?(a<0?comp(num,-a)>=0:1):(sgn>0?(a>0?comp(num,a)<=0:0):a>=0);}
inline int operator==(const bignum& a){return (sgn==a.sgn)?!comp(num,a.num):0;}
inline int operator==(const int a){return (sgn*a>=0)?!comp(num,ABS(a)):0;}
inline int operator!=(const bignum& a){return (sgn==a.sgn)?comp(num,a.num):1;}
inline int operator!=(const int a){return (sgn*a>=0)?comp(num,ABS(a)):1;}
inline int operator[](const int a){return digit(num,a);}
friend inline istream& operator>>(istream& is,bignum& a){read(a.num,a.sgn,is);return is;}
friend inline ostream& operator<<(ostream& os,const bignum& a){if(a.sgn<0)os<<'-';write(a.num,os);return os;}
friend inline bignum sqrt(const bignum& a){bignum ret;bignum_t t;memcpy(t,a.num,sizeof(bignum_t));sqrt(ret.num,t);ret.sgn=ret.num[0]!=1||ret.num[1];return ret;}
friend inline bignum sqrt(const bignum& a,bignum& b){bignum ret;memcpy(b.num,a.num,sizeof(bignum_t));sqrt(ret.num,b.num);ret.sgn=ret.num[0]!=1||ret.num[1];b.sgn=b.num[0]!=1||ret.num[1];return ret;}
inline int length(){return ::length(num);}
inline int zeronum(){return ::zeronum(num);}
inline bignum C(const int m,const int n){combination(num,m,n);sgn=1;return *this;}
inline bignum P(const int m,const int n){permutation(num,m,n);sgn=1;return *this;}
};

char str[65];
bignum com(int n, int m){
	bignum r;
	int i;
	r = 1;
	for (i = 1; i <= m; ++ i) {
		r *= (n-i+1); r /= i;
	}
	return r;
}
bignum gcd(bignum a,bignum b){
	if (b == 0) return a;
	return gcd(b,a%b);
}
bool cmp(const int a,const int b){
	return a > b;
}
int main(){
	int n,k,len,cnt[27],d[27];
	bignum tot,fz,tt;
	while(scanf("%d",&n) == 1){
		scanf("%s",str);
		memset(cnt,0,sizeof(cnt));
		len = strlen(str);
		for(int i=0 ; str[i] ; ++i)
			cnt[str[i]-'A']++;
		sort(cnt,cnt+26,cmp);
		for(k=0 ; cnt[k] ; ++k);
		tot = com(n,len);

		double temp;
		for(int i=0 ; i < k ; ++i) d[i]=1;
		fz = 1;
		for(int i=0 ; i < n-len ; ++i){
			int pos = -1;
			double Max = -1;
			for(int j=0 ; j < k ; ++j){
				temp = 1.0*(cnt[j]+d[j])/d[j];
				if(temp > Max){
					Max = temp; pos = j;
				}
			}
			fz = fz*(cnt[pos]+d[pos])/d[pos];
			d[pos]++;
		}
		tt = gcd(fz,tot);
		cout << fz/tt <<'/'<< tot/tt << endl;

		for(int i=0 ; i < k ; ++i) d[i]=1;
		fz = 1;
		for(int i=0 ; i < n-len ; ++i){
			int pos = 0;
			double Min = 1.0*inf;
			for(int j=0 ; j < k ; ++j){
				temp = 1.0*(cnt[j]+d[j])/d[j];
				if(temp < Min){
					Min = temp; pos = j;
				}
			}
			fz = fz*(cnt[pos]+d[pos])/d[pos];
			d[pos]++;
		}
		tt = gcd(fz,tot);
		cout << fz/tt <<'/'<< tot/tt << endl;

		cout << endl;
	}
	return 0;
}
