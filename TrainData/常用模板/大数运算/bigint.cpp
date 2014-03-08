	             //高精例程
/////////////////////////////////////////////////////////////
//常用函数                                                 //
//(1)add(bint a, bint b, bint& c)大数加法c=a+b             //
//(2)add(bint a, type b, bint& c)高精加单精 c=a+b          //
//(3)by(bint a, type b, bint& c)高精乘单精c=a*b,           //
// **注意:b应小于base**                                    //
//(4)by(bint a, bint b, bint& c)大数乘法c=a*b              //
//(5)div(bint a, type b, bint& c, type& d)高精除单精       //
//    c = a/b, d = a%b;                                    //
//(6)input(bint& a)输入高精,无效输入返回0,否则返回1        //
//(7)output(bint& a)输出高精                               //
/////////////////////////////////////////////////////////////
//少用函数                                                 //
//(8)move(bint& a)二进制右移,即除2操作                     //
//(9)sub(bint a, bint b, bint& c)大数减法c=a-b,a>=b        //
//(10)sub(bint a, type b, bint& c)高精减单精c=a-b,a>=b     // 
//(11)cmp(bint a, bint b)比较a和b,>,==,<分别返回           //
//    正数,0,负数.                                         //
//(12)give(bint a, bint& b)赋值 b = a;                     //
//(13)give(type a, bint& b)赋值 b = a;                     //
//(14)shift(bint& a, type k)段移位函数,把a移动k段,变大mod^k//
//(15)div(bint a, bint b, bint& c, bint& d)大数除法        //
//   c=a/b,d=a%b,**注意:需要函数(1),(2),(4),(9),(11),(13), //
//  (14)**                                                 //
/////////////////////////////////////////////////////////////
//0这个数据还没过，需要改一下 
#include <stdio.h>
#include <string.h>
//////////////////////////////////////
#define MAX 70
#define mod 10000
#define baselen 4
#define in(a) scanf("%d",&a);
#define out1(a) printf("%d",a)
#define out2(a) printf("%04d",a)
typedef int type;
/////////////////////////////////////
struct bint{
	type dig[MAX], len;
	bint(){len = 0, dig[0] = 0;}
};
////////////////////////////////////////////
//常用函数
//(1)
void add(bint a, bint b, bint& c){
	type i, carry ;
	for( i = carry = 0; i <= a.len || i <= b.len || carry; i++){
		  if(i<=a.len)carry += a.dig[i];
		  if(i<=b.len)carry += b.dig[i];
		  c.dig[i] = carry%mod;
		  carry /= mod;
	}
	c.len = i - 1;
}
//(2)
void add(bint a, type b, bint& c){
	type i;
	for( i  = 0; i <= a.len || b; i++){
		if(i<=a.len)b += a.dig[i];
		c.dig[i] = b%mod;
		b /= mod;
	}
	c.len = i-1;
}
//(3)
void by(bint a, type b, bint& c){
	type i, carry;
	for( i = carry = 0; i <= a.len || carry; i++){
		if( i <= a.len ) carry += b*a.dig[i];
		c.dig[i] = carry%mod;
		carry /= mod;
	}
	i--;
	while( i && !c.dig[i] )i--;
	c.len = i;
}
//(4)
void by(bint a, bint b, bint& c){
	type i, j, carry;
	for( i=a.len+b.len+1; i>=0; i--)c.dig[i] = 0;
	for( i=0; i<=a.len; i++){
		carry = 0;
		for( j=0; j<=b.len||carry; j++){
			carry  += c.dig[i+j];
			if(j<=b.len)carry += a.dig[i]*b.dig[j];
			c.dig[i+j] = carry%mod;
			carry /= mod;
		}
	}
	i = a.len+b.len+1;
	while(i&&c.dig[i]==0)i--;
	c.len = i;
}
//(5)
void div(bint a, type b, bint& c, type& d){
	type i;
	for(i = a.len,d = 0; i>=0 ; i--){
		d = d*mod + a.dig[i];
		c.dig[i] = d/b;
		d = d%b;		
	}
	i = a.len;
	while(i&&c.dig[i]==0)i--;
	c.len = i;
}
//(6)
bool input(bint& a){
	type i, j, w, k;
	char data[MAX*baselen+1];
	if(scanf("%s",data)==EOF)return false;
	w = strlen(data) - 1, a.len = 0;;
	while(1){
		i = j = 0, k = 1;
		while(i<baselen&&w>=0){
			j = j+ (data[w--] - '0')*k;
			k *= 10, i++;
		}
		a.dig[a.len++] = j;
		if(w<0)break;
	}
	a.len--;
	return true;
}
//(7)
void output(bint& a){
	type i;
	i = a.len - 1;
	out1(a.dig[a.len]);
	while(i>=0)out2(a.dig[i--]);
}
////////////////////////////////////////////////////////////////////////
//少用函数
//(8)
void move(bint& a){
	type carry, k, t;
	k = a.len+1, carry = 0;
	while(k--){
		t = a.dig[k]&1;
		a.dig[k] = (a.dig[k]>>1);
		if(carry)a.dig[k] += (mod>>1);
		carry = t;
	}
	if(a.len&&a.dig[a.len]==0)a.len--;
}
//(9)
void sub(bint a, bint b, bint& c){
	type i, carry;
	for( i=carry=0; i<=a.len; i++){
		c.dig[i] = a.dig[i]-carry;
		if(i<=b.len)c.dig[i] -= b.dig[i];
		if(c.dig[i]<0)carry = 1, c.dig[i] += mod;
		else carry = 0;
	}
	i--;
	while(i&&c.dig[i]==0)i--;
	c.len = i;
}
//(10)
void sub(bint a, type b, bint& c){
	type i;
	for( i=0; i<=a.len; i++){
		c.dig[i] = a.dig[i]-b;
		if(c.dig[i]<0)b = 1, c.dig[i] += mod;
		else b = 0;
	}
	i--;
	while(i&&c.dig[i]==0)i--;
	c.len = i;
}
//(11)
int cmp(bint a, bint b){
	if(a.len<b.len)return -1;
	if(a.len>b.len)return 1;
	int i = a.len;
	while(i&&a.dig[i]==b.dig[i])i--;
	return a.dig[i] - b.dig[i];
}
//(12)
void give(bint a, bint& b){
	int i = 0;
	while(i<=a.len){
		b.dig[i] = a.dig[i];
		i++;
	}
	b.len = a.len;
}
//(13)
void give(type a, bint& b){
	b.dig[0] = a%mod;
	a /= mod;
	if(a>0)b.dig[1] = a, b.len = 1;
	else b.len = 0;
}
//(14)
void shift(bint& a, type k){
	int i;
	i = a.len+k;
	while(i>=k){
		a.dig[i] = a.dig[i-k];
		i --;
	}
	while(i>=0)a.dig[i--] = 0;
	a.len += k;
}
//(15)
void div(bint a, bint b, bint& c, bint& d){
	type x, k;
	bint temp;
	give(a, d);
	c.len = c.dig[0] = 0;
	while( cmp(d,b)>0 ){
		k = d.len - b.len;
		if( d.dig[d.len] > b.dig[b.len] )
			x = d.dig[d.len] / (b.dig[b.len] + 1);
		else if( k )
			k--, x =  ( d.dig[d.len]*mod + d.dig[d.len-1])/(b.dig[b.len] + 1);
		else break;
		by( b, x, temp);
		shift( temp, k );
		sub(d, temp, d);
		give( x, temp );
		shift(temp, k);
		add(c, temp, c);
	}
	if(cmp(d,b)>=0) sub(d,b,d), add(c,(type)1, c); 	
}
//////////////////////////////////////////////////////////////////////////
int main(){
	bint a, start, end, mid, temp;
	type i, j, len;
	int s[200];
	while(input(a)){
		give(a,end);
		end.len = a.len/3  + 2;
		end.dig[end.len-1] = 0;
		end.dig[end.len] = 1;
		shift(end,10);
		give(a,start);
		start.len = a.len/3 - 1;
		if(start.len<0)start.len = 0;
		start.dig[start.len] = 1;
		shift(start,10);
		shift(a,30);
		while(cmp(end,start)>=0){
			add(end,start,mid);
			move(mid);
			by(mid,mid,temp);
			by(mid,temp,temp);
			if(cmp(temp,a)<=0)add(mid,type(1), start);
			else sub(mid,type(1),end);
		}
		for(i=0;i<30;i++)div(end,10,end,j);
		j = 0, len = 0;
		give(end,temp);
		while( !(temp.dig[0]==0&&temp.len==0) ){
			j += temp.dig[0]%10;
			s[len++] = temp.dig[0]%10;
			j %= 10;
			div(temp,10,temp,i);
		}
		printf("%d ",j);
		len--;
		while(len>=10)printf("%d",s[len--]);
		printf(".");
		while(len>=0)printf("%d",s[len--]);
		printf("\n");
	}
	return 0;
}
