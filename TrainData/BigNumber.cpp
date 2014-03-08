#include<iostream>
using namespace std;

typedef int Container; //B * B不能超范围
const int LEN = 150;   //10进制数总长
const int UNIT = 4;    //精度(与进制后的零的个数对应)
const Container B = 10000; //进制
const int D = LEN / UNIT; //数组大小
char BUFFER[LEN + 1];
struct Div_ans;	 //用结构体存除法的商和余数	

struct BigNumber 
{
	Container num[D], len;
	bool sign;

	BigNumber() {};
	BigNumber(int sour);
	BigNumber(char *sour);

	void operator += (BigNumber b); 		//加法用  += 
	BigNumber operator * (BigNumber b); 	//乘法用  * 
	
	char *toString();
	
	int Cmp(const BigNumber &a, const BigNumber &b);//被减法调用到 
	BigNumber operator - (BigNumber b); 	//减法用  - 
	
	//Div_ans div(BigNumber a,int div);		//除法用  div 
	
	/*
	bool operator > (BigNumber b);	
	bool operator == (BigNumber b);
	bool operator < (BigNumber b);
	
	BigNumber operator + (BigNumber b);
	void operator *= (BigNumber b);	
	*/
};

BigNumber::BigNumber(int sour) 
{
	memset(num, 0, sizeof(num));
	sign = (sour < 0);
	sour = abs(sour);
	num[0] = 0;
	len = 0;
	while (sour) 
	{
		num[len++] = sour % B;
		sour /= B;
	}
	if (len == 0) len++;
}

BigNumber::BigNumber(char *sour) 
{
	memset(num, 0, sizeof(num));
	len = 0;
	int slen = strlen(sour);
	if (sour[0] == '-') 
	{
		sign = 1;
		sour++;
		slen--;
	} else sign = 0;
	int i, j, tmp;
	for (i = slen - 1; i >= 0; i -= UNIT) 
	{
		tmp = 0;
		for (j = max(0, i - UNIT + 1); j <= i; j++) 
		{
			tmp = tmp * 10 + sour[j] - '0';
		}
		num[len++] = tmp;
	}
}
char *BigNumber::toString() //输出 
{
	char *p = BUFFER;
	if (sign) sprintf(p, "-");;
	if (len > 0) sprintf(p, "%d", num[len - 1]);
	else sprintf(p, "0");
	p += strlen(p);
	for (int i = len - 2; i >= 0; i--, p += strlen(p))
		sprintf(p, "%.*d", UNIT, num[i]);
	return BUFFER;
}

istream& operator >> (istream& input, BigNumber& data) 	//重载 >>
{
	input >> BUFFER;
	data = BUFFER;
	return input;
}

ostream& operator << (ostream& output, BigNumber& data) //重载 <<
{
	output << data.toString();
	return output;
}

void BigNumber::operator += (BigNumber b) 	//加法  +=
{
	if (b.len > len) len = b.len;
	int c = 0;
	for (int i = 0; i < len; i++) 
	{
		num[i] += b.num[i] + c;
		if (num[i] >= B) 
		{
			c = 1;
			num[i] -= B;
		} else c = 0;
	}
	if (c == 1) num[len++] = 1;
};

BigNumber BigNumber::operator * (BigNumber b) //乘法  *
{
	BigNumber res;
	memset(&res, 0, sizeof res);
	res.sign = sign ^ b.sign;
	res.len = len + b.len;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < b.len; j++) 
		{
			res.num[i + j] += num[i] * b.num[j];
			res.num[i + j + 1] += res.num[i + j] / B;
			res.num[i + j] %= B;
		}
		while (res.len > 1 && res.num[res.len - 1] == 0)
			--res.len;
		if (res.len == 1 && res.num[0] == 0) res.sign = 0;
		return res;
}

//------------------------------------------减法---------------------------------------------------
int BigNumber::Cmp(const BigNumber &a, const BigNumber &b) 	//比较函数
{
	if (a.len != b.len) return a.len - b.len;
	for (int i = a.len - 1; i >= 0; i--)
		if (a.num[i] != b.num[i]) return a.num[i] - b.num[i];
		return 0;
}

BigNumber BigNumber::operator - (BigNumber b)   //减法  -
{
	BigNumber res;
	BigNumber a = *this;
	res.sign = 0;
	if(Cmp(a,b)<0)	//if (a < b) 
	{
		BigNumber tmp = a;
		a = b;
		b = tmp;
		res.sign = 1;
	}
	memset(res.num, 0, sizeof res.num);
	int c = 0;
	res.len = max(a.len, b.len);
	for (int i = 0; i < res.len; i++) 
	{
		res.num[i] = a.num[i] - b.num[i] - c;
		c = 0;
		if (res.num[i] < 0) 
		{
			c = 1;
			res.num[i] += B;
		}
	}
	while (res.len > 1 && res.num[res.len - 1] == 0)
		res.len--;
	return res;
}
//-----------------------------------------------------------------------------------------------

/*------------------------------------------除法(很少用到)---------------------------------------
struct Div_ans
{
	BigNumber big;
	int left;
};	

Div_ans div(BigNumber a, int divisor) 
{
	int remain = 0;
	for (int i = a.len - 1; i >= 0; i--) 
	{
		a.num[i] += B * remain;
		remain = a.num[i] % divisor;
		a.num[i] /= divisor;
	}
	while(a.num[a.len - 1] == 0)  a.len--;
	Div_ans ans;
	ans.big=a;
	ans.left=remain;
	return ans;
}
-----------------------------------------------------------------------------------------------*/

/*-----------------------------------下面部分基本没用--------------------------------------------
bool BigNumber::operator > (BigNumber b) 
{
	return Cmp(*this, b) > 0;
}

bool BigNumber::operator == (BigNumber b) 
{
	return Cmp(*this, b) == 0;
}

bool BigNumber::operator < (BigNumber b) 
{
	return Cmp(*this, b) < 0;
}

BigNumber BigNumber::operator + (BigNumber b) 
{
	b += *this;
	return b;
}

void BigNumber::operator *= (BigNumber b) 
{
	*this = *this * b;
};
---------------------------------------------------------------------------------------------------*/
int main(){
    int i,j,k,n,T;
    while(1){
        BigNumber A,B,C;
        cin>>A;
        cin>>B;
        cout<<A<<endl;
        cout<<B<<endl;
        A+=B;
        cout<<A<<endl;
	}
	return 0;
}
